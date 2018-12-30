#include <iostream>
#include <string.h>

using namespace std;

class baseDMA {
public:
    char * label;
    int rating;
public:
    baseDMA();
    baseDMA(char * L, int r);  // default arguments can only be assigned once
    baseDMA(const baseDMA & rs);
    baseDMA & operator=(const baseDMA & rs);
    virtual ~baseDMA(){delete []label; cout<<"base deconstructor"<<endl;};
    void display();
};

class hasDMA :public baseDMA {
public:
    char *style;
public:
    hasDMA();
    hasDMA(char *M, int m);
    hasDMA(const hasDMA & hs);
    hasDMA &operator=(const hasDMA & hs);
    ~hasDMA(){delete []style; cout<<"derived deconstructor"<<endl;}
    void display();
};
