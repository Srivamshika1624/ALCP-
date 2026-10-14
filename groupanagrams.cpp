#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        anagramMap[key].push_back(str);
    }

    vector<vector<string>> result;

    for (const auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter " << n << " strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);

    cout << "Grouped Anagrams:" << endl;

    for (const auto& group : groupedAnagrams) {
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
