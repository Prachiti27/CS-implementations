#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {
    if (n == 0)
        return;

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from "
         << source << " to " << destination << '\n';

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "Total moves: " << (1LL << n) - 1 << '\n';
    return 0;
}