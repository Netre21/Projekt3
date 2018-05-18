#include"sklep.hpp"
#include"ksiazki.hpp"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include"random.h"
using namespace std;

sklep::sklep(int ka,int pracownicy)
    {
    if(ka>=pracownicy)
        {
        ilosckas=pracownicy;
        pracownicynasali=0;
        }
    else
        {
        ilosckas=ka;
        pracownicynasali=pracownicy-ka;
        }
    kasy=new queue<int> [ilosckas];
    for(int i=0;i<ilosckas;i++)
        {
        queue<int> kolejka;
        kasy[i]=kolejka;
        }
    czas=new int [ilosckas];
    for(int i=0;i<ilosckas;i++)
        {
        czas[i]=4;
        }
    }
sklep::~sklep()
    {
    delete kasy;
    }

int sklep::szukajkasy()
    {
    int minimum;
    minimum=kasy[0].size();
    int numerkolejki=1;
    for(int i=0;i<ilosckas;i++)
        {
        if(minimum>kasy[i].size())
            {
            minimum=kasy[i].size();
            numerkolejki=i+1;
            }
        }
    return numerkolejki;
    }

void sklep::zycie(int n)
    {
    int otwarty=1;
    int maxk=1;
    while(otwarty<=n)
        {
        cout<<"czas: "<<otwarty<<endl;
        for(int i=0;i<klienci.size();i++)
            {
            if(!(klienci[i].stan()))
                {
                klienci[i].zajmij();
                switch(klienci[i].zyj())
                    {
                    case 1:
                        cout<<"klient "<<klienci[i].nr()<<" idzie do kasy "<<szukajkasy()<<endl;
                        kasy[szukajkasy()-1].push( klienci[i].nr());
                        break;
                    case 2:
                        cout<<"klient "<<klienci[i].nr()<<" rezerwuje ksiazke"<<endl;
                        break;
                    case 3:
                        cout<<"klient "<<klienci[i].nr()<<" wychodzi z ksiegarni"<<endl;
                        for(int j=0;j<klienci.size();j++)
                            {
                            if(klienci[j].nr()==klienci[i].nr())
                                {
                                klienci.erase(klienci.begin()+j);
                                break;
                                }
                            }
                        break;
                    default:
                        klienci[i].zwolnij();
                        break;
                    }
                }
            }
        uzyciekasy();
        otwarty=otwarty+1;
        Sleep(100);
        if(randomChance(0.3))
            {
            klient a(maxk);
            klienci.push_back(a);
            cout<<"klient "<<maxk<<" wchodzi do sklepu"<<endl;
            maxk=maxk+1;
            }
        }
    }

void sklep::uzyciekasy()
    {
    int n;
    for(int j=0;j<ilosckas;j++)
        {
        if(kasy[j].size()!=0)
            {
            czas[j]=czas[j]-1;
            if(czas[j]==0)
                {
                czas[j]=4;
                n=losujkat();
                if(kile(n)==0)
                    {
                    cout<<"klientowi "<<kasy[j].front()<<". nie udaje siê kupiæ ksiazki z dzialu "<<knazwa(n)<<", w kasie numer "<<j+1<<" ,poniewaz sie skonczyly"<<endl;
                    }
                else
                    {
                    cout<<"klient "<<kasy[j].front()<<" kupuje ksiazke z dzialu "<<knazwa(n)<<", w kasie numer "<<j+1<<" i placi za nia "<<kcena(n)<<endl;
                    }
                kasy[j].pop();
                }
            }
        }
    }
