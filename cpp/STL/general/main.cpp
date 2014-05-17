# include <vector>
# include <iostream>

int
main(void) {

using namespace std;

    vector<int> v;
    int l = [] (const string& s){ cout << s <<endl;};

    cout << "pushing elments <int>s on vector" << endl;

    for (int i=0; i <=10; i++)
        v.push_back(i);

    cout << "Forward iterator" << endl;
    vector<int>::const_iterator ci;
    for (ci=v.begin(); ci != v.end(); ci++)
        cout << *ci << ", ";

    cout << endl;
    cout << "reverse iterator" << endl;

    vector<int>::reverse_iterator ri;
    for (ri=v.rbegin(); ri != v.rend(); ri++)
       cout << *ri << ", ";

    //swap(*(v.begin()), *(v.end()));
    swap(v[0], v[v.size()]);
    cout << endl;
    for (ci=v.begin(); ci != v.end(); ci++)
        cout << *ci << ", ";

    v.clear(); cout <<v.size() <<endl;

    //auto l = [] (const string& s){ cout << s <<endl;};
    l("Hello Lambda");

    return 0;

}
