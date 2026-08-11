#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;

    cout << "Enter a string of brackets: ";
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cout << "Invalid";
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                cout << "Invalid";
                return 0;
            }
        }
    }

    if (st.empty())
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}