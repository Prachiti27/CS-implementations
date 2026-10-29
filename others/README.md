
<h1 align="center">Algorithm Design Techniques</h1>

<p>
This folder contains implementations of fundamental algorithm
design techniques used to develop systematic solutions to
computational problems.
</p>

<p>
The implementations explore recursive problem-solving, search
through solution spaces, greedy decision-making, dynamic
programming, and the decomposition of complex problems into
smaller subproblems.
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
          <td><code>recursion-backtracking.cpp</code></td>
          <td>Demonstrates recursive factorial calculation and backtracking-based subset generation.</td>
          <td>Factorial: O(n)<br>Subsets: O(n * 2^n)</td>
          <td>O(n) excluding output</td>
          <td>Recursion, Backtracking, Call Stack, Subsets</td>
        </tr>
        <tr>
          <td><code>tower-of-hanoi.cpp</code></td>
          <td>Solves the Tower of Hanoi puzzle by recursively moving disks between three rods.</td>
          <td>O(2^n)</td>
          <td>O(n)</td>
          <td>Recursion, Tower of Hanoi, Divide and Conquer</td>
        </tr>
        <tr>
          <td><code>n-queens.cpp</code></td>
          <td>Finds and prints all valid arrangements of N queens on an N x N chessboard using backtracking.</td>
          <td>O(N!) upper bound</td>
          <td>O(N^2) including board; O(N) recursion depth</td>
          <td>N-Queens, Backtracking, Constraint Satisfaction, Pruning</td>
        </tr>
        <tr>
          <td><code>rat-in-a-maze.cpp</code></td>
          <td>Finds all valid paths through a maze using depth-first search and backtracking.</td>
          <td>O(4^(N^2)) upper bound</td>
          <td>O(N^2 + L) including stored paths, where L is total output length</td>
          <td>Rat in a Maze, DFS, Backtracking, Path Finding</td>
        </tr>
        <tr>
          <td><code>greedy-method.cpp</code></td>
          <td>Demonstrates greedy coin selection by repeatedly choosing the largest available denomination.</td>
          <td>O(A + C), where A is the amount and C is the number of denominations</td>
          <td>O(A) for the selected coins</td>
          <td>Greedy Method, Local Optimum, Coin Selection</td>
        </tr>
        <tr>
          <td><code>fractional-knapsack.cpp</code></td>
          <td>Maximizes total value by selecting items in descending value-to-weight ratio, allowing fractional items.</td>
          <td>O(n log n)</td>
          <td>O(log n) auxiliary for sorting, excluding input</td>
          <td>Fractional Knapsack, Greedy Algorithm, Sorting, Optimization</td>
        </tr>
        <tr>
          <td><code>activity-selection.cpp</code></td>
          <td>Selects the maximum number of mutually non-overlapping activities by earliest finishing time.</td>
          <td>O(n log n)</td>
          <td>O(n) for selected activities, excluding sorting stack</td>
          <td>Activity Selection, Greedy Algorithm, Interval Scheduling</td>
        </tr>
        <tr>
          <td><code>knapsack-01-dp.cpp</code></td>
          <td>Finds the maximum total value within a capacity constraint when each item can be selected at most once.</td>
          <td>O(nW)</td>
          <td>O(W)</td>
          <td>0/1 Knapsack, Dynamic Programming, Space Optimization</td>
        </tr>
        <tr>
          <td><code>longest-common-subsequence.cpp</code></td>
          <td>Computes and reconstructs a longest common subsequence of two strings using a DP table.</td>
          <td>O(nm)</td>
          <td>O(nm)</td>
          <td>LCS, Dynamic Programming, Strings, Sequence Reconstruction</td>
        </tr>
        <tr>
          <td><code>matrix-chain-multiplication.cpp</code></td>
          <td>Finds the minimum scalar multiplication cost for multiplying a chain of matrices.</td>
          <td>O(n^3)</td>
          <td>O(n^2)</td>
          <td>Matrix Chain Multiplication, Dynamic Programming, Optimization</td>
        </tr>
        <tr>
          <td><code>coin-change-dp.cpp</code></td>
          <td>Counts the combinations for forming a target amount using unlimited coins of each denomination.</td>
          <td>O(CA)</td>
          <td>O(A)</td>
          <td>Coin Change, Dynamic Programming, Unbounded Knapsack, Combinatorics</td>
        </tr>
        <tr>
          <td><code>longest-increasing-subsequence.cpp</code></td>
          <td>Finds and reconstructs a longest strictly increasing subsequence using binary search and predecessor indices.</td>
          <td>O(n log n)</td>
          <td>O(n)</td>
          <td>LIS, Dynamic Programming, Binary Search, Sequence Reconstruction</td>
        </tr>
        <tr>
          <td><code>divide-and-conquer.cpp</code></td>
          <td>Implements merge sort by recursively sorting two halves and merging their sorted results.</td>
          <td>O(n log n)</td>
          <td>O(n) auxiliary array plus O(log n) recursion stack</td>
          <td>Divide and Conquer, Merge Sort, Recursion, Sorting</td>
        </tr>
      </tbody>
    </table>
