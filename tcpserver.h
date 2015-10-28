#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <boost/asio.hpp>
#include "clientsocket.h"
#include <boost/signals2.hpp>

using namespace boost::asio;


class TcpServer
{
public:
    TcpServer(io_service &ios_,int port);
    void start();
    void accept_handle(boost::system::error_code ec,ClientSocket::Ptr sock);
    void onMessage(ClientSocket::Ptr sock,String msg);
    void onError();
    void onClosed(ClientSocket::Ptr);

    boost::signals2::signal<void(ClientSocket::Ptr)> onConnected;
    boost::signals2::signal<void(ClientSocket::Ptr,String)> onDispatch;

private:
    ip::tcp::acceptor _acceptor;
    io_service &_ios;


};

#endif // TCPSERVER_H
