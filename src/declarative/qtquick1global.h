/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtQml module of the Qt Toolkit.
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

#ifndef QTQUICK1GLOBAL_H
#define QTQUICK1GLOBAL_H

#include <QtCore/qglobal.h>

// This definition is in the process of being removed from qtbase - once it
// has been expunged, this will no longer be necssary:
#if defined(Q_QUICK1_EXPORT)
#  undef Q_QUICK1_EXPORT
#endif

#if defined(Q_OS_WIN)
#  if defined(QT_MAKEDLL) /* create a Qt DLL library */
#    if defined(QT_BUILD_QUICK1_LIB)
#      define Q_QUICK1_EXPORT Q_DECL_EXPORT
#    else
#      define Q_QUICK1_EXPORT Q_DECL_IMPORT
#    endif
#  elif defined(QT_DLL) /* use a Qt DLL library */
#    define Q_QUICK1_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(Q_QUICK1_EXPORT)
#  if defined(QT_SHARED)
#    define Q_QUICK1_EXPORT Q_DECL_EXPORT
#  else
#    define Q_QUICK1_EXPORT
#  endif
#endif

#endif // QTQUICK1GLOBAL_H
