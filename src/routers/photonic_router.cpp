#include "photonic_router.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <limits>

PhotonicRouter::PhotonicRouter( Configuration const & config, Module *parent, 
		    string const & name, int id, int inputs, int outputs )
: Router( config, parent, name, id, inputs, outputs )
{
    return;
}
PhotonicRouter::~PhotonicRouter(){
    return;
};
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