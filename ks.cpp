#include<stdlib.h>
#include"random.h"
#include"ks.hpp"
using namespace std;

przyrodnicze::przyrodnicze()
    {
    kscena=randomInteger(8,40);//losuje cene
    }
int przyrodnicze::kcena()
    {
    return kscena+14;//zwracam cene danej ksiazki
    }
string przyrodnicze::knazwa()
    {
    return "przyrodnicze";//zwracam nazwa grupy do ktorej nalezy dana ksiazka
    }

humanistyczne::humanistyczne()
    {
    kscena=randomInteger(13,25);//losuje cene
    }
int humanistyczne::kcena()
    {
    return kscena+23;//zwracam cene danej ksiazki
    }
string humanistyczne::knazwa()
    {
    return "humanistyczne";//zwracam nazwa grupy do ktorej nalezy dana ksiazka
    }

komputerowe::komputerowe()
    {
    kscena=randomInteger(2,16);//losuje cene
    }
int komputerowe::kcena()
    {
    return kscena+18;//zwracam cene danej ksiazki
    }
string komputerowe::knazwa()
    {
    return "komputerowe";//zwracam nazwa grupy do ktorej nalezy dana ksiazka
    }
