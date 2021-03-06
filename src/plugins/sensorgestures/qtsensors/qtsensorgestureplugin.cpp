/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSensors module of the Qt Toolkit.
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

#include <QtPlugin>
#include <QStringList>
#include <QObject>

#include "qtsensorgestureplugin.h"

#include <qsensorgestureplugininterface.h>

#include "qcoversensorgesturerecognizer.h"
#include "qtwistsensorgesturerecognizer.h"
#include "qdoubletapsensorgesturerecognizer.h"
#include "qhoversensorgesturerecognizer.h"
#include "qpickupsensorgesturerecognizer.h"
#include "qshake2recognizer.h"
#include "qslamgesturerecognizer.h"
#include "qturnoversensorgesturerecognizer.h"
#include "qwhipsensorgesturerecognizer.h"


QT_BEGIN_NAMESPACE


QtSensorGesturePlugin::QtSensorGesturePlugin()
{
}

QtSensorGesturePlugin::~QtSensorGesturePlugin()
{
}

QStringList QtSensorGesturePlugin::supportedIds() const
{
    QStringList list;
    list << "QtSensors.cover";
    list << "QtSensors.doubletap";
    list << "QtSensors.hover";
    list << "QtSensors.pickup";
    list << "QtSensors.shake2";
    list << "QtSensors.slam";
    list << "QtSensors.turnover";
    list << "QtSensors.twist";
    list << "QtSensors.whip";
    return list;
}

QList <QSensorGestureRecognizer *> QtSensorGesturePlugin::createRecognizers()
{
    QList <QSensorGestureRecognizer *> recognizers;

    recognizers.append(new QCoverSensorGestureRecognizer(this));

    recognizers.append(new QDoubleTapSensorGestureRecognizer(this));

    recognizers.append(new QHoverSensorGestureRecognizer(this));

    recognizers.append(new QPickupSensorGestureRecognizer(this));

    recognizers.append(new QShake2SensorGestureRecognizer(this));

    recognizers.append(new QSlamSensorGestureRecognizer(this));

    recognizers.append(new QTurnoverSensorGestureRecognizer(this));

    recognizers.append(new QWhipSensorGestureRecognizer(this));

    recognizers.append(new QTwistSensorGestureRecognizer(this));

    return recognizers;
}

QT_END_NAMESPACE
