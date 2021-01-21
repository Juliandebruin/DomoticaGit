#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QDebug>
#include "myudp.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    messageLabel = new QLabel(this);
    scroll = new QScrollArea(this);
    scroll->setGeometry( 20,120,200,60 );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GUI(){
    QFont georgia("Georgia",16,QFont::Bold);

    QFont* fontSize = new QFont;
    // lineEdit->font();
    fontSize->setPointSize(10);

    QLabel *title= new QLabel(this);
    title->setText( "UDP Reciever and Transmister" );
    title->setVisible( true );
    title->setGeometry( 20,20,350,30 );
    title->setFont( georgia );

    QPushButton* ipButton = new QPushButton(this);
    ipButton->setText("Set IP");
    ipButton->setVisible(true);
    ipButton->setGeometry(QRect(QPoint(150, 60),QSize(100, 20)));
    connect(ipButton, &QPushButton::clicked, this,&MainWindow::setIP );

    lineMessageIP = new QLineEdit(this);
    lineMessageIP->setGeometry(QRect(QPoint(20, 60),QSize(100, 20)));
    lineMessageIP->setFont(*fontSize);
    lineMessageIP->setVisible(true);

    QPushButton* buttonMessage = new QPushButton(this);
    buttonMessage->setText("Send Command");
    buttonMessage->setVisible(true);
    buttonMessage->setGeometry(QRect(QPoint(150, 80),QSize(100, 20)));
    connect(buttonMessage,&QPushButton::clicked,this,&MainWindow::sendMessage );

    lineMessage = new QLineEdit(this);
    lineMessage->setGeometry(QRect(QPoint(20, 80),QSize(100, 20)));
    lineMessage->setFont(*fontSize);
    lineMessage->setVisible(true);

}
void MainWindow::printMessages( QString inputText )
{
    static int counter=0;
    QString text;
    textv += inputText;
    for(int i=0; i<= counter; i++){
         text+= (textv[i] + "<br>");
    }
    messageLabel->setText(text);
    qDebug() << "dddnmm" <<messageLabel;
    scroll->setWidgetResizable( true );

    scroll->setWidget(messageLabel);
    counter++;
}

void MainWindow::setInstance( MyUDP *client )
{
    this->client = client;
}
void MainWindow::sendMessage(){
    client->sender.setAddress(lineMessage->text());
    //qDebug() << lineMessage->text();
    client->sendUDP(lineMessage->text());
    lineMessage->clear();
}

void MainWindow::setIP(){
    client->sender.setAddress(lineMessageIP->text());
    //qDebug() << lineMessageIP->text();
    lineMessageIP->clear();

}
