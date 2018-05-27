#include"klient.hpp"
#include"pracownik.hpp"
#include"randliczby.hpp"
#include<queue>
#include<fstream>
#include"ks.hpp"
#ifndef sklep_hpp
#define sklep_hpp

using namespace std;

class intersklep
{
public:
virtual void zycie(int n)=0;
virtual int szukajkasy()=0;
virtual void uzyciekasy()=0;
};

class sklep: public intersklep
    {
    fstream plikz;
    int zapis;
    int ilosckas;
    int pracownicynasali;
    vector<pracownik> pracownicy_sala;
    queue<int> * kasy;
    vector<klient> klienci;
    vector<ksiazka *> ksiazki;
    int *czas;
    losowanie Rn;
public:
    sklep(int k,int o, int przyr, int komp, int hum,int zap=0);
    ~sklep();
virtual void zycie(int n);
virtual int szukajkasy();
virtual void uzyciekasy();
    };

#endif // sklep
