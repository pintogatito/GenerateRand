#ifndef GENERATORMANAGER_HPP_INCLUDED
#define GENERATORMANAGER_HPP_INCLUDED

#include "Generator.hpp"
class GeneratorManager
{
public:
    bool GenText(int SizeText,int NumLines,string file);
};

bool GeneratorManager::GenText(int SizeText,int NumLines,string file)
{
    Generator g;
    string text;
    file += ".txt";
    ofstream myfile (file);
    if(!myfile.is_open())
    {
        return false;
    }
    for (int i = 0; i < NumLines; ++i)
    {
        text = g.GenRandText(SizeText);
        myfile << text << endl;
    }
    myfile.close();
    return true;
}

#endif // GENERATORMANAGER_HPP_INCLUDED
