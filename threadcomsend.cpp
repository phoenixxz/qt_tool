#include<threadcomsend.h>
#include<QtCore>

ThreadTtySend::ThreadTtySend(QLineEdit *le)
{
    tle=le;
    ttyfd=open("/dev/ttyS0",O_RDWR);
    if(ttyfd<0)
    {
	std::cout<<"+++++++++++++++++d\n";

    }
    std::cout<<"Hello,World\n";
}
ThreadTtySend::~ThreadTtySend()
{
    std::cout<<"bye,World\n";
}
void ThreadTtySend::ttySend()//slot
{
    std::cout<<"this is slot";
    start();
}
void ThreadTtySend::run()
{
    int i;
    static const QChar data_1[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xcf,0x91,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_2[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xa4,0x25,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };//0xefec
    static const QChar data_3[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x4a,0x6f,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_4[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x77,0x3c,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_5[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xa1,0x87,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_6[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x30,0x48,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_7[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xf7,0x87,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_8[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xe7,0xd1,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_9[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xc6,0xea,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_10[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x01,0xdb,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_11[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x58,0xf8,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_12[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x61,0x0f,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_13[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0x4e,0x28,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    static const QChar data_14[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xe0,0x92,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    QString str_1(data_1, 25);
    QString str_2(data_2, 25);
    QString str_3(data_3, 25);
    QString str_4(data_4, 25);
    QString str_5(data_5, 25);
    QString str_6(data_6, 25);
    QString str_7(data_7, 25);
    QString str_8(data_8, 25);
    QString str_9(data_9, 25);
    QString str_10(data_10, 25);
    QString str_11(data_11, 25);
    QString str_12(data_12, 25);
    QString str_13(data_13, 25);
    QString str_14(data_14, 25);
    //int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300};
    //int name_arr[] = {115200, 38400, 19200, 9600, 4800, 2400, 1200, 300};
    setSpeed(ttyfd,115200);

    QVariant numttysend;
    numttysend=QVariant(0);
    numttysend=numttysend.toInt()+1;
    while(1)
    {
	for (i = 0; i < str_1.size(); ++i)
	{
	    write(ttyfd,&str_1.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_2.size(); ++i)
	{
	    write(ttyfd,&str_2.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_3.size(); ++i)
	{
	    write(ttyfd,&str_3.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_4.size(); ++i)
	{
	    write(ttyfd,&str_4.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_5.size(); ++i)
	{
	    write(ttyfd,&str_5.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_6.size(); ++i)
	{
	    write(ttyfd,&str_6.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_7.size(); ++i)
	{
	    write(ttyfd,&str_7.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_8.size(); ++i)
	{
	    write(ttyfd,&str_8.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_9.size(); ++i)
	{
	    write(ttyfd,&str_9.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_10.size(); ++i)
	{
	    write(ttyfd,&str_10.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_11.size(); ++i)
	{
	    write(ttyfd,&str_11.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_12.size(); ++i)
	{
	    write(ttyfd,&str_12.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_13.size(); ++i)
	{
	    write(ttyfd,&str_13.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);
	for (i = 0; i < str_14.size(); ++i)
	{
	    write(ttyfd,&str_14.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	sleep(1);

//	numttysend = numttysend.toInt()+1;
//	tle->setText(numttysend.toString());
	
	//usleep(30000);
	sleep(3);
    }
    std::cout<<"this is slot";
}
//void setSpeed(int fd, int speed)
void ThreadTtySend::setSpeed(int fd, int speed)
{
    int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300};
    int name_arr[] = {115200, 38400, 19200, 9600, 4800, 2400, 1200, 300};
    unsigned int   i;
    int   status;
    struct termios Opt;
    tcgetattr(fd, &Opt);
    for ( i= 0; i < sizeof(speed_arr) / sizeof(int); i++) 
    {
	if (speed == name_arr[i]) 
	{    
	    tcflush(fd, TCIOFLUSH);    
	    cfsetispeed(&Opt, speed_arr[i]);
	    cfsetospeed(&Opt, speed_arr[i]);  
	    status = tcsetattr(fd, TCSANOW, &Opt);
	    if (status != 0) 
	    {   
	//	perror("tcsetattr fd1");
		return;    
	    }   
	    tcflush(fd,TCIOFLUSH);  
	}
    }
}

