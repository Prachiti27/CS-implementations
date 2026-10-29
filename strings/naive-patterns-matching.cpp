#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> naiveSearch(const string& text,
                        const string& pattern) {
    vector<int> positions;
    int n = text.size();
    int m = pattern.size();

    if (m == 0) {
        for (int i = 0; i <= n; i++)
            positions.push_back(i);
        return positions;
    }

    if (m > n)
        return positions;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j])
            j++;

        if (j == m)
            positions.push_back(i);
    }

    return positions;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> result = naiveSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result)
        cout << index << " ";

    cout << '\n';
    return 0;
}