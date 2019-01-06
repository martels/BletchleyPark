#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>

using namespace std;

typedef enum
{
  A = 0,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z
} alpha;

class wheel
{
    private:
    
    public:

};

class enigma
{
    private:
    wheel a, b, ref;

    public:
    enigma();
    alpha send(alpha msg);
    alpha recv(alpha msg);
    
};




#endif