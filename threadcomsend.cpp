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
    static const QChar data[25] = { 0xaa, 0x55, 0xff, 0xff,0xff,0xff,0xcf,0x91,\
	0xff,0xff,0xff,0xff,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,\
	0xaa,0xcc };
    QString str(data, 25);
    //int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300};
    //int name_arr[] = {115200, 38400, 19200, 9600, 4800, 2400, 1200, 300};
    setSpeed(ttyfd,115200);

    QVariant numttysend;
    numttysend=QVariant(0);
    numttysend=numttysend.toInt()+1;
    while(1)
    {
	for (i = 0; i < str.size(); ++i)
	{
	    write(ttyfd,&str.at(i),1);
	}
	numttysend = numttysend.toInt()+1;
	tle->setText(numttysend.toString());
	
	//usleep(30000);
	//usleep(300000);
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
    struct termios   Opt;
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

