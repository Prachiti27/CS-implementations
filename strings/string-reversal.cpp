#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

bool isPalindrome(const string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main() {
    string s = "madam";

    cout << "Original string: " << s << '\n';
    cout << "Reversed string: " << reverseString(s) << '\n';
    cout << "Is palindrome: " << boolalpha
         << isPalindrome(s) << '\n';

    return 0;
}