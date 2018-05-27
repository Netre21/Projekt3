#ifndef ks_hpp
#define ks_hpp
#include<stdlib.h>
#include<string>
using namespace std;

class ksiazka//klasa abstrakcyjna, ktora jest baza dla klas przyrodnicze, humanistyczne, komputerowe
    {
public:
    virtual int kcena()=0;//funckja, ktora ma zwracac cene ksiazki
    virtual string knazwa()=0;// funkcja, ktora ma zwracac nazwe dzialu ksiazki
    };

class przyrodnicze : public ksiazka
    {
public:
    int kscena;
    przyrodnicze();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };

class komputerowe : public ksiazka
    {
public:
    int kscena;
    komputerowe();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };

class humanistyczne : public ksiazka
    {
    int kscena;
public:
    humanistyczne();
    virtual int kcena();//zwraca cene ksiazki
    virtual string knazwa();//zwraca nazwe dzialu ksiazki
    };





#endif // ks_hpp
