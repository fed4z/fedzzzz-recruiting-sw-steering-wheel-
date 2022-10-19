#include "sensor.h"
#include "data.h"
#include <QDebug>


Sensor::Sensor(Data::Sensor type, int max_value, int min_value)
  : m_value(3), sensorType(type), max_val(max_value), min_val(min_value)
{
}

void Sensor::setValue(int newValue){
    if(m_value != newValue ){
        m_value = newValue;
        qDebug() << "value changed";
        emit valueChanged();
    }
}

void Sensor::getData(Data::Sensor sensor, float data){
    if(sensor == this->sensorType){
        m_value = (int) data;
       // qDebug() << m_value;
        emit valueChanged();
    }
}

int Sensor::value() {
    return m_value;
}
