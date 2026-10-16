
#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
    int t;                      // Minimum degree
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> children;

public:
    BTreeNode(int degree, bool isLeaf)
        : t(degree), leaf(isLeaf) {}

    void traverse() {
        int i;
        for (i = 0; i < (int)keys.size(); i++) {
            if (!leaf)
                children[i]->traverse();

            cout << keys[i] << " ";
        }

        if (!leaf)
            children[i]->traverse();
    }

    BTreeNode* search(int key) {
        int i = 0;

        while (i < (int)keys.size() && key > keys[i])
            i++;

        if (i < (int)keys.size() && keys[i] == key)
            return this;

        if (leaf)
            return nullptr;

        return children[i]->search(key);
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(t, y->leaf);

        int median = y->keys[t - 1];

        // Move the last t-1 keys to the new node.
        for (int j = 0; j < t - 1; j++)
            z->keys.push_back(y->keys[j + t]);

        // Move the last t children if y is not a leaf.
        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->children.push_back(y->children[j + t]);

            y->children.resize(t);
        }

        y->keys.resize(t - 1);

        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, median);
    }

    void insertNonFull(int key) {
        int i = (int)keys.size() - 1;

        if (leaf) {
            keys.push_back(key);

            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }

            keys[i + 1] = key;
        } else {
            while (i >= 0 && keys[i] > key)
                i--;

            i++;

            // Split a full child before descending.
            if ((int)children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);

                if (keys[i] < key)
                    i++;
            }

            children[i]->insertNonFull(key);
        }
    }

    int findKey(int key) {
        int i = 0;

        while (i < (int)keys.size() && keys[i] < key)
            i++;

        return i;
    }

    void remove(int key) {
        int idx = findKey(key);

        if (idx < (int)keys.size() && keys[idx] == key) {
            if (leaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            if (leaf)
                return;

            bool lastChild = (idx == (int)keys.size());

            // Ensure the child has enough keys before descending.
            if ((int)children[idx]->keys.size() < t)
                fill(idx);

            if (lastChild && idx > (int)keys.size())
                children[idx - 1]->remove(key);
            else
                children[idx]->remove(key);
        }
    }

    void removeFromLeaf(int idx) {
        keys.erase(keys.begin() + idx);
    }

    void removeFromNonLeaf(int idx) {
        int key = keys[idx];

        if ((int)children[idx]->keys.size() >= t) {
            int pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred);
        } else if ((int)children[idx + 1]->keys.size() >= t) {
            int succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ);
        } else {
            merge(idx);
            children[idx]->remove(key);
        }
    }

    int getPred(int idx) {
        BTreeNode* cur = children[idx];

        while (!cur->leaf)
            cur = cur->children.back();

        return cur->keys.back();
    }

    int getSucc(int idx) {
        BTreeNode* cur = children[idx + 1];

        while (!cur->leaf)
            cur = cur->children[0];

        return cur->keys[0];
    }

    void fill(int idx) {
        if (idx > 0 &&
            (int)children[idx - 1]->keys.size() >= t) {
            borrowFromPrev(idx);
        } else if (idx < (int)keys.size() &&
                   (int)children[idx + 1]->keys.size() >= t) {
            borrowFromNext(idx);
        } else {
            if (idx < (int)keys.size())
                merge(idx);
            else
                merge(idx - 1);
        }
    }

    void borrowFromPrev(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];

        child->keys.insert(child->keys.begin(), keys[idx - 1]);

        if (!child->leaf) {
            child->children.insert(
                child->children.begin(), sibling->children.back());
            sibling->children.pop_back();
        }

        keys[idx - 1] = sibling->keys.back();
        sibling->keys.pop_back();
    }

    void borrowFromNext(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];

        child->keys.push_back(keys[idx]);

        if (!child->leaf) {
            child->children.push_back(sibling->children.front());
            sibling->children.erase(sibling->children.begin());
        }

        keys[idx] = sibling->keys.front();
        sibling->keys.erase(sibling->keys.begin());
    }

    void merge(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];

        child->keys.push_back(keys[idx]);

        for (int key : sibling->keys)
            child->keys.push_back(key);

        if (!child->leaf) {
            for (BTreeNode* ptr : sibling->children)
                child->children.push_back(ptr);
        }

        keys.erase(keys.begin() + idx);
        children.erase(children.begin() + idx + 1);

        // The sibling object is no longer part of the tree.
        delete sibling;
    }

    friend class BTree;
};

class BTree {
    BTreeNode* root;
    int t;

    void destroy(BTreeNode* node) {
        if (!node)
            return;

        for (BTreeNode* child : node->children)
            destroy(child);

        delete node;
    }

public:
    explicit BTree(int degree) : root(nullptr), t(degree) {
        if (degree < 2)
            throw invalid_argument("Minimum degree must be >= 2");
    }

    ~BTree() {
        destroy(root);
    }

    bool search(int key) {
        return root && root->search(key) != nullptr;
    }

    void traverse() {
        if (root)
            root->traverse();

        cout << '\n';
    }

    void insert(int key) {
        if (search(key))
            return; // Ignore duplicate keys.

        if (!root) {
            root = new BTreeNode(t, true);
            root->keys.push_back(key);
            return;
        }

        if ((int)root->keys.size() == 2 * t - 1) {
            BTreeNode* newRoot = new BTreeNode(t, false);

            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);

            int i = (newRoot->keys[0] < key) ? 1 : 0;
            newRoot->children[i]->insertNonFull(key);

            root = newRoot;
        } else {
            root->insertNonFull(key);
        }
    }

    void remove(int key) {
        if (!root || !search(key))
            return;

        root->remove(key);

        // Shrink the root if it becomes empty.
        if (root->keys.empty()) {
            BTreeNode* oldRoot = root;

            if (root->leaf)
                root = nullptr;
            else
                root = root->children[0];

            // Do not delete the promoted child.
            if (oldRoot->leaf)
                delete oldRoot;
            else {
                oldRoot->children.clear();
                delete oldRoot;
            }
        }
    }
};

int main() {
    BTree tree(3); // Minimum degree t = 3

    int values[] = {
        10, 20, 5, 6, 12, 30, 7, 17,
        3, 25, 40, 50, 60, 1, 2
    };

    for (int value : values)
        tree.insert(value);

    cout << "B-Tree traversal: ";
    tree.traverse();

    cout << "Search 12: "
         << (tree.search(12) ? "Found" : "Not found") << '\n';

    cout << "Search 99: "
         << (tree.search(99) ? "Found" : "Not found") << '\n';

    tree.remove(6);
    tree.remove(20);
    tree.remove(50);

    cout << "After deletion: ";
    tree.traverse();

    return 0;
}