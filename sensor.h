#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include "data.h"

class Sensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float value READ value WRITE setValue NOTIFY valueChanged);
    Q_PROPERTY(bool error READ error NOTIFY errorChanged)

public:
    //explicit Sensor(QObject *parent = nullptr);
    explicit Sensor(Data::Sensor type = Data::SPEED, float max_value = 10 , float min_value = 0 );
    void checkBound();
    bool error();
    float value();

signals:
    void valueChanged();
    void errorChanged();

public slots:
    void setValue( float );
    void getData(Data::Sensor sensor, float data);

private:
    Data::Sensor sensorType;
    float m_value;
    bool m_error;
    float max_val;
    float min_val;


};

#endif // SENSOR_H
