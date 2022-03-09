#include "photonic_router.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <limits>

map<string, PhotonicRouter*> PhotonicRouter::_input_router_map;
map<string, PhotonicRouter*> PhotonicRouter::_output_router_map;

PhotonicRouter::PhotonicRouter( Configuration const & config, Module *parent, 
		    string const & name, int id, int inputs, int outputs )
: Router( config, parent, name, id, inputs, outputs )
{

    return;
}
PhotonicRouter::~PhotonicRouter(){
    return;
};

void PhotonicRouter::AddInputChannel(FlitChannel * channel, CreditChannel * backchannel) {
    auto check = this->_output_router_map.emplace(channel->Name(), this);
    assert(check.second == true);
    Router::AddInputChannel(channel, backchannel);
}

void PhotonicRouter::AddOutputChannel(FlitChannel * channel, CreditChannel * backchannel) {
    Router::AddOutputChannel(channel, backchannel);
}

void PhotonicRouter::ReadInputs( ){
    return;
}

void PhotonicRouter::WriteOutputs( ){
    return;
}

void PhotonicRouter::_InternalStep( ){
    return;
}

void PhotonicRouter::Display( ostream & os  ) const{
    return;
}