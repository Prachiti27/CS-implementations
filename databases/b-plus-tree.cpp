#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ORDER = 4;

struct Node {
    bool isLeaf;
    vector<int> keys;
    vector<Node*> children;
    Node* next;

    Node(bool leaf) : isLeaf(leaf), next(nullptr) {}
};

class BPlusTree {
private:
    Node* root;

    void insertInternal(Node* node, int key,
                        Node* rightChild) {
        auto it = upper_bound(node->keys.begin(),
                              node->keys.end(), key);

        int pos = it - node->keys.begin();
        node->keys.insert(it, key);
        node->children.insert(
            node->children.begin() + pos + 1, rightChild);
    }

    void splitLeaf(Node* leaf, int& promoted, Node*& newLeaf) {
        newLeaf = new Node(true);

        int mid = (leaf->keys.size() + 1) / 2;

        newLeaf->keys.assign(
            leaf->keys.begin() + mid, leaf->keys.end());

        leaf->keys.erase(leaf->keys.begin() + mid,
                         leaf->keys.end());

        newLeaf->next = leaf->next;
        leaf->next = newLeaf;

        promoted = newLeaf->keys.front();
    }

    void insertRecursive(Node* node, int key,
                         int& promoted, Node*& newChild) {
        if (node->isLeaf) {
            auto it = lower_bound(node->keys.begin(),
                                  node->keys.end(), key);

            if (it != node->keys.end() && *it == key)
                return;

            node->keys.insert(it, key);

            if (node->keys.size() < ORDER)
                return;

            splitLeaf(node, promoted, newChild);
            return;
        }

        int idx = upper_bound(node->keys.begin(),
                              node->keys.end(), key)
                  - node->keys.begin();

        int childPromotion = 0;
        Node* childSplit = nullptr;

        insertRecursive(node->children[idx], key,
                        childPromotion, childSplit);

        if (!childSplit)
            return;

        node->keys.insert(node->keys.begin() + idx,
                          childPromotion);
        node->children.insert(node->children.begin() + idx + 1,
                              childSplit);

        if (node->keys.size() < ORDER)
            return;

        Node* right = new Node(false);
        int mid = node->keys.size() / 2;

        promoted = node->keys[mid];

        right->keys.assign(node->keys.begin() + mid + 1,
                           node->keys.end());

        right->children.assign(
            node->children.begin() + mid + 1,
            node->children.end());

        node->keys.resize(mid);
        node->children.resize(mid + 1);

        newChild = right;
    }

public:
    BPlusTree() {
        root = new Node(true);
    }

    void insert(int key) {
        int promoted = 0;
        Node* newChild = nullptr;

        insertRecursive(root, key, promoted, newChild);

        if (newChild) {
            Node* newRoot = new Node(false);
            newRoot->keys.push_back(promoted);
            newRoot->children.push_back(root);
            newRoot->children.push_back(newChild);
            root = newRoot;
        }
    }

    bool search(int key) const {
        Node* current = root;

        while (!current->isLeaf) {
            int idx = upper_bound(current->keys.begin(),
                                  current->keys.end(), key)
                      - current->keys.begin();
            current = current->children[idx];
        }

        return binary_search(current->keys.begin(),
                             current->keys.end(), key);
    }

    void display() const {
        Node* current = root;

        while (!current->isLeaf)
            current = current->children.front();

        cout << "Keys in sorted order: ";

        while (current) {
            for (int key : current->keys)
                cout << key << " ";
            current = current->next;
        }

        cout << '\n';
    }
};

int main() {
    BPlusTree tree;

    vector<int> keys = {10, 20, 5, 6, 12, 30, 7, 17};

    for (int key : keys)
        tree.insert(key);

    tree.display();

    cout << boolalpha;
    cout << "Search 12: " << tree.search(12) << '\n';
    cout << "Search 25: " << tree.search(25) << '\n';

    return 0;
}