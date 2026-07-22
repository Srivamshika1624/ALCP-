#include <iostream>
using namespace std;

void maxmin(int arr[], int n)
{
    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    cout << "Maximum element = " << max << endl;
    cout << "Minimum element = " << min;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    maxmin(arr, n);

    return 0;
}