#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    if (dp[target])
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}
