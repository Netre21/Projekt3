#ifndef ks_hpp
#define ks_hpp
#include<stdlib.h>
#include<string>
using namespace std;
class ksiazka
    {
public:
    virtual int kcena()=0;
    virtual string knazwa()=0;
    };
class przyrodnicze : public ksiazka
    {

public:
    virtual int kcena();
    virtual string knazwa();
    };
class komputerowe : public ksiazka
    {
public:
    virtual int kcena();
    virtual string knazwa();
    };
class humanistyczne : public ksiazka
    {
    virtual int kcena();
    virtual string knazwa();
    };





#endif // ks_hpp
