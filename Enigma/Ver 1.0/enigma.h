#ifndef ENIGMA_H
#define ENIGMA_H
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// recv return 1, send return 0

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

const int ALPHABET_NUM = 26;

const alpha alphabet[ALPHABET_NUM] = {A, B, C, D, E, F, G, H, I, J, K, L, M,
                                      N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
const alpha rotor1[ALPHABET_NUM] = {E, K, M, F, L, G, D, Q, V, Z, N, T, O,
                                    W, Y, H, X, U, S, P, A, I, B, R, C, J};
const alpha rotor2[ALPHABET_NUM] = {A, J, D, K, S, I, R, U, X, B, L, H, W,
                                    T, M, C, Q, G, Z, N, P, Y, F, V, O, E};
const alpha rotor3[ALPHABET_NUM] = {B, D, F, H, J, L, C, P, R, T, X, V, Z,
                                    N, Y, E, I, W, G, A, K, M, U, S, Q, O};
const alpha rotor4[ALPHABET_NUM] = {E, S, O, V, P, Z, J, A, Y, Q, U, I, R,
                                    H, X, L, N, F, T, G, K, D, C, M, W, B};
const alpha rotor5[ALPHABET_NUM] = {V, Z, B, R, G, I, T, Y, U, P, S, D, N,
                                    H, L, X, A, W, M, J, Q, O, F, E, C, K};
const alpha rotor6[ALPHABET_NUM] = {J, P, G, V, O, U, M, F, Y, Q, B, E, N,
                                    H, Z, R, D, K, A, S, X, L, I, C, T, W};
const alpha rotor7[ALPHABET_NUM] = {N, Z, J, H, G, R, C, X, M, Y, S, W, B,
                                    O, U, F, A, I, V, L, P, E, K, Q, D, T};
const alpha rotor8[ALPHABET_NUM] = {F, K, Q, H, T, L, X, O, C, B, J, S, P,
                                    D, Z, R, A, M, E, W, N, I, U, Y, G, V};
const alpha reflector1[ALPHABET_NUM] = {Y, R, U, H, Q, S, L, D, P, X, N, G, O,
                                        K, M, I, E, B, F, Z, C, W, V, J, A, T};
const alpha reflector2[ALPHABET_NUM] = {F, V, P, J, I, A, O, Y, E, D, R, Z, X,
                                        W, G, C, T, K, U, Q, S, B, N, M, H, L};

class reflector
{
private:
  alpha table[ALPHABET_NUM][2];

public:
  reflector();
  reflector(int);
  alpha send(int);
  alpha recv(int);
};

class wheel
{
private:
  alpha status, queue;
  alpha table[ALPHABET_NUM][2];

public:
  wheel();
  //wheel(alpha t[ALPHABET_NUM], alpha q, alpha s);
  wheel(int i);
  void set(alpha);
  bool rotate();
  alpha getStat()
  {
    return status;
  };
  alpha send(alpha);
  alpha recv(alpha);
};

class plugboard
{
private:
  alpha table[ALPHABET_NUM][2];

public:
  plugboard();
  plugboard(int plugs[ALPHABET_NUM]);
  plugboard(alpha plugs[ALPHABET_NUM]);
  alpha send(alpha);
  alpha recv(alpha);
};

class enigma
{
private:
  reflector ref;
  wheel a, b, c;

public:
  enigma();
  //enigma(ifstream &fin);
  void rotate();
  void set(alpha, alpha, alpha);
  void set(int, int, int);
  alpha send(alpha);
  alpha recv(alpha);
};

#endif