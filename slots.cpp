#include "slots.h"

CommpandInput::CommpandInput(QObject *parent) : QObject(parent)
{

}
void CommpandInput::cppSlot(const QVariant &v)
{
  qDebug() << "Called the C++ slot with value:" << v;
}
