#include"klient.hpp"

#include<cstdlib>
#include<ctime>
#include<windows.h>
#include"random.h"
enum dzialanie
{
nic_nie_robi=0,
kupuje_ksiazke=1,
rezerwuje_ksiazke=2,
opuszcza_ksiegarnie=3,
rozmawia_z_pracownikiem=4,
};

klient::klient(int n)
    {
    numer=n;
    zajety=false;
    }

int klient::nr()//zwraca numer klienta
    {
    return numer;
    }

int klient::zyj()//wylosuj czynnosc
    {
    dzialanie klienta;
    int czynnosc;
    czynnosc=nic_nie_robi;

    if(RN.losuj(0.2)&& czynnosc!=1)//kupuje ksiazke
        {
        czynnosc=1;
        return kupuje_ksiazke;
        }
    if(RN.losuj(0.1) && czynnosc!=1)// rezerwuje ksiazke
        {
        czynnosc=1;
        return rezerwuje_ksiazke;
        }
    if(RN.losuj(0.1) && czynnosc!=1)// opuszcza ksiegarnie
        {
        czynnosc=1;
        return opuszcza_ksiegarnie;
        }
    if(RN.losuj(0.4) && czynnosc!=1)//rozmawia z pracownikiem
        {
        czynnosc=1;
        return rozmawia_z_pracownikiem;
        }
    return nic_nie_robi;
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
