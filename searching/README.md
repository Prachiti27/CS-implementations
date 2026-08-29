<h1 align="center">Searching Algorithms</h1>

<p>
This folder contains implementations of fundamental searching algorithms in
C++. The implementations demonstrate both straightforward sequential search
and efficient search on sorted data.
</p>

<p>
Searching algorithms are fundamental building blocks for understanding
algorithmic complexity and optimization.
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
      <td><code>linear-search.cpp</code></td>
      <td>
        Sequentially checks each element until the target value is found or
        the entire collection has been searched.
      </td>
      <td>
        Best: O(1)<br>
        Average: O(n)<br>
        Worst: O(n)
      </td>
      <td>O(1)</td>
      <td>Sequential Search, Arrays, Iteration</td>
    </tr>
    <tr>
      <td><code>binary-search.cpp</code></td>
      <td>
        Searches for an element in a sorted array by repeatedly dividing the
        search interval into two halves.
      </td>
      <td>
        Best: O(1)<br>
        Average: O(log n)<br>
        Worst: O(log n)
      </td>
      <td>O(1)</td>
      <td>Divide and Conquer, Sorted Arrays, Search Space</td>
    </tr>
  </tbody>
</table>

<hr>

<h2>Core Concepts</h2>

<ul>
  <li>Linear Search</li>
  <li>Binary Search</li>
  <li>Sorted Data</li>
  <li>Divide and Conquer</li>
  <li>Time Complexity</li>
  <li>Search Space Reduction</li>
</ul>