#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>

#include "slots.h"


int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);


  QQuickView view(QUrl::fromLocalFile("MyItem.qml"));

  QObject *item = view.rootObject();


  MyClass22 myClass;
  QObject::connect(item, SIGNAL(sendMessage(QVariant)),
                   &myClass, SLOT(cppSlot(QVariant)));




  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
