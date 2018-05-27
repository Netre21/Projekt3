#include<random>
#ifndef randliczby_hpp
#define randliczby_hpp
using namespace std;
class interlosowanie
{
public:
virtual bool losuj(double a)=0;
virtual int wylosuj(int a, int b)=0;
};


class losowanie: public interlosowanie
{
mt19937 b;
public:
losowanie();
virtual bool losuj(double a);
virtual int wylosuj(int a,int b);
};
#endif // randliczby_hpp
