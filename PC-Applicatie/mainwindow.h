#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myudp.h"

#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QUdpSocket>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QVector>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void GUI();
     void setIP();
     void setInstance( MyUDP* );
     void printMessages( QString  );
     void sendMessage();
     MyUDP* client;
     QLineEdit *lineEdit;
     QLineEdit *lineEdit2;
     QLineEdit *lineEdit3;
private:

     QLabel *messageLabel;
     QScrollArea* scroll;
     QWidget text2;
     QLineEdit *lineMessage;
     QLineEdit *lineMessageIP;
     QVector <QString> textv;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
