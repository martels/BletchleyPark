#include "enigma.h"
#include <iostream>

using namespace std;

int main()
{
    enigma a;
    alpha test, coded, reply;

    test = B;
    a.set(A, A, A);
    coded = a.send(test);

    a.set(A, A, A);
    reply = a.recv(coded);

    cout << "Test = " << test << endl;
    cout << "Coded = " << coded << endl;
    cout << "Reply = " << reply << endl;

}