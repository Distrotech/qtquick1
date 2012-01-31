/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qtquick1plugin.h"
#include "qdeclarativeviewinspector.h"

#include <QtCore/qplugin.h>
#include <QtQuick1/private/qdeclarativeinspectorservice_p.h>
#include <QtQuick1/qdeclarativeview.h>

namespace QmlJSDebugger {
namespace QtQuick1 {

QtQuick1Plugin::QtQuick1Plugin() :
    m_inspector(0)
{
}

QtQuick1Plugin::~QtQuick1Plugin()
{
    delete m_inspector;
}

bool QtQuick1Plugin::canHandleView(QObject *view)
{
    return qobject_cast<QDeclarativeView*>(view);
}

void QtQuick1Plugin::activate()
{
    QDeclarativeInspectorService *service = QDeclarativeInspectorService::instance();
    QList<QDeclarativeView*> views = service->views();
    if (views.isEmpty())
        return;

    // TODO: Support multiple views
    QDeclarativeView *view = service->views().at(0);
    m_inspector = new QDeclarativeViewInspector(view, view);
}

void QtQuick1Plugin::deactivate()
{
    delete m_inspector;
}

void QtQuick1Plugin::clientMessage(const QByteArray &message)
{
    if (m_inspector)
        m_inspector->handleMessage(message);
}

} // namespace QtQuick1
} // namespace QmlJSDebugger

Q_EXPORT_PLUGIN2(qmldbg_qtquick1, QmlJSDebugger::QtQuick1::QtQuick1Plugin)
