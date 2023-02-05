#ifndef GENERATOR_HPP_INCLUDED
#define GENERATOR_HPP_INCLUDED

using namespace std;

class Generator
{
public:
    string GenRandText(int SizeText);
private:
    vector<char> lowCase = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<char> uppCase = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<int> Numbers = {0,1,2,3,4,5,6,7,8,9};
    vector<char> SpecialChar = {'!','@','#','$','%','&','*','(',')','=','+','-','_'};
};

string Generator::GenRandText(int SizeText)
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
            text += lowCase.at(Rand_Index);
            break;
        case 1:
            Rand_Index = rand() % 24;
            text += uppCase.at(Rand_Index);
            break;
        case 2:
            Rand_Index = rand() % 9;
            text += to_string(Numbers.at(Rand_Index));
            break;
        case 3:
            Rand_Index = rand() % 12;
            text += SpecialChar.at(Rand_Index);
            break;
        default:
            j--;
        }
    }
    return text;
}
#endif // GENERATOR_HPP_INCLUDED
