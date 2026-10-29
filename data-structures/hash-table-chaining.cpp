#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
private:
    int capacity;
    vector<list<pair<int, int>>> table;

    int hashFunction(int key) const {
        return (key % capacity + capacity) % capacity;
    }

public:
    HashTable(int size = 10) : capacity(size), table(size) {
        if (size <= 0)
            throw invalid_argument("Capacity must be positive");
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        for (auto& entry : table[index]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

    bool search(int key, int& value) const {
        int index = hashFunction(key);

        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }

        return false;
    }

    bool remove(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin();
             it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }

        return false;
    }

    void display() const {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";

            for (const auto& entry : table[i]) {
                cout << "(" << entry.first << ", "
                     << entry.second << ") -> ";
            }

            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10, 100);
    ht.insert(17, 200);
    ht.insert(24, 300);
    ht.insert(5, 500);

    cout << "Hash Table:\n";
    ht.display();

    int value;
    if (ht.search(17, value))
        cout << "Value for key 17: " << value << '\n';
    else
        cout << "Key not found\n";

    ht.remove(17);

    cout << "\nAfter deleting key 17:\n";
    ht.display();

    return 0;
}