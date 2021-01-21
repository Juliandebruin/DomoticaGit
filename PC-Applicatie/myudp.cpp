#include "myudp.h"

#include "myudp.h"

#include <QToolButton>
#include "mainwindow.h"
#include "myudp.h"

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{
    // create a QUDP socket
    socket = new QUdpSocket(this);

    // The most common way to use QUdpSocket class is
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address,
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    socket->bind( 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::sendUDP(QString text)
{
    QByteArray Data;
    Data.append(text);

    // Sends the datagram datagram
    // to the host address and at port.
    // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
    //                      const QHostAddress & host, quint16 port)



    socket->writeDatagram(Data,sender,1234);
}
void MyUDP::setInstance( MainWindow* in){
    mainwindow = in;
};
void MyUDP::readyRead()
{
   // while(0==0){
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);
    if( buffer != ""){
    static int counter =1;
    QString text=  "Message "+ QString::number(counter)+" :" + buffer;
     counter +=1;
    mainwindow->printMessages( text );
    qDebug() <<"Message from: " + sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
    }
    //}
}
