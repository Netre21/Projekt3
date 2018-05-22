

#ifndef klient_hpp
#define klient_hpp
class customer
    {
    public:
    virtual int nr()=0;
    virtual int zyj()=0;
    virtual void zajmij()=0;
    virtual void zwolnij()=0;
    virtual bool stan()=0;
    };

class klient: public customer
    {
    int numer;
    bool zajety;
public:
    klient(int n);
    virtual int nr();
    virtual int zyj();
    virtual void zajmij();
    virtual void zwolnij();
    virtual bool stan();
    };



#endif
