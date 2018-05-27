#include<stdlib.h>
#include"pracownik.hpp"
using namespace std;


pracownik::pracownik(int n)
    {
    zajetosc=0;
    numer=n;
    }

void pracownik::zwolnij()
    {
    zajetosc=0;
    }

void pracownik::zajmij()
    {
    zajetosc=1;
    }

int pracownik::stan()
    {
    return zajetosc;
    }

int pracownik::pnumer()
    {
    return numer;
    }
