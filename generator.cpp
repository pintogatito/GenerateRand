#include "inc/Generate.hpp"
#include "inc/Arrays.h"

string GenRandText(int SizeText)
{
    string text;
    int Rand_Option;
    int Rand_Index;

    for(int j=0; j < SizeText; j++)
    {
        Rand_Option = rand() % 4;
        switch(Rand_Option)
        {
        case 0:
            Rand_Index = rand() % 24;
            text += lowCase[Rand_Index];
            break;
        case 1:
            Rand_Index = rand() % 24;
            text += uppCase[Rand_Index];
            break;
        case 2:
            Rand_Index = rand() % 9;
            text += to_string(Numbers[Rand_Index]);
            break;
        case 3:
            Rand_Index = rand() % 12;
            text += SpecialChar[Rand_Index];
            break;
        default:
            j--;
        }
    }

    return text;
}
