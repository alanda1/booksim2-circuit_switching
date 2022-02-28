#ifndef _PHOTONIC_ROUTER_HPP_
#define _PHOTONIC_ROUTER_HPP_

#include <string>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include "router.hpp"
#include "routefunc.hpp"

using namespace std;

class Flit;
//We might be able to use an allocator when connecting inputs to outputs?
class Allocator;

class PhotonicRouter : public Router{
  tRoutingFunction   _rf;

  enum inputState {
    idle,       // Not connected
    waiting,    // Waiting for full path to be established
    connected   // Full path established
  };

  enum outputState {
    idle,
    busy
  };

  vector<int> _input_map; //Current mapping from inputs to outputs

  vector<inputState> _input_state; //Status of input channels
  vector<outputState> _output_state; //Status of output channels

  virtual void _InternalStep( );

  public:

  PhotonicRouter( Configuration const & config,
	    Module *parent, string const & name, int id,
	    int inputs, int outputs );
  
  virtual ~PhotonicRouter( );

  virtual void ReadInputs( );
  virtual void WriteOutputs( );
  
  void Display( ostream & os = cout ) const;

  virtual int GetUsedCredit(int out) const {return 0;}
  virtual int GetBufferOccupancy(int i) const {return 0;}

#ifdef TRACK_BUFFERS
  virtual int GetUsedCreditForClass(int output, int cl) const;
  virtual int GetBufferOccupancyForClass(int input, int cl) const;
#endif

};

#endif
