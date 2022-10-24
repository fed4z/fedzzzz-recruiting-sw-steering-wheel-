#include "headers/sensor.h"
#include "headers/data.h"
#include <QDebug>


Sensor::Sensor(Data::Sensor type, float max_value, float min_value)
  :m_error(false), m_value(0), sensorType(type), max_val(max_value), min_val(min_value)
{
}


//this functions checks if the value of the sensor is otu of the declared boundaries
//in case of out of boundaries changes error to true and signals the change
//it also turns off the error if recieved values are now in the prescribed range
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
        emit valueChanged();
    }
}



//this slot is made to recieve the "dataRecieved" signal, update ""value" with new data
//and then signals the change to the QML layer
void Sensor::getData(Data::Sensor sensor, float data){
    if(sensor == this->sensorType){
        m_value = data;
        checkBound();
        emit valueChanged();
    }
}

//to retrieve value
float Sensor::value() {
    return m_value;
}

//to retrieve error value
bool Sensor::error() {
    return m_error;
}
