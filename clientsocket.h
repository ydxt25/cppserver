#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <string>
using namespace std;
class ClientSocket:public boost::enable_shared_from_this<ClientSocket>
{
public:
    typedef boost::shared_ptr<ClientSocket> Ptr;
    ClientSocket(boost::asio::io_service &ios_);
    boost::shared_ptr<boost::asio::ip::tcp::socket> GetSocket(){
        return _sock;
    }
    boost::signals2::signal<void(ClientSocket::Ptr,string msg)> onRequest;

    void handle_read(boost::system::error_code ec,size_t byte_transferred);
    void handle_write(boost::system::error_code ec,size_t byte_transferred);
    void startRead();
    void write2remote(string msg);
private:
    boost::asio::io_service &_ios;
    boost::shared_ptr<boost::asio::ip::tcp::socket> _sock;
    char message[1024];
};

#endif // CLIENTSOCKET_H
