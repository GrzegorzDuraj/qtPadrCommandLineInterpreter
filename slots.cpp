#include "slots.h"

CommpandInput::CommpandInput(QObject *parent) : QObject(parent)
{

}
void CommpandInput::cppSlot(const QVariant &v)
{
  qDebug() << "Called the C++ slot with value:" << v;

  QString command = QVariant(v).toString();

  builder.setProcessChannelMode(QProcess::MergedChannels);
  QStringList params;
  params << "www.google.com";
  builder.start("ping", params);
 // builder.waitForFinished();

  connect(&builder, SIGNAL(readyReadStandardOutput()),
    this, SLOT(readData()));


}


void CommpandInput::readData()
{
  QString output = builder.readAllStandardOutput();
  qDebug() << output << endl;

  emit messageChanged(output);

}
