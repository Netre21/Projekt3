#include"sklep.hpp"
#include<iostream>
#include"ks.hpp"
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;

sklep::sklep(int ka,int pracownicy, int przyr, int komp, int hum, int zap)
    {
    if(ka>=pracownicy)//zapelniamy kasy pracownikami
        {
        ilosckas=pracownicy;
        pracownicynasali=0;
        }
    else
        {
        ilosckas=ka;
        pracownicynasali=pracownicy-ka;
        }
    kasy=new queue<int> [ilosckas];//towrzymy tablice kolejek, w ktorej bedziemy przechowywali klientow czekajacych do danej kasy
    for(int i=0;i<ilosckas;i++)//tworzymy kolejki
        {
        queue<int> kolejka;
        kasy[i]=kolejka;
        }
    czas=new int [ilosckas];//tablica int, by wiedziec ile czasu stoi pierwsza osoba przy kasie (czas obslugi)
    for(int i=0;i<ilosckas;i++)
        {
        czas[i]=4;//klient potrzebuje 4 jednostek czasu przy kasie, zeby kupic ksiazke
        }
    //tworzymy vector, ktory przechowuje ksiazki 3 typow: przyrodniczych, humanistycznych i komputerowych
    for(int i=0;i<przyr;i++)//zapelniamy vector ksiazkami przyrodniczymi
        {
        przyrodnicze PR();
        ksiazki.push_back(new przyrodnicze());
        }
    for(int i=0;i<komp;i++)//komputerowymi
        {
        komputerowe KP();
        ksiazki.push_back(new komputerowe());
        }
    for(int i=0;i<hum;i++)//humanistycznymi
        {
        humanistyczne HM();
        ksiazki.push_back(new humanistyczne());
        }
    for(int i=0;i<pracownicynasali;i++)
        {
        pracownik PS(i+1);
        pracownicy_sala.push_back(PS);
        }
    zapis=zap;
    if(zapis==1)
        {
        plikz.open("przebieg.txt",ios::trunc | ios::out);
        if(plikz.good()!=1)
            {
            string blad="nie udalo sie otworzyc pliku do zapisywania";
            throw blad;
            }
        }
    }

sklep::~sklep()
    {

    delete [] czas;
    delete [] kasy;

    }

int sklep::szukajkasy()//funckja, ktora wyszukuje kase z najmniejsza kolejka i tam kieruje klienta
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

void sklep::zycie(int n)//funckcja, ktora odpowiada za zycie sklepu
    {
    int otwarty=1;
    int maxk=1;
    int hehehe;
    while(otwarty<=n)//czas otwarcia
        {
        cout<<"czas: "<<otwarty<<endl;
        if(zapis==1)
            {
            plikz<<"czas: "<<otwarty<<endl;
            }
        for(int i=0;i<klienci.size();i++)//wykonujemy wnetrze petli dla kazdego klienta w sklepie
            {
            if(!(klienci[i].stan()))//jezeli klient nie jest zajety to losujemy jego aktywnosc metoda zyj z klasy klient
                {
                switch(klienci[i].zyj())//w zaleznosci od wylosowanej akcji zostaja podjete kolejne kroki
                    {
                    case 1:
                        cout<<"klient "<<klienci[i].nr()<<" idzie do kasy "<<szukajkasy()<<endl;
                        if(zapis==1)
                            {
                            plikz<<"klient "<<klienci[i].nr()<<" idzie do kasy "<<szukajkasy()<<endl;
                            }
                        kasy[szukajkasy()-1].push( klienci[i].nr());
                        klienci[i].zajmij();
                        break;
                    case 2:
                        cout<<"klient "<<klienci[i].nr()<<" rezerwuje ksiazke"<<endl;
                        if(zapis==1)
                            {
                            plikz<<"klient "<<klienci[i].nr()<<" rezerwuje ksiazke"<<endl;
                            }
                        break;
                    case 3:
                        cout<<"klient "<<klienci[i].nr()<<" wychodzi z ksiegarni"<<endl;
                        if(zapis==1)
                            {
                            plikz<<"klient "<<klienci[i].nr()<<" wychodzi z ksiegarni"<<endl;
                            }
                        for(int j=0;j<klienci.size();j++)
                            {
                            if(klienci[j].nr()==klienci[i].nr())
                                {
                                klienci.erase(klienci.begin()+j);//usuwamy klienta ze sklepu
                                break;
                                }
                            }
                        break;
                    case 4:
                        for(int j=0;j<pracownicynasali;j++)
                            {
                            if(pracownicy_sala[j].stan()==0)
                                {
                                cout<<"klient "<<klienci[i].nr()<<" rozmawia z pracownikiem "<<pracownicy_sala[j].pnumer()<<endl;
                                if(zapis==1)
                                    {
                                    plikz<<"klient "<<klienci[i].nr()<<" rozmawia z pracownikiem "<<pracownicy_sala[j].pnumer()<<endl;
                                    }
                                pracownicy_sala[j].zajmij();
                                break;
                                }
                            }
                        break;
                    case 0://klient nic nie robi, wiec go pomijamy
                        break;
                    default:
                        string bledny_wybor="klient wybral czynnosc z poza swojego zakresu";
                        throw bledny_wybor;
                        break;
                    }
                }
            }
        uzyciekasy();
        otwarty=otwarty+1;
        Sleep(10);//czekamy 1s
        if(Rn.losuj(0.3))//losujemy czy w danej jednostce czasu jakis klient wszedl do sklepu
            {
            klient a(maxk);
            klienci.push_back(a);
            cout<<"klient "<<maxk<<" wchodzi do sklepu"<<endl;
            if(zapis==1)
                {
                plikz<<"klient "<<maxk<<" wchodzi do sklepu"<<endl;
                }
            maxk=maxk+1;
            }
        for(int i=0;i<pracownicynasali;i++)//rozmowa z klientem trwa jedna jednostke czasu, wiec pod koniec tej jednostki zmieniamy stan pracownikow na wolny
            {
            pracownicy_sala[i].zwolnij();
            }
        }
    }

