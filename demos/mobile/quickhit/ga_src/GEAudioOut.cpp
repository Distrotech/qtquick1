/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/qstring.h>
#include <QAudioOutput>

#include "GEAudioOut.h"

using namespace GE;
//using namespace QTM_NAMESPACE;

/*
#ifndef Q_OS_WIN32
QTM_USE_NAMESPACE
#endif
*/

const int CHANNELS = 2;
const QString CODEC = "audio/pcm";
const QAudioFormat::Endian BYTEORDER = QAudioFormat::LittleEndian;
const QAudioFormat::SampleType SAMTYPE = QAudioFormat::SignedInt;



AudioOut::AudioOut( QObject *parent, GE::IAudioSource *source ) : QThread(parent) {         // qobject
    m_source = source;
    QAudioFormat format;
    format.setFrequency(AUDIO_FREQUENCY);
    format.setChannels(CHANNELS);
    format.setSampleSize(AUDIO_SAMPLE_BITS);
    format.setCodec(CODEC);
    format.setByteOrder(BYTEORDER);
    format.setSampleType(SAMTYPE);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format))
        format = info.nearestFormat(format);


    m_audioOutput = new QAudioOutput(info,format);

#ifdef Q_WS_MAEMO_5
    m_audioOutput->setBufferSize(20000);
    m_sendBufferSize = 5000;
#else
    m_audioOutput->setBufferSize(16000);
    m_sendBufferSize = 4000;
#endif

    m_outTarget = m_audioOutput->start();


    m_sendBuffer = new AUDIO_SAMPLE_TYPE[ m_sendBufferSize ];
    m_samplesMixed = 0;

    m_runstate=0;

#ifndef Q_OS_SYMBIAN
    start();
#else
    m_audioOutput->setNotifyInterval(5);
    connect(m_audioOutput,SIGNAL(notify()),SLOT(audioNotify()));
#endif

};


AudioOut::~AudioOut() {
    if (m_runstate==0) m_runstate = 1;
    if (QThread::isRunning() == false) m_runstate = 2;
    while (m_runstate!=2) { msleep(50); }       // wait until the thread is finished
    m_audioOutput->stop();
    delete m_audioOutput;
    delete [] m_sendBuffer;
};


void AudioOut::audioNotify() {
    tick();
};

void AudioOut::tick() {
        // fill data to buffer as much as free space is available..
    int samplesToWrite = m_audioOutput->bytesFree() / (CHANNELS*AUDIO_SAMPLE_BITS/8);
    samplesToWrite*=2;

    if (samplesToWrite > m_sendBufferSize) samplesToWrite = m_sendBufferSize;
    if (samplesToWrite<=0) return;
    int mixedSamples = m_source->pullAudio( m_sendBuffer, samplesToWrite );
    m_outTarget->write( (char*)m_sendBuffer, mixedSamples*2 );

};


void AudioOut::run() {
    if (!m_source) { m_runstate=2; return; }
    int sleepTime = m_sendBufferSize * 340 / AUDIO_FREQUENCY;
    if (sleepTime<2) sleepTime = 2;

    while (m_runstate==0) {
        tick();
        msleep(sleepTime);
    };
    m_runstate = 2;
};


