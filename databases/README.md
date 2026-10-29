
<h1 align="center">Database Systems</h1>

<p>
This folder contains educational implementations of fundamental
database concepts related to data organization, storage,
indexing, and retrieval.
</p>

<p>
The implementations explore how database systems structure
information, organize access paths, and process operations
over stored data to support efficient data management.
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
    <td><code>b-tree.cpp</code></td>
    <td>
      B-Tree implementation supporting search, insertion, deletion, and
      sorted traversal using a self-balancing multiway search tree.
    </td>
    <td>
      Search: O(log n)<br>
      Insert: O(log n)<br>
      Delete: O(log n)<br>
      Traversal: O(n)
    </td>
    <td>O(n)</td>
    <td>B-Tree, Multiway Search Tree, Splitting, Merging, Balanced Tree</td>
  </tr>
<tr>
  <td><code>b-plus-tree.cpp</code></td>
  <td>Implements a B+ tree with insertion, key searching, internal-node splitting, linked leaf nodes, and sorted traversal of stored keys.</td>
  <td>Search: O(log n) average; Insert: O(log n) average; Display: O(n)</td>
  <td>O(n)</td>
  <td>B+ Tree, Balanced Search Tree, Multiway Tree, Database Indexing, Leaf Node Linking, Tree Splitting</td>
</tr>
  </tbody>
</table>