void sklep::uzyciekasy()//funkcja odpowiadajaca za przesuwanie kolejek przy kasach i informacji co kupuja klienci
    {
    int n;
    int koszt=-1;
    string knaz;
    int numerklienta;
    for(int j=0;j<ilosckas;j++)//wykonaj zawartosc dla kazdej kasy
        {
        if(kasy[j].size()!=0)//jezeli ktos stoi przy kasie to wykonaj wnetrze
            {
            czas[j]=czas[j]-1;//zmiejsz czas, ktory osoba pierwsza stoi przy kasie
            if(czas[j]==0)//jezeli czas tej osoy minal to wykonaj wnetrze
                {
                czas[j]=4;//ustaw czas dla kolejnej osoby
                for(int k=0;k<klienci.size();k++)//znajdz klienta, ktory wlasnie stal przy kasie
                    {
                    if(klienci[k].nr()==kasy[j].front())
                        {
                        numerklienta=k;
                        }
                    }
                n=Rn.wylosuj(1,3);//losuj jedna z 3 kategori ksiazki
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
                    for(int k=0;k<ksiazki.size();k++)//spradz dostepna ksiazki z danego dzialu
                        {
                        if(n==1)
                            {
                            if(ksiazki[k]->knazwa()=="przyrodnicze")//jesli sie udalo usun ja z listy ksiazek dostepnych
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        if(n==2)
                            {
                            if(ksiazki[k]->knazwa()=="komputerowe")//jesli sie udalo usun ja z listy ksiazek dostepnych
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        if(n==3)
                            {
                            if(ksiazki[k]->knazwa()=="humanistyczne")//jesli sie udalo usun ja z listy ksiazek dostepnych
                                {
                                koszt=ksiazki[k]->kcena();
                                ksiazki.erase(ksiazki.begin()+k);
                                break;
                                }
                            }
                        }
                if(koszt==-1)//koszt wynosi -1 tylko, gdy nie znaleziono ksiazki z wybranego przez klienta dzialu
                    {
                    cout<<"klientowi "<<kasy[j].front()<<". nie udaje sie kupic ksiazki z dzialu "<<knaz<<", w kasie numer "<<j+1<<" ,poniewaz sie skonczyly"<<endl;
                    if(zapis==1)
                        {
                        plikz<<"klientowi "<<kasy[j].front()<<". nie udaje sie kupic ksiazki z dzialu "<<knaz<<", w kasie numer "<<j+1<<" ,poniewaz sie skonczyly"<<endl;
                        }
                    }
                else
                    {
                    cout<<"klient "<<kasy[j].front()<<" kupuje ksiazke z dzialu "<<knaz<<", w kasie numer "<<j+1<<" i placi za nia "<<koszt<<endl;
                    if(zapis==1)
                        {
                        plikz<<"klient "<<kasy[j].front()<<" kupuje ksiazke z dzialu "<<knaz<<", w kasie numer "<<j+1<<" i placi za nia "<<koszt<<endl;
                        }
                    }
                for(int k=0;k<klienci.size();k++)//znajdz klienta, ktory wlasnie stal przy kasie
                    {
                    if(klienci[k].nr()==kasy[j].front())
                        {
                        klienci[k].zwolnij();//zmien jego stan na wolny, by mogl wykonywac inne czynnosci
                        }
                    }
                kasy[j].pop();//usun pierwszy element z kolejki, to znaczy ze klient kupil i odszedl od kasy
                }
            }
        }
    }
