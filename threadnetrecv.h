#include<QThread>
#include<QObject>
#include<QtCore>
#include<QtNetWork>
#include<QUdpSocket>
#include<QHostAddress>
#include<QSocketNotifier>
class ThreadNetRecv:public QThread
{
    public:
	ThreadNetRecv();
	void run();
    public slots:
	void recvSlot();
    private:
	QUdpSocket *udpSocket;
	char buffer[4096];
};
