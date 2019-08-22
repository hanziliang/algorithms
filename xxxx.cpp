#include <boost/lockfree/queue.hpp>
#include <thread>

#define WITH_THREAD

int main()
{
#ifndef WITH_THREAD
    boost::lockfree::queue<void*, boost::lockfree::capacity<20000>> intpool;
    return 0;
#else
    std::thread([]{
        //boost::lockfree::queue<void*> intpool(20000);
        boost::lockfree::queue<void*, boost::lockfree::capacity<20000>> intpool;
    }).join();
    return 0;
#endif
}
