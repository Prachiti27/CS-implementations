#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << '\n';
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

void huffmanCoding(string chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    generateCodes(pq.top(), "");
}

int main() {
    string chars = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCoding(chars, freq);

    return 0;
}