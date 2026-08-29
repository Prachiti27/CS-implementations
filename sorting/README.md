<h1 align="center">Sorting Algorithms</h1>

<p>
This folder contains implementations of classical sorting algorithms in C++.
The implementations demonstrate different sorting paradigms including
comparison-based sorting, divide and conquer, insertion-based sorting, and
heap-based sorting.
</p>

<p>
The algorithms are useful for understanding algorithmic complexity, recursion,
in-place operations, stability, and different approaches to ordering data.
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
      <td><code>bubble-sort.cpp</code></td>
      <td>
        Repeatedly compares adjacent elements and swaps them when they are in
        the wrong order.
      </td>
      <td>
        Best: O(n)<br>
        Average: O(n²)<br>
        Worst: O(n²)
      </td>
      <td>O(1)</td>
      <td>Comparison Sort, Swapping, Stable Sort</td>
    </tr>

    <tr>
      <td><code>heap-sort.cpp</code></td>
      <td>
        Builds a heap and repeatedly extracts the maximum or minimum element
        to produce the sorted sequence.
      </td>
      <td>
        Best: O(n log n)<br>
        Average: O(n log n)<br>
        Worst: O(n log n)
      </td>
      <td>O(1)</td>
      <td>Heap, Heapify, In-place Sorting</td>
    </tr>

    <tr>
      <td><code>insertion-sort.cpp</code></td>
      <td>
        Builds the sorted portion of the array one element at a time by
        inserting each element into its correct position.
      </td>
      <td>
        Best: O(n)<br>
        Average: O(n²)<br>
        Worst: O(n²)
      </td>
      <td>O(1)</td>
      <td>Insertion, Stable Sort, In-place</td>
    </tr>

    <tr>
      <td><code>merge-sort.cpp</code></td>
      <td>
        Divide-and-conquer sorting algorithm that recursively splits the array
        and merges the sorted halves.
      </td>
      <td>
        Best: O(n log n)<br>
        Average: O(n log n)<br>
        Worst: O(n log n)
      </td>
      <td>O(n)</td>
      <td>Divide and Conquer, Recursion, Merging</td>
    </tr>

    <tr>
      <td><code>quick-sort.cpp</code></td>
      <td>
        Selects a pivot and partitions the array around it, recursively sorting
        the resulting subarrays.
      </td>
      <td>
        Best: O(n log n)<br>
        Average: O(n log n)<br>
        Worst: O(n²)
      </td>
      <td>
        Average: O(log n)<br>
        Worst: O(n)
      </td>
      <td>Divide and Conquer, Pivot, Partitioning</td>
    </tr>

    <tr>
      <td><code>selection-sort.cpp</code></td>
      <td>
        Repeatedly selects the minimum element from the unsorted portion and
        places it at its correct position.
      </td>
      <td>
        Best: O(n²)<br>
        Average: O(n²)<br>
        Worst: O(n²)
      </td>
      <td>O(1)</td>
      <td>Selection, Comparison Sort, In-place</td>
    </tr>
  </tbody>
</table>

<hr>

<h2>Core Concepts</h2>

<ul>
  <li>Comparison-Based Sorting</li>
  <li>Stable vs Unstable Sorting</li>
  <li>In-place Sorting</li>
  <li>Divide and Conquer</li>
  <li>Recursion</li>
  <li>Partitioning</li>
  <li>Heap and Heapify</li>
  <li>Best, Average and Worst Case Complexity</li>
</ul>

<hr>

<h2>Complexity Comparison</h2>

<table>
  <thead>
    <tr>
      <th>Algorithm</th>
      <th>Best</th>
      <th>Average</th>
      <th>Worst</th>
      <th>Space</th>
    </tr>
  </thead>

  <tbody>
    <tr>
      <td>Bubble Sort</td>
      <td>O(n)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Selection Sort</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Insertion Sort</td>
      <td>O(n)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Merge Sort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n)</td>
    </tr>
    <tr>
      <td>Quick Sort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n²)</td>
      <td>O(log n)*</td>
    </tr>
    <tr>
      <td>Heap Sort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(1)</td>
    </tr>
  </tbody>
</table>

<p>
<small>
* Quick Sort uses O(log n) auxiliary stack space on average and can reach
O(n) in the worst case.
</small>
</p>