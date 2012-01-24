/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef QSENSORITEM_H
#define QSENSORITEM_H

#include <QtDeclarative/qdeclarative.h>
#include <QtCore/QString>
#include "propertyinfo.h"

QT_BEGIN_NAMESPACE

class QSensor;
class QSensorItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool start READ start WRITE setStart NOTIFY startChanged)
    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY(QDeclarativeListProperty<QPropertyInfo> properties READ properties NOTIFY propertiesChanged)
public:
    QSensorItem(QObject* parent = 0);
    QSensorItem(QSensor* sensor, QObject* parent = 0);
    virtual ~QSensorItem();

public slots:
    void select();
    void unSelect();
    void changePropertyValue(QPropertyInfo* property, const QString& val);

private slots:
    void sensorReadingChanged();

private:
    QString id();
    bool start();
    void setStart(bool run);
    QDeclarativeListProperty<QPropertyInfo> properties();
    QString convertValue(const QString& type, const QVariant& val);
    bool isWriteable(const QString& propertyname);
    bool ignoreProperty(const QString& propertyname);
    void updateSensorPropertyValues();

Q_SIGNALS:
    void propertiesChanged();
    void startChanged();

private:
    QSensor* _qsensor;
    QList<QPropertyInfo*> _properties;
    QList<QPropertyInfo*> _readerProperties;
    QList<QPropertyInfo*> _sensorProperties;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QSensorItem)

#endif // QSENSORITEM_H
