
//# include "Base.h"
# include "Derived.h"

using namespace std;

int
main()
{
    string s("Hello Base"), s2("Hello Derived!");
    Base b (s);
    b.BaseImpl();

//    Derived d(s2);
//    d.DerivedImpl();

    Derived d2(b);
    d2.DerivedImpl();
    return 0;
}
