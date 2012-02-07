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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuick1>
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QAudioInput>
#include "voicegenerator.h"
#include "voiceanalyzer.h"

const int DataFrequencyHzOutput = 44100;
const int DataFrequencyHzInput = 48000;

#define MAX_INPUT_VALUE 50
#define MIN_INPUT_VALUE -50

class GuitarTuner : public QMainWindow
{
    Q_OBJECT
public:
    enum Orientation {
        LockPortrait,
        LockLandscape,
        Auto
    };
    explicit GuitarTuner(QWidget *parent = 0);
    qreal getVolume();
    qreal getMicrophoneSensitivity();
    bool getMuteState();
    void setOrientation(Orientation orientation);

signals:

public slots:
    void modeChanged(bool isInput);
    void muteStateChanged(bool isMuted);
    void targetFrequencyChanged(qreal targetFrequency);
    void outputStateChanged(QAudio::State state);
    void setMaxVolumeLevel(qreal);

private:
    void initAudioOutput();
    void initAudioInput();
    VoiceGenerator *m_voicegenerator;
    VoiceAnalyzer *m_analyzer;
    QObject *qmlObject;
    QAudioOutput *m_audioOutput;
    QAudioInput *m_audioInput;
    QAudioFormat m_format_output;
    QAudioFormat m_format_input;
    QDeclarativeView *m_guitarTunerUI;
};

#endif // MAINWINDOW_H
