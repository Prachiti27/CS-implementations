#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string lcs(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
        }
    }

    string result;
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "ABCBDAB";
    string b = "BDCAB";

    string result = lcs(a, b);

    cout << "LCS: " << result << '\n';
    cout << "Length: " << result.size() << '\n';

    return 0;
}