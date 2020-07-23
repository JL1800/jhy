#include "tcpsocket.h"
#include <QDebug>
#include<QHostAddress>
TCPSocket::TCPSocket(QObject *parent) : QTcpSocket(parent)
{
    // 建立信号槽连接
     connect(this, &TCPSocket::readyRead,
             this, &TCPSocket::receivemessage);
     //
     length=0;
}

bool TCPSocket::connectToserver(QString strIP, quint16 port)
{
    bool ret =true;
    //中断当前的socket的一切连接，并且复位socket
    this->abort();
    this->connectToHost(QHostAddress(strIP),port);
    ret=this->waitForConnected();//等待30s
    return ret;
}

void TCPSocket::SendMessage(QString content)
{
    QByteArray ba = content.toUtf8();

    int nwrite = this->write(ba);
    if (-1 == nwrite)
    {
        qDebug() << "send fail!";
    }
    else
    {
        qDebug() << "send sucess:" << nwrite;
    }

}

void TCPSocket::receivemessage()
{
   if(length==0)
   {
       //开始接收
       buffer =new char[1024];//申请空间
       int nread =this->read(buffer,1024);
         length +=nread;
   }
   else
   {
       int nread=this->read(buffer+length, 1024-length);
        length += nread;
   }
   if (1024 == length)
   {
       // 数据包读取结束
       // 发送信号
       emit dealMessage(buffer);

       // 初始化，准备接收下一个数据包
       length = 0;

       if(this->bytesAvailable() > 0)
       {
           // 继续解析下一个包
           this->receivemessage();
       }
       }
}
