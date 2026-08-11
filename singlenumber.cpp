#include <iostream>
using namespace std;

int main() {
    int n, result = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        result = result ^ arr[i];
    }

    cout << "Single number: " << result;

    return 0;
}