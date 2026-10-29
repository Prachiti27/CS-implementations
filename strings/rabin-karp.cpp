#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> rabinKarp(const string& text,
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

    const long long base = 256;
    const long long mod = 1000000007;

    long long patternHash = 0;
    long long windowHash = 0;
    long long highestPower = 1;

    for (int i = 0; i < m - 1; i++)
        highestPower = highestPower * base % mod;

    for (int i = 0; i < m; i++) {
        patternHash =
            (patternHash * base + (unsigned char)pattern[i]) % mod;
        windowHash =
            (windowHash * base + (unsigned char)text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            // Verify characters to avoid hash-collision errors.
            if (text.compare(i, m, pattern) == 0)
                positions.push_back(i);
        }

        if (i < n - m) {
            windowHash =
                (windowHash -
                 (long long)(unsigned char)text[i] * highestPower % mod
                 + mod) % mod;

            windowHash =
                (windowHash * base +
                 (unsigned char)text[i + m]) % mod;
        }
    }

    return positions;
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result)
        cout << index << " ";

    cout << '\n';
    return 0;
}