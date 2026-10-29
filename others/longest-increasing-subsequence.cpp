#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestIncreasingSubsequence(
    const vector<int>& arr) {
    int n = arr.size();

    if (n == 0)
        return {};

    vector<int> tails;
    vector<int> tailIndex;
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(tails.begin(), tails.end(),
                              arr[i]) - tails.begin();

        if (pos > 0)
            parent[i] = tailIndex[pos - 1];

        if (pos == (int)tails.size()) {
            tails.push_back(arr[i]);
            tailIndex.push_back(i);
        } else {
            tails[pos] = arr[i];
            tailIndex[pos] = i;
        }
    }

    vector<int> result;
    int index = tailIndex.back();

    while (index != -1) {
        result.push_back(arr[index]);
        index = parent[index];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> lis = longestIncreasingSubsequence(arr);

    cout << "LIS: ";
    for (int x : lis)
        cout << x << " ";

    cout << "\nLength: " << lis.size() << '\n';
    return 0;
}