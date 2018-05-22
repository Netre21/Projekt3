#include"sklep.hpp"
#include<iostream>
#include"ks.hpp"
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include"random.h"
using namespace std;

sklep::sklep(int ka,int pracownicy, int przyr, int komp, int hum)
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
    for(int i=0;i<przyr;i++)
        {
        przyrodnicze PR();
        ksiazki.push_back(new przyrodnicze());
        }
    for(int i=0;i<komp;i++)
        {
        komputerowe KP();
        ksiazki.push_back(new komputerowe());
        }
    for(int i=0;i<hum;i++)
        {
        humanistyczne HM();
        ksiazki.push_back(new humanistyczne());
        }
    zajecie_pracownikow=new int [pracownicynasali];
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
                switch(klienci[i].zyj())
                    {
                    case 1:
                        cout<<"klient "<<klienci[i].nr()<<" idzie do kasy "<<szukajkasy()<<endl;
                        kasy[szukajkasy()-1].push( klienci[i].nr());
                        klienci[i].zajmij();
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
                    case 4:
                        for(int j=0;j<pracownicynasali;j++)
                            {
                            if(zajecie_pracownikow[j]==0)
                                {
                                cout<<"klient "<<klienci[i].nr()<<" rozmawia z pracownikiem "<<j+1<<endl;
                                zajecie_pracownikow[j]=1;
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
        for(int i=0;i<pracownicynasali;i++)
            {
            zajecie_pracownikow[i]=0;
            }
        }
    }

void sklep::uzyciekasy()
    {
    int n;
    int koszt=-1;
    string knaz;
    for(int j=0;j<ilosckas;j++)
        {
        if(kasy[j].size()!=0)
            {
            czas[j]=czas[j]-1;
            if(czas[j]==0)
                {
                czas[j]=4;
                n=randomInteger(1,3);//ddddddddddddd
                switch (n)
                    {
                case 1:
                    knaz="przyrodniczego";
                    break;
                case 2:
                    knaz="komputerowego";
                    break;
                case 3:
                    knaz="humanistycznego";
                    break;
                    }
                    for(int k=0;k<ksiazki.size();k++)
                        {
                        if(n==1)
                            {
                            if(ksiazki[k]->knazwa()=="przyrodnicze")
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        if(n==2)
                            {
                            if(ksiazki[k]->knazwa()=="komputerowe")
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        if(n==3)
                            {
                            if(ksiazki[k]->knazwa()=="humanistyczne")
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        }
                if(koszt==-1)
                    {
                    cout<<"klientowi "<<kasy[j].front()<<". nie udaje sie kupic ksiazki z dzialu "<<knaz<<", w kasie numer "<<j+1<<" ,poniewaz sie skonczyly"<<endl;
                    }
                else
                    {
                    cout<<"klient "<<kasy[j].front()<<" kupuje ksiazke z dzialu "<<knaz<<", w kasie numer "<<j+1<<" i placi za nia "<<koszt<<endl;
                    }
                for(int k=0;k<klienci.size();k++)
                    {
                    if(klienci[k].nr()==kasy[j].front())
                        {
                        klienci[k].zwolnij();
                        }
                    }
                kasy[j].pop();
                }
            }
        }
    }
