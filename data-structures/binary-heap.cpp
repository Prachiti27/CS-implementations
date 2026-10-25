
#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    void insert(int val);
    int top();
    void pop();
    bool empty();
    void display();
};

void MaxHeap::insert(int val) {
    heap.push_back(val);
    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] >= heap[i]) break;

        swap(heap[parent], heap[i]);
        i = parent;
    }
}

int MaxHeap::top() {
    if (heap.empty()) return -1;
    return heap[0];
}

void MaxHeap::pop() {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();

    int i = 0, n = heap.size();

    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        swap(heap[i], heap[largest]);
        i = largest;
    }
}

bool MaxHeap::empty() {
    return heap.empty();
}

void MaxHeap::display() {
    for (int x : heap) cout << x << " ";
    cout << endl;
}


// MIN HEAP

class MinHeap {
    vector<int> heap;

public:
    void insert(int val);
    int top();
    void pop();
    bool empty();
    void display();
};

void MinHeap::insert(int val) {
    heap.push_back(val);
    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;

        swap(heap[parent], heap[i]);
        i = parent;
    }
}

int MinHeap::top() {
    if (heap.empty()) return -1;
    return heap[0];
}

void MinHeap::pop() {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();

    int i = 0, n = heap.size();

    while (true) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

bool MinHeap::empty() {
    return heap.empty();
}

void MinHeap::display() {
    for (int x : heap) cout << x << " ";
    cout << endl;
}


int main() {
    MaxHeap maxH;
    MinHeap minH;

    vector<int> values = {10, 30, 20, 5, 40};

    for (int x : values) {
        maxH.insert(x);
        minH.insert(x);
    }

    cout << "Max Heap: ";
    maxH.display();
    cout << "Maximum: " << maxH.top() << endl;

    maxH.pop();
    cout << "After removing maximum: ";
    maxH.display();

    cout << "\nMin Heap: ";
    minH.display();
    cout << "Minimum: " << minH.top() << endl;

    minH.pop();
    cout << "After removing minimum: ";
    minH.display();

    return 0;
}
