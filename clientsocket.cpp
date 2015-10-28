#include "clientsocket.h"
#include <iostream>
#include "tcpserver.h"
ClientSocket::ClientSocket(boost::asio::io_service &ios_,TcpServer *tcpserver):
    _ios(ios_),_sock(new boost::asio::ip::tcp::socket(ios_)),_tcpserver(tcpserver)
{
}


void ClientSocket::read_handle(boost::system::error_code ec,std::size_t byte_transferred)
{
    if(!ec)
    {
        tcpserver->onMessage();
    }
    else
    {
        _sock->close();
    }
}

//void ClientSocket::write2remote(string msg)
//{
//    _sock->async_write_some(boost::asio::buffer(msg),boost::bind(&ClientSocket::write_handle,shared_from_this(),_1,_2));
//}

void ClientSocket::send(String msg)
{
    _ios.post([this,msg](){
        _sock->async_write_some(boost::asio::buffer(msg),boost::bind(&ClientSocket::write_handle,shared_from_this(),_1,_2));
    });
}

void ClientSocket::write_handle(boost::system::error_code ec,std::size_t byte_transferred)
{
    if(!ec)
    {

    }
    else
    {
        _tcpserver->onClosed(shared_from_this());
    }

}
