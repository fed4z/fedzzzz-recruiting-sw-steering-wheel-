#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include "data.h"

class Sensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged);
public:
    //explicit Sensor(QObject *parent = nullptr);
    explicit Sensor(Data::Sensor type = Data::SPEED, int max_value = 10 , int min_value = 12);
    int value();

signals:
    void valueChanged();
    void outOfBound();

public slots:
    void setValue( int );
    void getData(Data::Sensor sensor, float data);

private:
    Data::Sensor sensorType;
    int m_value;
    int max_val;
    int min_val;


};

#endif // SENSOR_H
