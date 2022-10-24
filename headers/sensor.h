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

    //signal to notify that value has changed
    void valueChanged();

    //signal to notify that the error state has changed
    void errorChanged();

public slots:
    void setValue( float );

    //function to retrieve data and signal the change to QML component
    void getData(Data::Sensor sensor, float data);

private:
    Data::Sensor sensorType;
    float m_value; //this variable stores the value to be displayed on the screen
    bool m_error; //this variable indicates the state of the sensor, if the last sensed value was out of declared bounds or not
    float max_val;
    float min_val;


};

#endif // SENSOR_H
