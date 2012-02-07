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

#include <QTimer>

#include "guitartunerui.h"
#include "ui_guitartunerui.h"

GuitarTunerUI::GuitarTunerUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GuitarTunerUI),
    m_maximumPrecision(0)
{
    ui->setupUi(this);

    // Set up the class attributes to proper values.
    m_outputActive = false;
    m_muted = false;
    m_outputVolumeLevel = getVolumeFromSoundSlider();
    m_inputVolumeLevel = 1.0 - m_outputVolumeLevel;

    // Set up the current tone, the frequency, and the name for it.
    m_currentToneIndex = 5;
    updateFrequencyByToneIndex(m_currentToneIndex);

    // Connect the signals from UI into proper slots.
    connect(ui->soundSlider, SIGNAL(valueChanged(int)),
            SLOT(changeVolume()));
    connect(ui->soundButton, SIGNAL(toggled(bool)),
            SLOT(toggleSound(bool)));
    connect(ui->modeButton, SIGNAL(clicked()),
            SLOT(toggleInputOrOutput()));
    connect(ui->buttonNext, SIGNAL(clicked()), SLOT(next()));
    connect(ui->buttonPrev, SIGNAL(clicked()), SLOT(prev()));

    // Initialise up the UI by calling toggleInputOrOutput
    // for the first time.
    toggleInputOrOutput();
}

GuitarTunerUI::~GuitarTunerUI()
{
    delete ui;
}

void GuitarTunerUI::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
  * Returns a value from 0 to 1, representing the volume.
  */
qreal GuitarTunerUI::getVolumeFromSoundSlider() const
{
    qreal value = ui->soundSlider->value();
    return value/ui->soundSlider->maximum();
}

/**
  * Updates the m_currentToneFrequency and m_currentToneString,
  * according to the given index. Also updates the UI.
  */
void GuitarTunerUI::updateFrequencyByToneIndex(int index)
{

    switch (index) {
    case 0: {
            m_currentToneFrequency = FrequencyE;
            m_currentToneString = "E";
            break;
        }
    case 1: {
            m_currentToneFrequency = FrequencyA;
            m_currentToneString = "A";
            break;
        }
    case 2: {
            m_currentToneFrequency = FrequencyD;
            m_currentToneString = "D";
            break;
        }
    case 3: {
            m_currentToneFrequency = FrequencyG;
            m_currentToneString = "G";
            break;
        }
    case 4: {
            m_currentToneFrequency = FrequencyB;
            m_currentToneString = "B";
            break;
        }
    case 5: {
            m_currentToneFrequency = FrequencyE2;
            m_currentToneString = "e";
            break;
        }
    default: {
            qDebug() << "invalid index!" << index;
        }
    }
    // Set the noteLabel text according to the current tone.
    ui->noteLabel->setText(m_currentToneString);
}

/**
  * Returns the volume.
  */
qreal GuitarTunerUI::getVolume() const
{
    return m_outputVolumeLevel;
}

/**
  * Returns true if the sound is muted.
  */
bool GuitarTunerUI::getMuteState() const
{
    return m_muted;
}


/**
  * Returns the microphone sensitivity.
  */
qreal GuitarTunerUI::getMicrophoneSensitivity() const
{
    return m_inputVolumeLevel;
}

/**
  * Returns whether the input mode is active.
  */
bool GuitarTunerUI::isInputModeActive() const
{
    return !m_outputActive;
}

/**
  * Returns the current target frequency.
  */
qreal GuitarTunerUI::getFrequency() const
{
    return m_currentToneFrequency;
}

/**
  * Toggles the sound according to the parameter.
  * Has no effect if output is not active.
  */
void GuitarTunerUI::toggleSound(bool noSound)
{
    if (!m_outputActive) {
        return;
    }
    m_muted = noSound;
    emit muteChanged(m_muted);
}

/**
  * Changes the volume or microphone sensitivity.
  */
