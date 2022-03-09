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

  //Maps channel name to the channel's input
  static map<string, PhotonicRouter*> _input_router_map; 
  //Maps channel name to the channel's output
  static map<string, PhotonicRouter*> _output_router_map;

  tRoutingFunction   _rf;

  enum inputState {
    idle,       // Not connected
    waiting,    // Waiting for full path to be established
    connected   // Full path established
  };

  enum outputState {
    free,
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

  virtual void AddInputChannel( FlitChannel *channel, CreditChannel *backchannel );
  virtual void AddOutputChannel( FlitChannel *channel, CreditChannel *backchannel );


  void Display( ostream & os = cout ) const;

  virtual int GetUsedCredit(int out) const {return 0;}
  virtual int GetBufferOccupancy(int i) const {return 0;}

#ifdef TRACK_BUFFERS
  virtual int GetUsedCreditForClass(int output, int cl) const;
  virtual int GetBufferOccupancyForClass(int input, int cl) const;
#endif
    virtual vector<int> UsedCredits() const { return vector<int>(); }
  virtual vector<int> FreeCredits() const { return vector<int>(); }
  virtual vector<int> MaxCredits() const { return vector<int>(); }
};

#endif
