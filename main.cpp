#include"sklep.hpp"
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
ifstream plik;
plik.open("wksiazki.txt");
if(!plik.good())
    {
    cout<<"blad oczytu"<<endl;
    return 0;
    }
int a,b,c,d,e,f;
plik>>a>>b>>c>>d>>e>>f;
sklep empik(a,b,c,d,e);
empik.zycie(f);
cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f;

}
