#include<random>
#include<chrono>
#include"randliczby.hpp"
#include<iostream>
using namespace std;


losowanie::losowanie()
    {
    unsigned seed1=chrono::system_clock::now().time_since_epoch().count();
    b=mt19937(seed1);// stworz maszyne do losowanie
    }


bool losowanie::losuj(double a)
    {
    int mnoznik=1;
    while(ceil(a)!=a)
        {
        mnoznik=mnoznik*10;
        a=a*10;
        }
    int losowa;
    losowa=b()%mnoznik;
    if(losowa<a)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

int losowanie::wylosuj(int a, int c)
    {
    return b()%(c-a+1)+a;
    }
