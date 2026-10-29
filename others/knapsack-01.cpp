#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack01(int capacity, const vector<int>& weights,
               const vector<int>& values) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w],
                        values[i] + dp[w - weights[i]]);
        }
    }

    return dp[capacity];
}

int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int capacity = 7;

    cout << "Maximum value: "
         << knapsack01(capacity, weights, values) << '\n';

    return 0;
}