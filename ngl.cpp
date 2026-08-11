#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    cout << "Next greater elements: ";

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}