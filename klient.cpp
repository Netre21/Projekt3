#include"klient.hpp"
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include"random.h"
klient::klient(int n)
    {
    numer=n;
    zajety=false;
    }
int klient::nr()
    {
    return numer;
    }

int klient::zyj()
    {
    int czynnosc;
    czynnosc=0;

    if(randomChance(0.2)&& czynnosc!=1)//kupuje ksiazke
        {
        if(czynnosc!=1)
            {
            czynnosc=1;
            return 1;
            }
        }
    if(randomChance(0.1) && czynnosc!=1)// rezerwuje ksiazke
        {
        czynnosc=1;
        return 2;
        }
    if(randomChance(0.1) && czynnosc!=1)// opuszcza ksiegarnie
        {
        czynnosc=1;
        return 3;
        }
    return 0;
    }

void klient::zajmij()
    {
    zajety=true;
    }
void klient::zwolnij()
    {
    zajety=false;
    }
bool klient::stan()
    {
    return zajety;
    }
