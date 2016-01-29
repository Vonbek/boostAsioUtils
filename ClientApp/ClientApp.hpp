#ifndef ClientApp_HEADER
#define ClientApp_HEADER

#include "Client.hpp"
#include "ProtobufSender.hpp"
#include "ProtobufReceiver.hpp"

#include "ClientAppRequest.pb.h"
#include "ClientAppResponse.pb.h"

using namespace BoostClient;
using namespace BoostProtoSender;
using namespace BoostProtoReceiver;

class ClientApp {
public:
    ClientApp(boost::asio::io_service& io, const Client::Config& cfg); 
    
    void run();

private:
    Client           _client;
    ProtobufSender   _pbs;
    ProtobufReceiver _pbr;

    ClientAppProto::Request   _statsRequest;
    ClientAppProto::Response  _statsResponse;

    void handleConnectionFailure(const std::string& reason);
    void onClientConnected(const boost::system::error_code& ec);
    void onRequestSent(const boost::system::error_code& ec);
    void onResponseReceived(const boost::system::error_code& ec);
};

#endif
