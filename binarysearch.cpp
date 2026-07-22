#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (x == arr[mid])
        return mid;

    else if (x > arr[mid])
        return binarySearch(arr, x, mid + 1, high);

    else
        return binarySearch(arr, x, low, mid - 1);
}

int main()
{
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> x;

    int pos = binarySearch(arr, x, 0, n - 1);

    if (pos == -1)
        cout << "Element Not Found";
    else
        cout << "Element Found at position " << pos + 1;

    return 0;
}