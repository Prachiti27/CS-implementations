#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

double fractionalKnapsack(double capacity,
                          vector<Item>& items) {
    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b) {
             return a.value / a.weight >
                    b.value / b.weight;
         });

    double totalValue = 0;

    for (const Item& item : items) {
        if (capacity <= 0)
            break;

        double taken = min(capacity, item.weight);
        totalValue += taken * item.value / item.weight;
        capacity -= taken;
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };

    cout << "Maximum value: "
         << fractionalKnapsack(50, items) << '\n';

    return 0;
}