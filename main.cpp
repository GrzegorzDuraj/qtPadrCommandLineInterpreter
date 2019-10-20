#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>
#include <QQmlContext>

#include "slots.h"


int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  CommpandInput commandInput;

  auto root_context = engine.rootContext();
  root_context->setContextProperty("commandInputClass", &commandInput );




  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);




  QObject *topLevel  = engine.rootObjects().value(0);
  QObject * myObject= topLevel->findChild<QObject*>("rectangleCommandSend");
  QObject::connect(myObject, SIGNAL(sendMessage(QVariant)),
                   &commandInput, SLOT(cppSlot(QVariant)));

  return app.exec();
}
