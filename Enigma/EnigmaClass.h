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

const char char_alphabet[CHAR_NUM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const alpha alphabet[CHAR_NUM] = {A, B, C, D, E, F, G, H, I, J, K, L, M,
                                      N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
const alpha rotor1[CHAR_NUM] = {E, K, M, F, L, G, D, Q, V, Z, N, T, O,
                                    W, Y, H, X, U, S, P, A, I, B, R, C, J};
const alpha rotor2[CHAR_NUM] = {A, J, D, K, S, I, R, U, X, B, L, H, W,
                                    T, M, C, Q, G, Z, N, P, Y, F, V, O, E};
const alpha rotor3[CHAR_NUM] = {B, D, F, H, J, L, C, P, R, T, X, V, Z,
                                    N, Y, E, I, W, G, A, K, M, U, S, Q, O};
const alpha rotor4[CHAR_NUM] = {E, S, O, V, P, Z, J, A, Y, Q, U, I, R,
                                    H, X, L, N, F, T, G, K, D, C, M, W, B};
const alpha rotor5[CHAR_NUM] = {V, Z, B, R, G, I, T, Y, U, P, S, D, N,
                                    H, L, X, A, W, M, J, Q, O, F, E, C, K};
const alpha rotor6[CHAR_NUM] = {J, P, G, V, O, U, M, F, Y, Q, B, E, N,
                                    H, Z, R, D, K, A, S, X, L, I, C, T, W};
const alpha rotor7[CHAR_NUM] = {N, Z, J, H, G, R, C, X, M, Y, S, W, B,
                                    O, U, F, A, I, V, L, P, E, K, Q, D, T};
const alpha rotor8[CHAR_NUM] = {F, K, Q, H, T, L, X, O, C, B, J, S, P,
                                    D, Z, R, A, M, E, W, N, I, U, Y, G, V};
const alpha reflector1[CHAR_NUM] = {Y, R, U, H, Q, S, L, D, P, X, N, G, O,
                                        K, M, I, E, B, F, Z, C, W, V, J, A, T};
const alpha reflector2[CHAR_NUM] = {F, V, P, J, I, A, O, Y, E, D, R, Z, X,
                                        W, G, C, T, K, U, Q, S, B, N, M, H, L};


class rotor
{
    private:
    alpha in[CHAR_NUM];
    alpha out[CHAR_NUM];
    int status;
    
    public:
    rotor();
    rotor(alpha In[CHAR_NUM], alpha OUT[CHAR_NUM], int stat);
    alpha InOut(alpha IN);
    alpha OutIn(alpha OUT);
    void SetStatus(int stat);
    void AddStatus();
};

class reflector
{
    private:
    alpha in[CHAR_NUM];
    alpha out[CHAR_NUM];
    
    public:
    reflector();
    reflector(alpha IN[CHAR_NUM], alpha o[CHAR_NUM]);
    alpha InOut(alpha IN);
    alpha OutIn(alpha OUT);
};

class enigma
{
    private:
    rotor ROTOR_A, ROTOR_B, ROTOR_C;
    reflector REFLC;

    public:


};

//-------------------------------------Rotor----------------------------------------//
rotor::rotor() : status(1)
{
    for(int i = 0; i < CHAR_NUM; i++)
    {
        in[i] = alphabet[i];
        out[i] = rotor1[i];
    }
}

rotor::rotor(alpha IN[CHAR_NUM], alpha OUT[CHAR_NUM], int stat) : status(stat)
{
    for(int i = 0; i < CHAR_NUM; i++)
    {
        in[i] = IN[i];
        out[i] = OUT[i];
    }
}

alpha rotor::InOut(alpha IN)
{
    int pos = (int) IN;
    pos = pos + status;
    pos = pos%(CHAR_NUM+1);
    alpha ind = (alpha) pos;
    return out[ind];

}

alpha rotor::OutIn(alpha OUT)
{
    int pos = (int) OUT;
    pos = pos + status;
    pos = pos%(CHAR_NUM+1);
    alpha ind = (alpha) pos;
    return in[ind];
}

void rotor::SetStatus(int stat)
{
    status = stat;
    return;
}

void rotor::AddStatus()
{
    status++;
    return;
}

//------------------------------------Reflector-------------------------------------//

reflector::reflector()
{
    for(int i = 0; i < CHAR_NUM; i++)
    {
        in[i] = alphabet[i];
        out[i] = reflector1[i];
    }
}

reflector::reflector(alpha IN[CHAR_NUM], alpha OUT[CHAR_NUM])
{
    for(int i = 0; i < CHAR_NUM; i++)
    {
        in[i] = IN[i];
        out[i] = OUT[i];
    }
}

alpha reflector::InOut(alpha IN)
{
    return out[IN];
}

alpha reflector::OutIn(alpha OUT)
{
    return in[OUT];
}

//-------------------------------------Enigma---------------------------------------//


#endif