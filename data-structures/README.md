<h1 align="center">Data Structures</h1>

<p>
This folder contains implementations of fundamental and advanced data structures
from scratch in C++. The implementations focus on understanding the internal
working of each data structure rather than relying on the STL equivalents.
</p>

<p>
The collection covers linear data structures, linked lists, queues, hash-based
structures, heaps, and balanced search trees.
</p>

<hr>

<h2>Implementations</h2>

<table>
  <thead>
    <tr>
      <th>Implementation</th>
      <th>Description</th>
      <th>Time Complexity</th>
      <th>Space Complexity</th>
      <th>Key Concepts</th>
    </tr>
  </thead>

  <tbody>
    <tr>
      <td><code>avl-tree.cpp</code></td>
      <td>
        Self-balancing Binary Search Tree that maintains its height difference
        using rotations after insertions and deletions.
      </td>
      <td>
        Search: O(log n)<br>
        Insert: O(log n)<br>
        Delete: O(log n)
      </td>
      <td>O(n)</td>
      <td>BST, Height Balance, Rotations, Balancing</td>
    </tr>
    <tr>
      <td><code>binary-search-tree.cpp</code></td>
      <td>
        Binary Search Tree implementation supporting insertion, searching and
        tree traversal based on the BST ordering property.
      </td>
      <td>
        Average: O(log n)<br>
        Worst: O(n)
      </td>
      <td>O(n)</td>
      <td>BST Property, Recursion, Traversals</td>
    </tr>
    <tr>
      <td><code>circular-linked-list.cpp</code></td>
      <td>
        Linked list in which the last node points back to the first node,
        forming a circular structure.
      </td>
      <td>
        Traversal: O(n)<br>
        Search: O(n)<br>
        Insert: O(1) or O(n)<br>
        Delete: O(1) or O(n)
      </td>
      <td>O(n)</td>
      <td>Pointers, Circular Structure, Dynamic Memory</td>
    </tr>
    <tr>
      <td><code>circular-queue.cpp</code></td>
      <td>
        Queue implementation using a circular array where the rear wraps
        around to the beginning when space becomes available.
      </td>
      <td>
        Enqueue: O(1)<br>
        Dequeue: O(1)
      </td>
      <td>O(n)</td>
      <td>FIFO, Circular Buffer, Modulo Arithmetic</td>
    </tr>
    <tr>
      <td><code>deque.cpp</code></td>
      <td>
        Double-ended queue supporting insertion and deletion from both the
        front and rear.
      </td>
      <td>
        Insert Front: O(1)<br>
        Insert Rear: O(1)<br>
        Delete Front: O(1)<br>
        Delete Rear: O(1)
      </td>
      <td>O(n)</td>
      <td>Deque, FIFO, Double-ended Operations</td>
    </tr>
    <tr>
      <td><code>doubly-linked-list.cpp</code></td>
      <td>
        Linked list where every node maintains pointers to both its previous
        and next nodes.
      </td>
      <td>
        Traversal: O(n)<br>
        Search: O(n)<br>
        Insert/Delete: O(1) with node reference
      </td>
      <td>O(n)</td>
      <td>Bidirectional Traversal, Pointers, Dynamic Memory</td>
    </tr>
    <tr>
      <td><code>hash-map.cpp</code></td>
      <td>
        Hash-based key-value data structure that maps keys to values using a
        hashing function.
      </td>
      <td>
        Average Search/Insert/Delete: O(1)<br>
        Worst: O(n)
      </td>
      <td>O(n)</td>
      <td>Hashing, Key-Value Mapping, Collision Handling</td>
    </tr>
    <tr>
      <td><code>hash-table.cpp</code></td>
      <td>
        Hash table implementation that stores values using a hash function and
        handles collisions between keys.
      </td>
      <td>
        Average: O(1)<br>
        Worst: O(n)
      </td>
      <td>O(n)</td>
      <td>Hash Function, Collisions, Buckets</td>
    </tr>
    <tr>
      <td><code>priority-queue.cpp</code></td>
      <td>
        Priority queue implementation where elements are processed according
        to their priority rather than insertion order.
      </td>
      <td>
        Insert: O(log n)<br>
        Remove: O(log n)<br>
        Peek: O(1)
      </td>
      <td>O(n)</td>
      <td>Heap, Priority, Heapify</td>
    </tr>
    <tr>
      <td><code>queue.cpp</code></td>
      <td>
        FIFO queue implementation supporting insertion from the rear and
        deletion from the front.
      </td>
      <td>
        Enqueue: O(1)<br>
        Dequeue: O(1)
      </td>
      <td>O(n)</td>
      <td>FIFO, Front, Rear</td>
    </tr>
    <tr>
      <td><code>red-black-tree.cpp</code></td>
      <td>
        Self-balancing Binary Search Tree that uses node colors and rotations
        to maintain logarithmic height.
      </td>
      <td>
        Search: O(log n)<br>
        Insert: O(log n)<br>
        Delete: O(log n)
      </td>
      <td>O(n)</td>
      <td>BST, Rotations, Coloring, Balancing</td>
    </tr>
    <tr>
      <td><code>singly-linked-list.cpp</code></td>
      <td>
        Basic linked list where each node stores data and a pointer to the
        next node.
      </td>
      <td>
        Traversal: O(n)<br>
        Search: O(n)<br>
        Insert at Head: O(1)
      </td>
      <td>O(n)</td>
      <td>Pointers, Nodes, Dynamic Memory</td>
    </tr>
    <tr>
      <td><code>stack.cpp</code></td>
      <td>
        LIFO stack implementation supporting insertion and removal from the
        top of the stack.
      </td>
      <td>
        Push: O(1)<br>
        Pop: O(1)<br>
        Peek: O(1)
      </td>
      <td>O(n)</td>
      <td>LIFO, Stack, Top</td>
    </tr>
  </tbody>
</table>
<hr>
<h2>Core Concepts</h2>
<ul>
  <li>Linear vs Non-Linear Data Structures</li>
  <li>Linked Lists and Pointer Manipulation</li>
  <li>Stacks, Queues and Deques</li>
  <li>Hashing and Collision Resolution</li>
  <li>Binary Search Trees</li>
  <li>Self-Balancing Trees</li>
  <li>Tree Rotations</li>
  <li>Heap and Priority Queue</li>
  <li>Time and Space Complexity</li>
</ul>