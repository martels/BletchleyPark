#if (1)
#include "enigma.h"

using namespace std;

//--------------------------Reflector---------------------------------//

reflector::reflector()
{
    for(int i = 0; i < ALPHABET_NUM; i++)
    {
        table[i][0] = alphabet[i];
        table[i][1] = alphabet[i];
    }
}

reflector::reflector(int i)
{
    if(i == 1)
    {
        for(int i = 0; i < ALPHABET_NUM; i++)
        {
            table[i][0] = alphabet[i];
            table[i][1] = reflector1[i];
        }
    }
    
    else if(i == 2)
    {
        for(int i = 0; i < ALPHABET_NUM; i++)
        {
            table[i][0] = alphabet[i];
            table[i][1] = reflector2[i];
        }
    }

    else
    {
        for(int i = 0; i < ALPHABET_NUM; i++)
        {
            table[i][0] = alphabet[i];
            table[i][1] = alphabet[i];
        }
    }
}

alpha reflector::send(int i)
{
    return table[i][1];
}

alpha reflector::recv(int i)
{
    return table[i][0];
}

//---------------------------Wheel------------------------------------//

wheel::wheel() : status(A), queue(Z)
{
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
      table[j][i];
    }
}

wheel::wheel(int i)
{
  if (i == 1)
  {
    queue = Q;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor1[j];
    }
  }

  else if (i == 2)
  {
    queue = E;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor2[j];
    }
  }

  else if (i == 3)
  {
    queue = V;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor3[j];
    }
  }

  else if (i == 4)
  {
    queue = J;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor4[j];
    }
  }

  else if (i == 5)
  {
    queue = Z;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor5[j];
    }
  }

  else if (i == 6)
  {
    queue = Z;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor6[j];
    }
  }

  else if (i == 7)
  {
    queue = Z;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor7[j];
    }
  }

  else if (i == 8)
  {
    queue = Z;
    status = A;
    for (int j = 0; j < ALPHABET_NUM; j++)
    {
        table[0][j] = alphabet[j];
        table[1][j] = rotor8[j];
    }
  }

  else
  {
      queue = Z;
      status = A;
      for(int i = 0; i < 2; i++)
        for(int j = 0; j < ALPHABET_NUM; j++)
        {
            table[i][j] = A;
        }
  }
}

// wheel::wheel(alpha t[ALPHABET_NUM], alpha q, alpha s)
// {
//     queue = q;
//     status = s;
//     for (int j = 0; j < ALPHABET_NUM; j++)
//     {
//         table[0][j] = alphabet[j];
//         table[1][j] = rotor1[j];
//     }
// }

void wheel::set(alpha n) 
{
    status = n;
    return;
}

alpha wheel::send(alpha temp)
{
    int t = (int) temp;
    int s = (int) status;
    int i = t + s;
    i = i%ALPHABET_NUM;
    return table[i][0];
}

alpha wheel::recv(alpha temp)
{
    int t = (int) temp;
    int s = (int) status;
    int i = s - t;
    i = i%ALPHABET_NUM;
    return table[i][1];
}

bool wheel::rotate() 
{
    int temp = (int) status;
    temp++;
    temp = temp%ALPHABET_NUM;
    status = (alpha) temp;
    if (status == queue)
    {
        return true;
    }

    return false;
    
}

//---------------------------Plugboard--------------------------------//

plugboard::plugboard() 
{
    for(int i = 0; i < ALPHABET_NUM; i++)
    {
        table[i][0] = alphabet[i];
        table[i][1] = alphabet[i];
    }
}

plugboard::plugboard(int plugs[ALPHABET_NUM]) 
{
    for(int i = 0; i < ALPHABET_NUM; i++)
    {
        table[i][0] = alphabet[i];
        table[i][1] = (alpha) plugs[i];
    }
}

plugboard::plugboard(alpha plugs[ALPHABET_NUM])
{
    for(int i = 0; i < ALPHABET_NUM; i++)
    {
        table[i][0] = alphabet[i];
        table[i][1] = plugs[i];
    }
}


//-----------------------------Enigma---------------------------------//

enigma::enigma() : a(1), b(2), c(3)
{
    // wheel *ap, *bp, *cp;
    // // ap = new wheel(1);
    // // bp = new wheel(2);
    // // cp = new wheel(3);
    // a = *ap;
    // b = *bp;
    // c = *cp;

    reflector* p;
    p = new reflector(1);
    ref = *p;
}

// enigma::enigma(ifstream &fin) {}

void enigma::rotate()
{
    if(a.rotate())
    {
        if(b.rotate())
            c.rotate();
    }
}

void enigma::set(alpha ta, alpha tb, alpha tc)
{
    a.set(ta);
    b.set(tb);
    c.set(tc);
}

void enigma::set(int tai, int tbi, int tci)
{
    alpha ta = (alpha) tai;
    alpha tb = (alpha) tbi;
    alpha tc = (alpha) tci;

    a.set(ta);
    b.set(tb);
    c.set(tc);
}

alpha enigma::send(alpha temp)
{
    rotate();
    alpha t;
    t = a.send(temp);
    t = b.send(t);
    t = c.send(t);
    // t = ref.recv(t);
    // t = c.recv(t);
    // t = b.recv(t);
    // t = a.recv(t);
    return t;
}

alpha enigma::recv(alpha temp)
{
    rotate();
    alpha t;
    t = a.send(temp);
    t = b.send(t);
    t = c.send(t);
    // t = ref.send(t);
    // t = c.send(t);
    // t = b.send(t);
    // t = a.send(t);
    return t;
}
#endif