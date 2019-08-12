#ifndef ENIGMANUM_H
#define ENIGMANUM_H

    const int ALPHANUM = 26;

class EnigmaNum
{
    public:
        char Aalphabet[ALPHANUM], Arotor1[ALPHANUM], Arotor2[ALPHANUM], Arotor3[ALPHANUM], 
                Arotor4[ALPHANUM], Arotor5[ALPHANUM], Arotor6[ALPHANUM], Arotor7[ALPHANUM], 
                Arotor8[ALPHANUM], Areflector1[ALPHANUM], Areflector2[ALPHANUM];
        int numeric[ALPHANUM];

        int rotor1[ALPHANUM], rotor2[ALPHANUM], rotor3[ALPHANUM], rotor4[ALPHANUM],
            rotor5[ALPHANUM], rotor6[ALPHANUM], rotor7[ALPHANUM], rotor8[ALPHANUM], reflector1[ALPHANUM], 
            reflector2[ALPHANUM];
        EnigmaNum();
        int convert2int(char msg);
        char convert2char(int msg);
};


EnigmaNum::EnigmaNum()
{

    char A[ALPHANUM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char B[ALPHANUM] = {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O',
                                    'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'};
    char C[ALPHANUM] = {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W',
                                    'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'};
    char D[ALPHANUM] = {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z',
                                    'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'};
    char E[ALPHANUM] = {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R',
                                    'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'};
    char F[ALPHANUM] = {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N',
                                    'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'};
    char G[ALPHANUM] = {'J', 'P', 'G', 'V', 'O', 'U', 'M', 'F', 'Y', 'Q', 'B', 'E', 'N',
                                    'H', 'Z', 'R', 'D', 'K', 'A', 'S', 'X', 'L', 'I', 'C', 'T', 'W'};
    char H[ALPHANUM] = {'N', 'Z', 'J', 'H', 'G', 'R', 'C', 'X', 'M', 'Y', 'S', 'W', 'B',
                                    'O', 'U', 'F', 'A', 'I', 'V', 'L', 'P', 'E', 'K', 'Q', 'D', 'T'};
    char I[ALPHANUM] = {'F', 'K', 'Q', 'H', 'T', 'L', 'X', 'O', 'C', 'B', 'J', 'S', 'P',
                                    'D', 'Z', 'R', 'A', 'M', 'E', 'W', 'N', 'I', 'U', 'Y', 'G', 'V'};
    char J[ALPHANUM] = {'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O',
                                    'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T'};
    char K[ALPHANUM] = {'F', 'V', 'P', 'J', 'I', 'A', 'O', 'Y', 'E', 'D', 'R', 'Z', 'X',
                                    'W', 'G', 'C', 'T', 'K', 'U', 'Q', 'S', 'B', 'N', 'M', 'H', 'L'};
    int N[ALPHANUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
                                18, 19, 20 , 21, 22, 23 , 24, 25};

    for(int i = 0; i < ALPHANUM; i++)
    {
        Aalphabet[i] = A[i];
        Arotor1[i] = B[i];
        Arotor2[i] = C[i];
        Arotor3[i] = D[i];
        Arotor4[i] = E[i];
        Arotor5[i] = F[i];
        Arotor6[i] = G[i];
        Arotor7[i] = H[i];
        Arotor8[i] = I[i];
        Areflector1[i] = J[i];
        Areflector2[i] = K[i];
        numeric[i] = N[i];
    }

    int p = 0;
    for(int i = 0; i < ALPHANUM; i++)
    {
        while(Arotor1[i] != Aalphabet[p])
        {
            p++;
        }
        rotor1[i] = p;
        p = 0;

        while(Arotor2[i] != Aalphabet[p])
        {
            p++;
        }
        rotor2[i] = p;
        p = 0;

        while(Arotor3[i] != Aalphabet[p])
        {
            p++;
        }
        rotor3[i] = p;
        p = 0;

        while(Arotor4[i] != Aalphabet[p])
        {
            p++;
        }
        rotor4[i] = p;
        p = 0;
        
        while(Arotor5[i] != Aalphabet[p])
        {
            p++;
        }
        rotor5[i] = p;
        p = 0;

        while(Arotor6[i] != Aalphabet[p])
        {
            p++;
        }
        rotor6[i] = p;
        p = 0;

        while(Arotor7[i] != Aalphabet[p])
        {
            p++;
        }
        rotor7[i] = p;
        p = 0;

        while(Arotor8[i] != Aalphabet[p])
        {
            p++;
        }
        rotor8[i] = p;
        p = 0;

        while(Areflector1[i] != Aalphabet[p])
        {
            p++;
        }
        reflector1[i] = p;
        p = 0;
        
        while(Areflector2[i] != Aalphabet[p])
        {
            p++;
        }
        reflector2[i] = p;
        p = 0;
    }
}

int EnigmaNum::convert2int(char msg)
{
    int count = 0;

    while(msg != Aalphabet[count] && count <= ALPHANUM)
    {
        count++;
    }

    if(count == ALPHANUM)
    {
        cout << "Error, invalid character." << endl;
        return -1;
    }

    return numeric[count];
}

char EnigmaNum::convert2char(int msg)
{
    return Aalphabet[msg];
}

#endif