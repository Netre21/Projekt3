#include<iostream>
#include"ksiazki.hpp"
#include<stdlib.h>
#include"random.h"
#include<fstream>
using namespace std;

ksiazki::ksiazki()
    {
    ksiegozbior=new kategoria [3];
    kategoria a(2,26,"kryminaly");
    ksiegozbior[0]=a;
    kategoria b(10,30,"przyrodnicze");
    ksiegozbior[1]=b;
    kategoria c(60,10,"sci-fi");
    ksiegozbior[2]=c;
    wczytajzpliku();
    }
void ksiazki::drukuj()
    {
    for(int i=0;i<liczba;i++)
        {
        cout<<ksiegozbior[i];
        }
    }
kategoria::kategoria(int a, int b, string c)
    {
    ilosc=a;
    cena=b;
    nazwa=c;
    }
int kategoria::koszt()
    {
    return cena;
    }
int kategoria::ile()
    {
    return ilosc;
    }
string kategoria::jnazwa()
    {
    return nazwa;
    }
ostream& operator<<(ostream& out,kategoria &p)
        {
        out<<"nazwa: "<<p.nazwa<<" ,ilosc: "<<p.ilosc<<" ,cena: "<<p.cena<<endl;
        return out;
        }

int ksiazki::kile(int n)
    {
    return ksiegozbior[n].ile();
    }
int ksiazki::kcena(int n)
    {
    return ksiegozbior[n].koszt();
    }
string ksiazki::knazwa(int n)
    {
    return ksiegozbior[n].jnazwa();
    }

void ksiazki::zmniejszi(int n)
    {
    if(ksiegozbior[n].ilosc==0)
        {
        cout<<"brak ksiazek z kategori: "<<ksiegozbior[n].nazwa<<endl;
        return;
        }
    ksiegozbior[n].ilosc=ksiegozbior[n].ilosc-1;
    return;
    }
void ksiazki::zwiekszbib(int a, int b, string c)
    {
    kategoria* temp=ksiegozbior;
    ksiegozbior=new kategoria [liczba+1];
    for(int i=0;i<liczba;i++)
        {
        ksiegozbior[i]=temp[i];
        }
    liczba=liczba+1;
    kategoria tym(a,b,c);
    ksiegozbior[liczba-1]=tym;
    delete temp;
    }
int ksiazki::losujkat()
    {
    int n;
    n=randomInteger(0,liczba-1);
    return n;
    }

void ksiazki::wczytajzpliku()
    {
    ifstream plik;
    plik.open("wksiazki.txt");
    if(!plik.good())
        {
        cout<<"nie powiodlo sie wczytanie"<<endl;
        return;
        }
    int licz;
    plik>>licz;
    string c;
    int a;
    int b;
    kategoria *temp;
    temp=new kategoria [licz+liczba];
    for(int i=0;i<liczba;i++)
        {
        temp[i]=ksiegozbior[i];
        }
    for(int i=liczba;i<licz+liczba;i++)
        {
        plik>>a>>b;
        getline(plik,c);
        kategoria X(a,b,c);
        temp[i]=X;
        }
    delete[] ksiegozbior;
    ksiegozbior=temp;
    liczba=liczba+licz;
    }
