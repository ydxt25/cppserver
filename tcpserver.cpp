#include "tcpserver.h"
#include <iostream>
#include <boost/bind.hpp>
using namespace std;
TcpServer::TcpServer(io_service &ios_,int port):_ios(ios_),_acceptor(ios_,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),port))
{

}

void TcpServer::start()
{
    ClientSocket::Ptr sock(new ClientSocket(_ios,this));
    _acceptor.async_accept(*sock->GetSocket(),boost::bind(&TcpServer::accept_handle,this,_1,sock));
}

void TcpServer::accept_handle(boost::system::error_code ec,ClientSocket::Ptr sock)
{
    if(!ec)
    {
        onConnected(sock);
        start();
    }
    else
    {
        _acceptor.close();
    }
}


void TcpServer::onMessage(ClientSocket::Ptr sock,String msg)
{
    onDispatch(sock,msg);
}


void TcpServer::onClosed(ClientSocket::Ptr)
{

}
