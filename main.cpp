#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickView>

#include "headers/sensor.h"
#include "headers/data.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // Data generator
    Data *data = new Data(&app);

    //added sensors
    Sensor rpmCounter(Data::RPM, 100000, 0);
    Sensor currentSpeed(Data::SPEED, 200, 0);
    Sensor valuePower(Data::POWER_LIMITER, 100, 0);
    Sensor temp_HV(Data::BMS_HV_TEMP, 40, 20);
    Sensor temp_LV(Data::BMS_LV_TEMP, 50, 20);
    Sensor temp_INVERT(Data::INVERTER_TEMP, 70, 20);
    Sensor temp_MOTOR(Data::MOTOR_TEMP, 80, 20);
    Sensor volt_HV(Data::BMS_HV_VOLTAGE, 460, 350); //remaining battery charge
    Sensor volt_LV(Data::BMS_LV_VOLTAGE, 18, 12);
    Sensor current(Data::BMS_LV_CURRENT, 30, 0);


    //connecting data generator to sensors
    QObject::connect(data, &Data::dataReceived, &rpmCounter, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &currentSpeed, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &valuePower, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &temp_HV, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &temp_LV, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &temp_INVERT, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &temp_MOTOR, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &volt_HV, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &volt_LV, &Sensor::getData);
    QObject::connect(data, &Data::dataReceived, &current, &Sensor::getData);

    QQmlApplicationEngine engine;


    //connecting sensors to QML layer
    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("rpmCounter", &rpmCounter);
    rootContext->setContextProperty("currentSpeed", &currentSpeed);
    rootContext->setContextProperty("valuePower", &valuePower);
    rootContext->setContextProperty("temp_HV", &temp_HV);
    rootContext->setContextProperty("temp_LV", &temp_LV);
    rootContext->setContextProperty("temp_INVERT", &temp_INVERT);
    rootContext->setContextProperty("temp_MOTOR", &temp_MOTOR);
    rootContext->setContextProperty("volt_HV", &volt_HV);
    rootContext->setContextProperty("volt_LV", &volt_LV);
    rootContext->setContextProperty("current", &current);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);





    return app.exec();
}
