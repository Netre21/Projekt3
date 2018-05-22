#include"klient.hpp"
#include<queue>

#include"ks.hpp"
#ifndef sklep_hpp
#define sklep_hpp

using namespace std;
class sklep
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
void zycie(int n);
int szukajkasy();
void uzyciekasy();
    };

#endif // sklep
