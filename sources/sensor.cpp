#include "headers/sensor.h"
#include "headers/data.h"
#include <QDebug>


Sensor::Sensor(Data::Sensor type, float max_value, float min_value)
  :m_error(false), m_value(0), sensorType(type), max_val(max_value), min_val(min_value)
{
}



void Sensor::checkBound(){
    if(m_value < min_val || m_value > max_val ){
       if(m_error == false ){
           m_error = true;
           emit errorChanged();
       }

    }else{
        if(m_error == true){
            m_error = false;
            emit errorChanged();
        }
    }
}

void Sensor::setValue(float newValue){
    if(m_value != newValue ){
        m_value = newValue;
       // qDebug() << "value changed";
        emit valueChanged();
    }
}



void Sensor::getData(Data::Sensor sensor, float data){
    if(sensor == this->sensorType){
        m_value = data;
        checkBound();
       // qDebug() << m_value;
        emit valueChanged();
    }
}

float Sensor::value() {
    return m_value;
}

bool Sensor::error() {
    return m_error;
}
