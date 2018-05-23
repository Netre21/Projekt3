#include"klient.hpp"
#include<queue>

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
    int ilosckas;
    int pracownicynasali;
    int * zajecie_pracownikow;
    queue<int> * kasy;
    vector<klient> klienci;
    vector<ksiazka *> ksiazki;
    int *czas;
public:
    sklep(int k,int o, int przyr, int komp, int hum);
    ~sklep();
virtual void zycie(int n);
virtual int szukajkasy();
virtual void uzyciekasy();
    };

#endif // sklep
