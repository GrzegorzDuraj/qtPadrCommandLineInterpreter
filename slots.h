#ifndef SLOTS_H
#define SLOTS_H

#include <QObject>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>
#include <QProcess>


class CommpandInput : public QObject
{
  Q_OBJECT
public:
  explicit CommpandInput(QObject *parent = nullptr);


  QProcess builder;

signals:
  void messageChanged(QString outputCommand);

public slots:

  void cppSlot(const QVariant &v);

  void readDataOutput();
  void readDataError();


};



#endif // SLOTS_H
