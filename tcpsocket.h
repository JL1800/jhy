#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TCPSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TCPSocket(QObject *parent = nullptr);

    //连接到服务器
    bool connectToserver(QString strIP,quint16 port);

    //发送数据
    void SendMessage(QString content);

public slots:
    void receivemessage();
    //接收数据

signals:

    void dealMessage(char*buffer);
private:
    int length;//
    char *buffer;
};

#endif // TCPSOCKET_H
