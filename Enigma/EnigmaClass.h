#ifndef ENIGMA_CLASS
#define ENIGMA_CLASS

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

const int CHAR_NUM = 26;

class rotor
{
    private:
    alpha in[CHAR_NUM];
    alpha out[CHAR_NUM];
    int status;
    
    public:

};

class reflector
{
    private:
    alpha in[CHAR_NUM];
    alpha out[CHAR_NUM];
    
    public:

};




#endif