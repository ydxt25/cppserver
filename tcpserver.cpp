#include "tcpserver.h"
#include <iostream>
#include <boost/bind.hpp>
using namespace std;
TcpServer::TcpServer(io_service &ios_,int port):_ios(ios_),_acceptor(ios_,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),port))
{

}

void TcpServer::start()
{
    ClientSocket::Ptr sock(new ClientSocket(_ios));
    _acceptor.async_accept(*sock->GetSocket(),boost::bind(&TcpServer::handle_accept,this,_1,sock));
}

void TcpServer::handle_accept(boost::system::error_code ec,ClientSocket::Ptr sock)
{
    if(!ec)
    {
        cout<<"accept"<<endl;
        sock->startRead();
        start();
    }
    else
    {
        _acceptor.close();
    }
}
