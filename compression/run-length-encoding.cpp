#include <iostream>
#include <string>
using namespace std;

string runLengthEncode(const string& s) {
    string result;
    int n = s.size();

    for (int i = 0; i < n; ) {
        char current = s[i];
        int count = 0;

        while (i < n && s[i] == current) {
            count++;
            i++;
        }

        result += current;
        result += to_string(count);
    }

    return result;
}

int main() {
    string s = "aaabbccccdaa";

    cout << "Original string: " << s << '\n';
    cout << "Encoded string: " << runLengthEncode(s) << '\n';

    return 0;
}