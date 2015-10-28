#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <string>
using namespace std;
class TcpServer ;
typedef boost::shared_ptr<std::string> String;

class ClientSocket:public boost::enable_shared_from_this<ClientSocket>
{
public:
    typedef boost::shared_ptr<ClientSocket> Ptr;
    ClientSocket(boost::asio::io_service &ios_,TcpServer *_tcpserver);
    boost::shared_ptr<boost::asio::ip::tcp::socket> GetSocket(){
        return _sock;
    }

    void read_handle(boost::system::error_code ec,size_t byte_transferred);
    void write_handle(boost::system::error_code ec,size_t byte_transferred);
    void send(String msg);
private:
    TcpServer *_tcpserver;
    boost::asio::io_service &_ios;
    boost::shared_ptr<boost::asio::ip::tcp::socket> _sock;
    char message[1024];
};

#endif // CLIENTSOCKET_H
