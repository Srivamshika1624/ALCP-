#include <iostream>
using namespace std;

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of rotations: ";
    cin >> k;

    k = k % n;

    for (int i = 0; i < k; i++) {
        int last = arr[n - 1];

        for (int j = n - 1; j > 0; j--)
            arr[j] = arr[j - 1];

        arr[0] = last;
    }

    cout << "Rotated array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}