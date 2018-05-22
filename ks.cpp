#include<stdlib.h>
#include"random.h"
#include"ks.hpp"
using namespace std;


int przyrodnicze::kcena()
    {
    return randomInteger(8,40);
    }
string przyrodnicze::knazwa()
    {
    return "przyrodnicze";
    }


int humanistyczne::kcena()
    {
    return randomInteger(13,25);
    }
string humanistyczne::knazwa()
    {
    return "humanistyczne";
    }


int komputerowe::kcena()
    {
    return randomInteger(2,16);
    }
string komputerowe::knazwa()
    {
    return "komputerowe";
    }
