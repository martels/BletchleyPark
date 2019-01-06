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

int main()
{
    alpha x, y, z;
    int f, g;
    x = A;
    y = B;

    f = (int) x;
    g = (int) y;

    z = (alpha) f;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x + y = " << x + y << endl;
    cout << "f = " << f << endl;
    cout << "g = " << g << endl;
    cout << "z = " << z << endl;

    return(0);
    
}
