/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQuick1 module of the Qt Toolkit.
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

#ifndef QDECLARATIVESTRINGCONVERTERS_P_H
#define QDECLARATIVESTRINGCONVERTERS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <private/qtdeclarativeglobal_p.h>
#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE

class QColor;
class QPointF;
class QSizeF;
class QRectF;
class QString;
class QByteArray;
class QVector3D;

// XXX - Bauhaus currently uses these methods which is why they're exported
namespace QDeclarativeStringConverters
{
    QVariant Q_DECLARATIVE_PRIVATE_EXPORT variantFromString(const QString &);
    QVariant Q_DECLARATIVE_PRIVATE_EXPORT variantFromString(const QString &, int preferredType, bool *ok = 0);

    QColor Q_DECLARATIVE_PRIVATE_EXPORT colorFromString(const QString &, bool *ok = 0);
#ifndef QT_NO_DATESTRING
    QDate Q_DECLARATIVE_PRIVATE_EXPORT dateFromString(const QString &, bool *ok = 0);
    QTime Q_DECLARATIVE_PRIVATE_EXPORT timeFromString(const QString &, bool *ok = 0);
    QDateTime Q_DECLARATIVE_PRIVATE_EXPORT dateTimeFromString(const QString &, bool *ok = 0);
#endif
    QPointF Q_DECLARATIVE_PRIVATE_EXPORT pointFFromString(const QString &, bool *ok = 0);
    QSizeF Q_DECLARATIVE_PRIVATE_EXPORT sizeFFromString(const QString &, bool *ok = 0);
    QRectF Q_DECLARATIVE_PRIVATE_EXPORT rectFFromString(const QString &, bool *ok = 0);
    QVector3D Q_DECLARATIVE_PRIVATE_EXPORT vector3DFromString(const QString &, bool *ok = 0);
}

QT_END_NAMESPACE

#endif // QDECLARATIVESTRINGCONVERTERS_P_H
