#include"sklep.hpp"
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
fstream plik;
try//podaje moj kod
    {
    plik.open("wksiazki.txt");
    if(!plik.good())
        {
        int blad=1;
        throw blad;
        }
    int a,b,c,d,e,f;
    plik>>a>>b>>c>>d>>e>>f;

    if(a<1)//to znaczy ze nie ma zadnych dostepnych kas
        {
        string w2="Jezeli zadna kasa nie jest otwarta to sklep tez nie";
        throw w2;
        }

    if(b<1)// to znaczy ze nie ma zadnych pracownikow do obslugi kas lub bycia na sali
        {
        string w3="Jezeli nie ma pracownikow to sklep nie moze byc otwarty";
        throw w3;
        }

    if(f<1)//czas otwarcia wynosi mniej niz 0, czyli sklep nie zostal otwarty
        {
        string w4="Czas otwarcia sklepu trwal 0 sekund, wiec nie zostal otwarty";
        throw w4;
        }

    sklep empik(a,b,c,d,e,1);
    empik.zycie(f);
    }
catch(string w)//wyjatki, gdy udalo sie otworzyc plik, wiec musimy go zamknac
    {
    cout<<"Wyjatek: "<<w<<endl;
    plik.close();
    }
catch(int n)//przypadek, gdy nawet nie otworzylismy pliku
    {
    cout<<"Wyjatek, nie udalo sie otworzyc pliku";
    }
catch(...)//awaryjnie gdyby jakis przypadek nie byl obsluzony przez wczesniejsze catch()
    {
    cout<<"cos poszlo nie tak :(";
    }
}
