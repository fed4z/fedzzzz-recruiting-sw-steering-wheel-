#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickView>

#include "sensor.h"
#include "data.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //Sensor inverterTemp; //
    qmlRegisterType< Sensor >("Fed", 1, 0, "Sensor");

    // Data generator
      Data *data = new Data(&app);
      Sensor rpmCounter(Data::RPM, 100000, 0);
      //Sensor *currentSpeed = new Sensor(Data::SPEED, 200, 0);
      Sensor currentSpeed(Data::SPEED, 200, 0);
      Sensor valuePower(Data::POWER_LIMITER, 100, 0);
      Sensor temp_HV(Data::BMS_HV_TEMP, 40, 20);
      Sensor temp_LV(Data::BMS_LV_TEMP, 50, 20);
      Sensor temp_INVERT(Data::INVERTER_TEMP, 70, 20);
      Sensor temp_MOTOR(Data::MOTOR_TEMP, 80, 20);
      Sensor volt_HV(Data::BMS_HV_VOLTAGE, 460, 350); //remaining battery charge
      Sensor volt_LV(Data::BMS_LV_VOLTAGE, 18, 12);
      Sensor current(Data::BMS_LV_CURRENT, 30, 0);



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
      /*QObject::connect(data, &Data::dataReceived, &rpmCounter, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, currentSpeed, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, &rpmCounter, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, currentSpeed, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, &rpmCounter, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, currentSpeed, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, &rpmCounter, &Sensor::getData);
      QObject::connect(data, &Data::dataReceived, currentSpeed, &Sensor::getData);*/


      //currentSpeed->setValue(12);
      // QQuickView *view = new QQuickView;
      // QQmlContext *context = view->engine()->rootContext();



       //context->setContextProperty("currentSpeed", currentSpeed);



    // qDebug() << sensore.value();

    // QObject::connect(data, &Data::dataReceived, &sensore, &Sensor::getData);



   // for(int i=0; i< 2000000000; i++);

   //  qDebug ()<< sensore.value();

     //qDebug() << sensore.temp();

      // You can received data using Qt Signals and Slots.
      // https://doc.qt.io/qt-5/signalsandslots.html

      // example:
      // QObject::connect(data, &Data::dataReceived, backend, &Backend::ingestData);

    QQmlApplicationEngine engine;

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


    //si può fare con una sola funzione?




    return app.exec();
}
