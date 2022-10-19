#ifndef STATEOFSENSORS_H
#define STATEOFSENSORS_H

#include <QObject>
#include <QDebug>
#include "data.h"

class StateOfSensors : public QObject
{
    Q_OBJECT

    Sensor


public:
    explicit StateOfSensors(QObject *parent = nullptr);



signals:

};

#endif // STATEOFSENSORS_H
