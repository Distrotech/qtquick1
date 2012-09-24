/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 1.0

Image {
    id: enemy
    objectName: "enemy"
    smooth:true
    opacity: 0 // 0=hidden by default
    fillMode:Image.PreserveAspectFit
    source:"file:/"+LevelPlugin.pictureRootPath()+"enemy1.png"

    property int enemySpeed: LevelPlugin.enemySpeed()

    function pause(doPause) {
        if (doPause) {
            upToDownAnim.pause()
            rightLeftAnim.pause()
        } else {
            upToDownAnim.resume()
            rightLeftAnim.resume()
        }
    }

    function startMovingAnim() {
        upToDownAnim.restart()
        rightLeftAnim.restart()
    }

    // Right-left animation
    SequentialAnimation {
    id: rightLeftAnim
    loops: Animation.Infinite
    NumberAnimation { target:enemy; property:"x";
    to:gameArea.width - enemy.width; easing.type: Easing.OutQuad; duration: 3000 }
    NumberAnimation { target:enemy; property:"x"; to:0; easing.type: Easing.OutQuad; duration: 3000 }
    }

    // Up to down animation
    SequentialAnimation {
    id: upToDownAnim
    PropertyAnimation { target:enemy; property:"y"; to: gameArea.height;
        easing.type: Easing.Linear; duration: enemy.enemySpeed }
    PropertyAction { target: enemy; properties: "opacity"; value: 0 }
    }
}
