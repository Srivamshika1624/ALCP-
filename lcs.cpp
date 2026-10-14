#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string get_lcs_string(const string& text1, const string& text2) {
    int m = text1.length();
    int n = text2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int i = m, j = n;
    string lcs_chars = "";
    
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs_chars += text1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(lcs_chars.begin(), lcs_chars.end());
    return lcs_chars;
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    
    string lcs = get_lcs_string(str1, str2);
    
    cout << "LCS String: " << lcs << endl;
    cout << "Length: " << lcs.length() << endl;
    
    return 0;
}