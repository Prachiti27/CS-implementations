#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void generateSubsets(int index, const vector<int>& arr,
                     vector<int>& current) {
    if (index == (int)arr.size()) {
        cout << "{ ";
        for (int x : current)
            cout << x << " ";
        cout << "}\n";
        return;
    }

    // Include the current element.
    current.push_back(arr[index]);
    generateSubsets(index + 1, arr, current);

    // Backtrack: remove the current element.
    current.pop_back();

    // Exclude the current element.
    generateSubsets(index + 1, arr, current);
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << '\n';

    vector<int> arr = {1, 2, 3};
    vector<int> current;

    cout << "\nSubsets:\n";
    generateSubsets(0, arr, current);

    return 0;
}