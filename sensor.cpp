#include "sensor.h"
#include "data.h"
#include <QDebug>


Sensor::Sensor(Data::Sensor type, int max_value, int min_value)
  :m_error(false), m_value(8), sensorType(type), max_val(max_value), min_val(min_value)
{
}



void Sensor::checkBound(){
    if(m_value < min_val || m_value > max_val ){
        //m_error = true;
        qDebug() << "ERROR!"<< m_value ;
        //emit outOfBound();
    }
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
        checkBound();
       // qDebug() << m_value;
        emit valueChanged();
    }
}

int Sensor::value() {
    return m_value;
}

bool Sensor::error() {
    return m_error;
}
