#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter window size: ";
    cin >> k;

    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() <= i - k)
            dq.pop_front();

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    cout << "Sliding window maximums: ";

    for (int x : result)
        cout << x << " ";

    return 0;
}