#ifndef SLOTS_H
#define SLOTS_H

#include <QObject>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>


class CommpandInput : public QObject
{
  Q_OBJECT
public:
  explicit CommpandInput(QObject *parent = nullptr);

signals:

public slots:

  void cppSlot(const QVariant &v);

};



#endif // SLOTS_H
