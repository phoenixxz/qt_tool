#include"threadnetrecv.h"
#include <QUdpSocket>
#include<iostream>
ThreadNetRecv::ThreadNetRecv()
{
    udpSocket = new QUdpSocket;
    udpSocket -> bind(QHostAddress::LocalHost,9000);
    ///connect(sendButton,SIGNAL(clicked()),this,SLOT(send_slot()));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}
void ThreadNetRecv::run()
{
    std::cout<<"this is thread\n" ;

}
void ThreadNetRecv::recvSlot()
{
    qDebug()<<"in recv_slot()";
    udpSocker -> readDatagram(buffer,4096,0,0);
    cout<<buffer;
}
