# include <iostream>
# include "Tokeniser.h"

using namespace std;
using namespace bnym;

int 
main(){
  string a(" hello world");
  Tokeniser next(a);           // Tokenize the string a
  string token;                // Will receive each token

  cout << "string before tokenising: " << a << endl;

  // Advance until the null string is returned:
  while (!(token=next()).empty())
    cout << token << endl;

  cout << "string after tokenising: " << a << endl;
  return 0;
}
