#include "clientsocket.h"
#include <iostream>
ClientSocket::ClientSocket(boost::asio::io_service &ios_):
    _ios(ios_),_sock(new boost::asio::ip::tcp::socket(ios_))
{
}

void ClientSocket::startRead()
{
    _sock->async_receive(boost::asio::buffer(message),boost::bind(&ClientSocket::handle_read,shared_from_this(),_1,_2));
}
void ClientSocket::handle_read(boost::system::error_code ec,std::size_t byte_transferred)
{
    if(!ec)
    {
        std::cout<<message;
        this->write2remote(message);
        memset(message,0,1024);
        this->startRead();

    }
    else
    {
        _sock->close();
    }

}

void ClientSocket::write2remote(string msg)
{
    _sock->async_write_some(boost::asio::buffer(msg),boost::bind(&ClientSocket::handle_write,shared_from_this(),_1,_2));
}
void ClientSocket::handle_write(boost::system::error_code ec,std::size_t byte_transferred)
{
    std::cout<<byte_transferred<<" bytes sended"<<endl;
}
