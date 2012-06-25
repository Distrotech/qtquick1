/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
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

#include <qdeclarative.h>
#include <qdeclarativeextensionplugin.h>

#include "qdeclarativewebview_p.h"

QT_BEGIN_NAMESPACE

class WebKitQmlPlugin : public QDeclarativeExtensionPlugin
{
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDeclarativeExtensionInterface" FILE "plugin.json")
    Q_OBJECT
public:
    virtual void registerTypes(const char* uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QtWebKit"));
        qmlRegisterType<QDeclarativeWebSettings>();
        qmlRegisterType<QDeclarativeWebView>(uri, 1, 0, "WebView");
        qmlRegisterType<QDeclarativeWebView>(uri, 1, 1, "WebView");
        qmlRegisterRevision<QDeclarativeWebView, 0>("QtWebKit", 1, 0);
        qmlRegisterRevision<QDeclarativeWebView, 1>("QtWebKit", 1, 1);
    }
};

QT_END_NAMESPACE

#include "plugin.moc"
