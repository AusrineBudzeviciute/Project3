#include "my_lib.h"


int main()
{
    char konteineris;
    cout<<"Pasirinkite, kokiame konteineryje talpinami duomenys ('v'-vector, 'l'-list): ";
    cin>>konteineris;
    if (konteineris == 'l')
    {
        listas();
    }
    else if (konteineris == 'v')
    {
        vektorius();
    }
}





