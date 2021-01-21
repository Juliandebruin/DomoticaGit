#include "mainwindow.h"

#include <QApplication>
#include "myudp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     MyUDP client;
     MainWindow w;

     client.setInstance(&w);
     w.setInstance( &client);


     w.resize(400,200);
     w.GUI();
     w.show();
     client.sendUDP("test 1");
     client.sendUDP("test 2");


     return a.exec();

}
