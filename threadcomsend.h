#include<iostream>
#include<QThread>
#include<fcntl.h>
#include <termios.h> 
#include <time.h> 
#include<QLineEdit>

class ThreadTtySend:public QThread
{
    Q_OBJECT
    public:
	ThreadTtySend(QLineEdit *le);
	~ThreadTtySend();
    public slots:
	void ttySend();
    protected:
	void run();
    public:
	int ttyOpen(int fd);
	int ttyClose(int fd);
	int ttySetAttr(int fd);
	int ttyWrite();
	void setSpeed(int fd,int speed);
    private:
	int ttyfd;
	QLineEdit *tle;
	//QVariant numttysend;
//	static int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300};
	
};
