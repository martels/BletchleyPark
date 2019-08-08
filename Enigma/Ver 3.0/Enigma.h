//-----------VER 3.0------------//

#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include "CONT_LIST.h"
#include "EnigmaNum.h"


using namespace std;

class enigma
{
    private:
    Cont_List rotorA;
    Cont_List rotorB;
    Cont_List rotorC;
    Cont_List reflect;
    EnigmaNum info;
    int counterA, counterB, counterC;

    public:
    void selectRotorA(int select);
    void selectRotorB(int select);
    void selectRotorC(int select);
    void selectReflector(int select); 
    void setRotors(int A, int B, int c);
    void rotate();
    int send(int msg);
    int recv(int msg);
};

void enigma::selectRotorA(int select)
{
    if(select > 8 || select < 1)
    {
        cout << "Not a valid entry, [selectRotorA()]" << endl;
        return;
    }

    if(select == 1)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor1[i]);
        }
    }

    if(select == 2)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor2[i]);
        }
    }

    if(select == 3)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor3[i]);
        }
    }

    if(select == 4)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor4[i]);
        }
    }

    if(select == 5)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor5[i]);
        }
    }

    if(select == 6)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor6[i]);
        }
    }

    if(select == 7)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor7[i]);
        }
    }

    if(select == 8)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorA.addNode(info.numeric[i], info.rotor8[i]);
        }
    }
    return;
}

void enigma::selectRotorB(int select)
{
    if(select > 8 || select < 1)
    {
        cout << "Not a valid entry, [selectRotorB()]" << endl;
        return;
    }

    if(select == 1)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor1[i]);
        }
    }

    if(select == 2)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor2[i]);
        }
    }

    if(select == 3)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor3[i]);
        }
    }

    if(select == 4)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor4[i]);
        }
    }

    if(select == 5)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor5[i]);
        }
    }

    if(select == 6)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor6[i]);
        }
    }

    if(select == 7)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor7[i]);
        }
    }

    if(select == 8)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorB.addNode(info.numeric[i], info.rotor8[i]);
        }
    }
    return;
}

void enigma::selectRotorC(int select)
{
    if(select > 8 || select < 1)
    {
        cout << "Not a valid entry, [selectRotorC()]" << endl;
        return;
    }

    if(select == 1)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor1[i]);
        }
    }

    if(select == 2)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor2[i]);
        }
    }

    if(select == 3)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor3[i]);
        }
    }

    if(select == 4)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor4[i]);
        }
    }

    if(select == 5)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor5[i]);
        }
    }

    if(select == 6)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor6[i]);
        }
    }

    if(select == 7)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor7[i]);
        }
    }

    if(select == 8)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            rotorC.addNode(info.numeric[i], info.rotor8[i]);
        }
    }
    return;
}

void enigma::selectReflector(int select)
{
    if(select < 1 || select > 2)
    {
        cout << "Not a valid entry [selectReflector()]" << endl;
        return;
    }

    if(select == 1)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            reflect.addNode(info.numeric[i], info.reflector1[i]);
        }
    }

    if(select == 2)
    {
        for(int i = 0; i < ALPHANUM; i++)
        {
            reflect.addNode(info.numeric[i], info.reflector2[i]);
        }
    }

}

void enigma::setRotors(int A, int B, int C)
{
    rotorA.setInitial(A);
    rotorB.setInitial(B);
    rotorC.setInitial(C);
}

void enigma::rotate()
{
    counterA++;
    rotorA.click();
    if(counterA%(ALPHANUM-1) == 0)
    {
        rotorB.click();
        counterB++;
        if(counterB%(ALPHANUM-1) == 0)
        {
            rotorC.click();
            counterC++;
        }
    }
    rotorA.returnPointer();
    rotorB.returnPointer();
    rotorC.returnPointer();
    reflect.returnPointer();
    return;
}

int enigma::send(int msg)
{
    for(int i = 0; i < msg; i++)
    {
        rotorA.iterate();
    }

    msg = rotorA.getLink();
    
    for(int i = 0; i < msg; i++)
    {
        rotorB.iterate();
    }
    
    msg = rotorB.getLink();
    
    for(int i = 0; i < msg; i++)
    {
        rotorC.iterate();
    }
    
    msg = rotorC.getLink();
    
    for(int i = 0; i < msg; i++)
    {
        reflect.iterate();
    }
    
    msg = reflect.getLink();
    rotorA.returnPointer();
    rotorB.returnPointer();
    rotorC.returnPointer();
    reflect.returnPointer();

    // for(int i = 0; i < msg; i++)
    // {
    //     rotorC.iterate();
    // }

    // msg = rotorC.getIndex();

    // for(int i = 0; i < msg; i++)
    // {
    //     rotorB.iterate();
    // }    

    // msg = rotorB.getIndex();

    // for(int i = 0; i < msg; i++)
    // {
    //     rotorA.iterate();
    // }

    // msg = rotorA.getIndex();

    // rotorA.returnPointer();
    // rotorB.returnPointer();
    // rotorC.returnPointer();
    // reflect.returnPointer();
    // rotate();
    return msg;
}

int enigma::recv(int msg)
{
    // for(int i = 0; i < msg; i++)
    // {
    //     rotorA.iterate();
    // }

    // msg = rotorA.getIndex();
    
    // for(int i = 0; i < msg; i++)
    // {
    //     rotorB.iterate();
    // }
    
    // msg = rotorB.getIndex();
    
    // for(int i = 0; i < msg; i++)
    // {
    //     rotorC.iterate();
    // }
    
    // msg = rotorC.getIndex();
    
    // for(int i = 0; i < msg; i++)
    // {
    //     reflect.iterate();
    // }
    
    msg = reflect.getLink();
    rotorA.returnPointer();
    rotorB.returnPointer();
    rotorC.returnPointer();
    reflect.returnPointer();

    for(int i = 0; i < msg; i++)
    {
        rotorC.iterate();
    }

    msg = rotorC.getIndex();

    for(int i = 0; i < msg; i++)
    {
        rotorB.iterate();
    }    

    msg = rotorB.getIndex();

    for(int i = 0; i < msg; i++)
    {
        rotorA.iterate();
    }

    msg = rotorA.getIndex();

    rotorA.returnPointer();
    rotorB.returnPointer();
    rotorC.returnPointer();
    reflect.returnPointer();
    // rotate();
    return msg;
}


#endif