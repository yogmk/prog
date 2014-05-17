using namespace std;

# include <iostream>
# include <string>


class Base {

    private:
    string pvtS;

    protected:
    string protS;

    public:
    string pubS;

    public:
    Base() {}
    Base(string s) { this->pvtS = s; }
    ~Base() {}

    void BaseImpl() { cout << "from Base '" << pvtS << "'" << endl; }
};

/*
Base::Base(string s)
{
    this->pvtS = s;
}

void Base::BaseImpl()
{
    cout << "from Base '" << pvtS << "'" << endl;
}
*/
