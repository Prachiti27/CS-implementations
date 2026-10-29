#include <iostream>
#include <vector>
using namespace std;

vector<int> greedyChange(int amount,
                         const vector<int>& coins) {
    vector<int> result;

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }

    if (amount != 0)
        result.clear(); // No exact solution found by greedy.

    return result;
}

int main() {
    int amount = 93;
    vector<int> coins = {50, 20, 10, 5, 2, 1};

    vector<int> result = greedyChange(amount, coins);

    if (result.empty() && amount != 0) {
        cout << "Greedy could not form the amount\n";
    } else {
        cout << "Selected denominations: ";
        for (int coin : result)
            cout << coin << " ";

        cout << "\nNumber of coins: " << result.size() << '\n';
    }

    return 0;
}