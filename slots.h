#ifndef SLOTS_H
#define SLOTS_H

#include <QObject>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>



class Slots : public QObject
{
  Q_OBJECT
public:
  explicit Slots(QObject *parent = nullptr);

signals:

public slots:
};




class MyClass22 : public QObject
{
  Q_OBJECT
public:
  MyClass22(){}
  virtual ~MyClass22(){}

public slots:
  void cppSlot(const QVariant &v)
  {
    qDebug() << "Called the C++ slot with value:" << v;

    QQuickItem *item =
        qobject_cast<QQuickItem*>(v.value<QObject*>());
    qDebug() << "Item dimensions:" << item->width()
             << item->height();
  }
};


#endif // SLOTS_H
