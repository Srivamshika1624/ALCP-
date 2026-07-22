#include <iostream>
using namespace std;

void sumAvg(int arr[], int n)
{
    int sum = 0;
    float avg;

    for (int i = 0; i < n; i++)
        sum = sum + arr[i];

    avg = (float)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sumAvg(arr, n);

    return 0;
}