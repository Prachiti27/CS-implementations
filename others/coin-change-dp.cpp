#include <iostream>
#include <vector>
using namespace std;

long long countWays(const vector<int>& coins, int amount) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int sum = coin; sum <= amount; sum++) {
            dp[sum] += dp[sum - coin];
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of combinations: "
         << countWays(coins, amount) << '\n';

    return 0;
}