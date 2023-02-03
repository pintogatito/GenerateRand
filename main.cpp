#include <iostream>
#include <cstdlib>
#include <ctime>

#include "inc/Generate.hpp"
using namespace std;

int main()
{
    //Declaration of Variables
    int Size_Length;
    int Number_Lines;
    string Text;

    //Assing seed of random function
    srand(time(NULL));

    //Data Reading
    cout << "Enter the size of the random string: ";
    cin >> Size_Length;
    cout << "Enter the number of lines to generate: ";
    cin >> Number_Lines;

    //Cicle
    for(int j=0; j < Number_Lines; j++)
    {
        Text = GenRandText(Size_Length);
        cout << Text << endl;
    }
    return 0;
}
