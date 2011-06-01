#include<threadcomsend.h>
ThreadTtySend::ThreadTtySend()
{
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
    static const QChar data[4] = { 0x0055, 0x006e, 0x10e3, 0x03a3 };
    QString str(data, 4);
    //int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300};
    //int name_arr[] = {115200, 38400, 19200, 9600, 4800, 2400, 1200, 300};
    setSpeed(ttyfd,115200);
    for (i = 0; i < str.size(); ++i)
    {
	write(ttyfd,&str.at(i),1);
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

