#include <iostream>
#include "Enigma.h"


using namespace std;

int main()
{
    // Cont_List rotor;   
    // EnigmaNum info;

    // for(int i = 0; i < 4; i++)
    // {
    //     // cout << "here" <<  rotor.getNumNode() << endl;
    //     rotor.addNode(info.numeric[i], info.rotor1[i]);
    // }
    // cout << rotor.getNumNode() << endl;
    // rotor.setInitial(0);

    // for(int k = 0; k < ALPHANUM; k++)
    // {
    //     cout << "Index: " << rotor.getIndex() << ",   Link: " << rotor.getLink() << endl;
    //     rotor.iterate();
    // }



    
    enigma box;

    box.selectRotorA(1);
    box.selectRotorB(2);
    box.selectRotorC(3);
    box.selectReflector(1);
    box.setRotors(1, 2, 3);
    int message = 3, recv = 0;
    recv = box.send(message);
    cout << "Sent: " << message << ", encode: " << box.send(message) << ", decode: " << box.recv(recv) << endl;


    return 0;
}