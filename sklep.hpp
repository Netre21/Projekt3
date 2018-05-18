#include"klient.hpp"
#include<queue>
#include "ksiazki.hpp"
#ifndef sklep_hpp
#define sklep_hpp
using namespace std;
class sklep: public ksiazki
    {
    int ilosckas;
    int pracownicynasali;
    queue<int> * kasy;
    vector<klient> klienci;
    int *czas;
public:
    sklep(int k,int o);
    ~sklep();
void zycie(int n);
int szukajkasy();
void uzyciekasy();
    };

#endif // sklep
