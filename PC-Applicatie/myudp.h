// myudp.h

#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
class MainWindow;

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = 0);
    void sendUDP(QString);
    QHostAddress sender;
    QUdpSocket* socket;
    void setInstance( MainWindow* in);
    MainWindow* mainwindow;
signals:

public slots:
    void readyRead();
private:


};

#endif // MYUDP_H
