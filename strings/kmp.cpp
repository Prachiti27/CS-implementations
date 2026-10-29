#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i] = ++len;
            i++;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

vector<int> KMPSearch(const string& text,
                      const string& pattern) {
    vector<int> positions;
    int n = text.size();
    int m = pattern.size();

    if (m == 0) {
        for (int i = 0; i <= n; i++)
            positions.push_back(i);
        return positions;
    }

    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return positions;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> result = KMPSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result)
        cout << index << " ";

    cout << '\n';
    return 0;
}