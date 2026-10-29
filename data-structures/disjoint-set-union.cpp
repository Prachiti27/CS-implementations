#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (sz[rootX] < sz[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];

        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int componentSize(int x) {
        return sz[find(x)];
    }
};

int main() {
    DSU dsu(7);

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(5, 6);

    cout << boolalpha;

    cout << "0 and 2 connected: "
         << dsu.connected(0, 2) << '\n';

    cout << "0 and 4 connected: "
         << dsu.connected(0, 4) << '\n';

    dsu.unite(2, 4);

    cout << "0 and 4 connected after union: "
         << dsu.connected(0, 4) << '\n';

    cout << "Component size of 0: "
         << dsu.componentSize(0) << '\n';

    return 0;
}