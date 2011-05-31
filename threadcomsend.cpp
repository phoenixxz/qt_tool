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
    std::cout<<"this is slot";
}

