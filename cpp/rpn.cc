# include <iostream>
# include <vector>
# include <string>
# include <stdexcept>
# include <stdlib.h>

using namespace std;

int pop(vector<int>& stk);

int
main(void)
{
    vector<int> opStack;
    string token;
    int lhs, rhs;

    while (cin >> token) {
        if (isdigit(token[0])) {         // it's a number.
            opStack.push_back (atoi(token.c_str()));
        }
        else {         // it's an operand.
            switch (token[0]) {
                case '+': opStack.push_back (pop(opStack) + pop(opStack));
                          break;

                case '-': rhs = pop(opStack);
                          lhs = pop(opStack);
                          opStack.push_back (lhs-rhs);
                          break;

                case '*': opStack.push_back (pop(opStack) * pop(opStack));
                          break;

                case '/': rhs = pop(opStack);
                          lhs = pop(opStack);
                          opStack.push_back (lhs/rhs);
                          break;

                default: throw domain_error ("undefined operator");
            }
            cout << "Result: "<< opStack.back() << endl;
        }
    }
    return 0;
}

int
pop(vector<int>& stk)
{
    if (stk.empty()) throw underflow_error ("stack underflow");

    int result = stk.back();
    stk.pop_back();
    return result;
}
 
