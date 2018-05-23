

#ifndef klient_hpp
#define klient_hpp
class interklient//interfejs klienta
    {
    public:
    int numer;
    bool zajety;
    virtual int nr()=0;//funkcja, ktora ma zwraca numer klienta
    virtual int zyj()=0;//funkcja, ktora ma losowac czynnosc, ktora wykona klient
    virtual void zajmij()=0;//funkcja, ktora ma zmienic stan klienta na zajety
    virtual void zwolnij()=0;//funkcja, ktora ma zmienic stan klienta na wolny
    virtual bool stan()=0;//funkcja, ktora ma zwraca stan klienta
    };

class klient: public interklient
    {
public:
    klient(int n);
    virtual int nr();//funckja, ktora ma zwracac numer klienta
    virtual int zyj();//funckja, ktora losuje czynnosc, ktora wykona klient
    virtual void zajmij();//funckja, ktora zmienia stan klienta na zajety
    virtual void zwolnij();//funckja, ktora zmienia stan klienta na wolny
    virtual bool stan();//funckja, ktora zwraca stan klienta
    };



#endif
