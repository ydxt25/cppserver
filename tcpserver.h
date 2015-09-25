#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <boost/asio.hpp>
#include "clientsocket.h"
using namespace boost::asio;
class TcpServer
{
public:
    TcpServer(io_service &ios_,int port);
    void start();
    void handle_accept(boost::system::error_code ec,ClientSocket::Ptr sock);

private:
    ip::tcp::acceptor _acceptor;
    io_service &_ios;


};

#endif // TCPSERVER_H
