#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1;

    vector<vector<int>> A(r1, vector<int>(c1));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cin >> r2 >> c2;
    vector<vector<int>> B(r2, vector<int>(c2));
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    if (c1 != r2) {
        cout << "Matrix multiplication not possible";
        return 0;
    }

    vector<vector<int>> C(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << '\n';
    }

    return 0;
}