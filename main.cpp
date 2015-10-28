#include <iostream>
#include <boost/asio.hpp>
#include "tcpserver.h"
using namespace std;



void work()
{

}

int main()
{

    boost::asio::io_service _ios;
    TcpServer tcpserver(_ios,1991);
    tcpserver.start();

    _ios.run();

    return 0;
}

