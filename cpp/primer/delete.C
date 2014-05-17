# include <iostream>

class Oject {
    public:
     int a;
     char s[100];
    public:
	 Oject (const char*);
     const char* foo();
     Oject& operator=(const char *s);
};

using namespace std;

void
bar (const Oject& obj)
{
    cout << obj.a << endl;
    cout << obj.s << endl;

}

int
main (void)
{

    cout << "main" << endl;
    Oject o("Hello C++");
    bar ( (Oject(o.foo()) ));
    Oject ob1 = o.foo();
    bar ( ob1 );

    return 0;
}
