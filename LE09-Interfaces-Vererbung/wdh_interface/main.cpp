#include<vector>
#include<iostream>
class Interface {
    public:
    Interface( int y ) : x(y) {}
    virtual ~Interface() {}
    virtual void f() = 0;
    int x;
};

class Derived_A : public Interface {
    public:
    Derived_A( int y ) : Interface(y) {}
    void f(){ return; }
};

class Derived_B : public Interface {
    public:
    Derived_B( int y ) : Interface(y) {}
    void f(){ return; }
};


int main()
{
    std::vector<Interface*> abstractObjects;
    int N = 5;

    //zeiger nehmen! (aber am besten keine rohen sondern intelligente (unique)
    Derived_A* a = new Derived_A (1);
    abstractObjects.push_back(a);

 /*
    for(int ii = 0; ii < N; ii++ )
    {
        abstractObjects.push_back( new Derived_A(ii) );
        abstractObjects.push_back( new Derived_B(ii) );
    }

    for(int ii = 0; ii < abstractObjects.size(); ii++ )
    {
        abstractObjects[ii]->f();
        std::cout << abstractObjects[ii]->x << '\t' << std::endl;
    }


    for(int ii = 0; ii < abstractObjects.size(); ii++ )
    {
        delete abstractObjects[ii];
    }
*/
    return 0;
}
