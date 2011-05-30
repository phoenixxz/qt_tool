#include<iostream>
#include<QThread>
class ThreadComSend:public QThread
{
    Q_OBJECT
    public:
//	ThreadComSend(QPushButton *botton);
	ThreadComSend();
	~ThreadComSend();
    public slots:
	void myslot();

    private:
	int fd;
	

};
