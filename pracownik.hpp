#include<stdlib.h>

using namespace std;

class interpracownik
{
public:
virtual void zwolnij()=0;
virtual void zajmij()=0;
virtual int stan()=0;
virtual int pnumer()=0;
};


class pracownik: public interpracownik
{
int zajetosc;
int numer;
public:
    pracownik(int n);
virtual void zwolnij();
virtual void zajmij();
virtual int stan();
virtual int pnumer();
};
