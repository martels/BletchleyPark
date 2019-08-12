#include <iostream>
#include "Enigma.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
    enigma box;
    EnigmaNum info;
    string message = "HI";
    box.selectRotorA(1);
    box.selectRotorB(2);
    box.selectRotorC(3);
    box.selectReflector(1);
    box.setRotors(0, 0, 0);

    cout << "Please enter a messaage with no spaces in all caps:" << endl;
    cin >> message;

    cout << endl << "-------------------------ENCODING--------------------------" << endl;

    vector<char> msg(message.begin(), message.end());
    int recv = 0;
    vector<char> enco;
    for(int i = 0; i < msg.size(); i++)
    {
        recv = box.send(info.convert2int(msg.at(i)));
        enco.push_back(info.convert2char(recv));
    }

    cout << "The encoded message is: " << endl;

    for(int i = 0; i < msg.size(); i++)
    {
        cout << enco.at(i);
    }

    cout << endl;

    return 0;
}