void GuitarTunerUI::changeVolume()
{
    qreal resultingAmplitude = getVolumeFromSoundSlider();
    qDebug() << "resultingAmplitude" << resultingAmplitude;
    if (m_outputActive) {
        m_outputVolumeLevel = resultingAmplitude;
        emit volumeChanged(resultingAmplitude);
    }
    else {
        m_inputVolumeLevel = resultingAmplitude;
        emit microphoneSensitivityChanged(1.0-resultingAmplitude);
    }
}

/**
  * Toggles input or output, depending of the current state.
  */
void GuitarTunerUI::toggleInputOrOutput()
{
    // If output mode is active:
    if (m_outputActive) {
        // Change UI to correspond to the input mode.
        m_outputActive = false;
        ui->soundSlider->setValue(m_inputVolumeLevel*100);
        ui->soundButton->setDisabled(true);
        ui->soundButton->hide();
        ui->micSensitivityLabel->show();
        emit modeChanged(true);
        ui->modeButton->setText("To tone mode");
    }
    // Else:
    else {
        // Change UI to correspond to the output mode.
        m_outputActive = true;
        ui->soundSlider->setValue(m_outputVolumeLevel*100);
        ui->soundButton->setDisabled(false);
        ui->micSensitivityLabel->hide();
        ui->soundButton->show();
        emit modeChanged(false);
        ui->modeButton->setText("To listen mode");
    }
}

/**
  * Receives the low voice signal.
  */
void GuitarTunerUI::lowVoice()
{
    if (ui->noteLabel->font().bold()) {
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        ui->noteLabel->setFont(font);
    }
}

/**
  * Receives the voice difference signal.
  * The difference is qreal, where increase of 1 corresponds
  * to increase of 1 tone to the target frequency.
  */
void GuitarTunerUI::voiceDifference(qreal difference)
{
    if (ui->noteLabel->font().bold()) {
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        ui->noteLabel->setFont(font);
    }
    ui->correctSoundSlider->setValue(difference*m_maximumPrecision);
}

/**
  * Receives the correct frequency signal.
  * Makes the UI to visualize correct frequency event.
  */
void GuitarTunerUI::correctFrequencyObtained()
{
    qDebug() << "CORRECT FREQUENCY";
    QFont font;
    font.setBold(true);
    font.setUnderline(true);
    ui->noteLabel->setFont(font);
}

/**
  * Sets up the maximum voice difference.
  */
void GuitarTunerUI::setMaximumVoiceDifference(int max)
{
    // Assert that the maximum precision is known.
    Q_ASSERT(m_maximumPrecision != 0);
    // Set the maximum and minimum values of the correctSoundSlider
    // to the +- max*m_maximumPrecision, and set the tick interval
    // to be m_maximumPrecision.
    ui->correctSoundSlider->setMaximum(max*m_maximumPrecision);
    ui->correctSoundSlider->setMinimum(-max*m_maximumPrecision);
    ui->correctSoundSlider->setTickInterval(max*m_maximumPrecision);
}

/**
  * Stores the maximum precision per note. Used to setup the
  * correct sound slider.
  */
void GuitarTunerUI::setMaximumPrecisionPerNote(int max)
{
    m_maximumPrecision = max;
}

/**
  * Changes the tone to the next value.
  */
void GuitarTunerUI::next()
{
    changeTone((m_currentToneIndex + 1) % 6);
}

/**
  * Changes the tone to the previous value.
  */
void GuitarTunerUI::prev()
{
    changeTone((m_currentToneIndex + 5) % 6);
}

/**
  * Changes the tone according to the new index.
  */
void GuitarTunerUI::changeTone(int newIndex)
{
    m_currentToneIndex = newIndex;
    updateFrequencyByToneIndex(m_currentToneIndex);
    qDebug() << "targetFrequencyChanged" << m_currentToneFrequency;
    emit targetFrequencyChanged(m_currentToneFrequency);
}
