using namespace std;

# include "Base.h"

class Derived: public Base
{
    private:
    string pvtS;

    protected:
    string protS;

    public:
    string pubS;

    public:
    Derived (Base b)   { ; }
    Derived (string s) { this->pvtS = s; }

    ~Derived() {}

    void DerivedImpl()
    {
        this->BaseImpl();
        cout <<"from Derived class '"<< pvtS << "'" <<endl;
    }
};
