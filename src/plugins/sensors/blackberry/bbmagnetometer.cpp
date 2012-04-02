/****************************************************************************
**
** Copyright (C) 2012 Research In Motion
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSensors module of the Qt Toolkit.
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
#include "bbmagnetometer.h"

BbMagnetometer::BbMagnetometer(QSensor *sensor)
    : BbSensorBackend<QMagnetometerReading>(devicePath(), SENSOR_TYPE_MAGNETOMETER, sensor)
{
    setDescription(QLatin1String("Magnetic flux density in Teslas (T)"));
}

QString BbMagnetometer::devicePath()
{
    return QLatin1String("/dev/sensor/mag");
}

bool BbMagnetometer::updateReadingFromEvent(const sensor_event_t &event, QMagnetometerReading *reading)
{
    // TODO: In the future, support returnGeoValues here. Right now, /dev/sensors/mag has no
    //       geomagnatic mode, but will gain it in the future.
    reading->setX(convertValue(event.motion.dsp.x));
    reading->setY(convertValue(event.motion.dsp.y));
    reading->setZ(convertValue(event.motion.dsp.z));

    const bool returnGeoValues = sensor()->property("returnGeoValues").toBool();
    if (returnGeoValues) {
        switch (event.accuracy) {
        case SENSOR_ACCURACY_UNRELIABLE: reading->setCalibrationLevel(0.0f); break;
        case SENSOR_ACCURACY_LOW:        reading->setCalibrationLevel(0.1f); break;

        // We determined that MEDIUM should map to 1.0, because existing code samples
        // show users should pop a calibration screen when seeing < 1.0. The MEDIUM accuracy
        // is actually good enough not to require calibration, so we don't want to make it seem
        // like it is required artificially.
        case SENSOR_ACCURACY_MEDIUM:     reading->setCalibrationLevel(1.0f); break;
        case SENSOR_ACCURACY_HIGH:       reading->setCalibrationLevel(1.0f); break;
        }
    } else {
        reading->setCalibrationLevel(1.0f);
    }

    return true;
}

qreal BbMagnetometer::convertValue(float bbValueInMicroTesla)
{
    // Convert from microtesla to tesla
    return bbValueInMicroTesla * 1.0e-6;
}