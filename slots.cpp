#include "slots.h"

CommpandInput::CommpandInput(QObject *parent) : QObject(parent)
{
  connect(&builder, SIGNAL(readyReadStandardOutput()),
          this, SLOT(readDataOutput()));


  connect(&builder, SIGNAL(readyReadStandardError()),
          this, SLOT(readDataError()));

}
void CommpandInput::cppSlot(const QVariant &v)
{
  qDebug() << "Called the C++ slot with value:" << v;

  QString command = QVariant(v).toString();

  QStringList list = command.split(QRegExp("\\s+"));

  builder.setProcessChannelMode(QProcess::MergedChannels);
  QStringList params;
  // params << "www.google.com";
  // builder.start("ping", params);
  builder.waitForFinished();

  for (int i = 1 ; i<list.size(); ++i )
  {
    if (! list[i].isEmpty())
    {
      params.push_back(list[i]);
    }
  }
  qDebug() << "comand " << list[0] << endl;
  qDebug() << "params " << params << endl;
  qDebug() << "list "  << list << endl;


  builder.start(list[0].trimmed(), params);

  //builder.waitForFinished();




}

void CommpandInput::readDataError()
{
  QString output = builder.readAllStandardError();
  output = output.replace("\n", "<br>");
  qDebug() << "output:" << output << endl;

  emit messageChanged(output);

}


void CommpandInput::readDataOutput()
{
  QString output = builder.readAllStandardOutput();
  output = output.replace("\n", "<br>");
  qDebug() << "output:" << output << endl;

  emit messageChanged(output);

}
