#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>

const int ALPHABET_NUM = 26;

using namespace std;

class rotor
{
    private:
    int table[ALPHABET_NUM][2];
    int position;

    public:
    int forward(int);
    int bckward(int);
    void click();
    void setPosition(int);

};

class reflector
{
    private:
    int table[ALPHABET_NUM][2];

    public:
    int forward 
};

// class plugboard
// {

// };

class enigma
{
    private:

    public:

};