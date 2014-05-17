# include <iostream>

void dummyfoo() {}

# define knownAdd ((char*)1)

# define cpp_offsetof(t,m) \
(((char*) &((t*)knownAdd)->m) - knownAdd)


class Foo
{
    public:

    int intA;
    char charB;
    float floatC;
    virtual ~Foo() {};
};


int
main()
{
    Foo f;

    f.intA = 1, f.charB = 2, f.floatC = 3;

    int offB = cpp_offsetof(Foo, charB);

    char* pB = (char*)((char*) &f + offB);

    *pB=100;

    std::cout << *pB << std::endl;
    std::cout << "offsetof B=" << offB << std::endl;
     
    return 0;
}
