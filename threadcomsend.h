#include<iostream>
#include<QThread>
#include<fcntl.h>

class ThreadTtySend:public QThread
{
    Q_OBJECT
    public:
	ThreadTtySend();
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
    private:
	int ttyfd;
};
