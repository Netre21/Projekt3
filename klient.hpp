

#ifndef klient_hpp
#define klient_hpp
class klient
    {
    int numer;
    bool zajety;
public:
    klient(int n);
    int nr();
    int zyj();
    void zajmij();
    void zwolnij();
    bool stan();
    };



#endif
