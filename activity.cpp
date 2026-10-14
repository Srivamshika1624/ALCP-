#include <iostream>
#include <algorithm>
using namespace std;

class Activity {
public:
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[n];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].finish;

    sort(a, a + n, compare);

    cout << "\nSelected activities:\n";

    int count = 1;
    int finish = a[0].finish;

    cout << "(" << a[0].start << ", " << a[0].finish << ") ";

    for (int i = 1; i < n; i++) {
        if (a[i].start >= finish) {
            cout << "(" << a[i].start << ", " << a[i].finish << ") ";
            finish = a[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;

    return 0;
}
