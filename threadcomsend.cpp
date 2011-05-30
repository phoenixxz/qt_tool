#include<threadcomsend.h>
ThreadComSend::ThreadComSend()
{
    std::cout<<"Hello,World\n";
}
ThreadComSend::~ThreadComSend()
{
    std::cout<<"bye,World\n";
}
void ThreadComSend::myslot()
{
    std::cout<<"this is slot";
}
