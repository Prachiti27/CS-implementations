#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long matrixChain(const vector<int>& dims) {
    int n = dims.size() - 1;

    if (n <= 1)
        return 0;

    vector<vector<long long>> dp(
        n + 1, vector<long long>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j]
                    + 1LL * dims[i - 1] * dims[k] * dims[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};

    cout << "Minimum multiplications: "
         << matrixChain(dimensions) << '\n';

    return 0;
}