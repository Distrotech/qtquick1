/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
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

#ifndef VOICEGENERATOR_H
#define VOICEGENERATOR_H

#include <QIODevice>
#include <QByteArray>
#include <QAudioFormat>
#include <QtCore/qmath.h>
#include <QtCore/qendian.h>
#include <QDebug>

#include "constants.h"


class VoiceGenerator : public QIODevice
{
    Q_OBJECT
public:
    VoiceGenerator(const QAudioFormat &format, qreal frequency, qreal amplitude, QObject *parent = 0);
    ~VoiceGenerator();
    void setFrequency(qreal frequency);
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 maxlen);
    qint64 bytesAvailable() const;
    qreal frequency();
signals:

public slots:
    void setAmplitude(qreal amplitude);
    void start();
    void stop();

private:
    void setValue(uchar *ptr, qreal realValue);
    void refreshData();
    const QAudioFormat m_format;
    // buffer to store the data
    QByteArray m_buffer;
    // current position in buffer
    qint64 m_position;
    // max position depends on the sample rate of format and the frequency of voice
    qint64 m_max_position;
    qreal m_amplitude;
    qreal m_frequency;
};

#endif // VOICEGENERATOR_H
