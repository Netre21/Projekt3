#ifndef ksiazki_hpp
#define ksiazki_hpp
#include<stdlib.h>
#include<string>
using namespace std;


    struct kategoria
    {
    int cena;
    int ilosc;
    string nazwa;

    kategoria(int a=0,int b=0, string c="");
    int koszt();
    int ile();
    string jnazwa();
    friend ostream& operator<<(ostream& out,kategoria &p);
    };

class ksiazki
    {
    int liczba=3;
    kategoria * ksiegozbior;
public:
    ksiazki();
void drukuj();
int kile(int n);
int kcena(int n);
string knazwa(int n);
void zmniejszi(int n);
void zwiekszbib(int a, int b, string c);
int losujkat();
void wczytajzpliku();
    };



#endif // ksiazki_hpp
