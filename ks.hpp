#ifndef ks_hpp
#define ks_hpp
#include<stdlib.h>
#include<string>
using namespace std;

class ksiazka//klasa abstrakcyjna, ktora jest baza dla klas przyrodnicze, humanistyczne, komputerowe
    {
public:
    int kscena;
    virtual int kcena()=0;//funckja, ktora ma zwracac cene ksiazki
    virtual string knazwa()=0;// funkcja, ktora ma zwracac nazwe dzialu ksiazki
    };

class przyrodnicze : public ksiazka
    {
public:
    przyrodnicze();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };

class komputerowe : public ksiazka
    {
public:
    komputerowe();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };

class humanistyczne : public ksiazka
    {
public:
    humanistyczne();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };





#endif // ks_hpp
