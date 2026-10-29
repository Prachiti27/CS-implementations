
<h1 align="center">String Algorithms</h1>

<p>
This folder contains implementations of fundamental techniques
for processing, analyzing, and manipulating character sequences.
</p>

<p>
The implementations explore string representation, sequence
comparison, pattern recognition, and the efficient processing
of textual data.
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
  <td><code>string-reversal.cpp</code></td>
  <td>
    String manipulation implementation supporting string reversal
    using the STL reverse algorithm and palindrome checking using
    two pointers from opposite ends of the string.
  </td>
  <td>
    Reverse: O(n)<br>
    Palindrome Check: O(n)
  </td>
  <td>O(n) auxiliary for reversal; O(1) for palindrome checking</td>
  <td>
    Strings, String Reversal, Palindrome, Two Pointers,
    STL Algorithms, String Manipulation
  </td>
</tr>

<tr>
  <td><code>naive-pattern-matching.cpp</code></td>
  <td>
    Naive string pattern matching algorithm that checks the pattern
    at every possible position in the text and returns all starting
    indices where the pattern occurs.
  </td>
  <td>
    Best Case: O(n)<br>
    Average Case: O(nm)<br>
    Worst Case: O(nm)
  </td>
  <td>O(k) auxiliary for storing k matches</td>
  <td>
    Pattern Matching, String Searching, Brute Force,
    Substring Search, Text Processing
  </td>
</tr>

<tr>
  <td><code>kmp.cpp</code></td>
  <td>
    Knuth-Morris-Pratt string matching algorithm using the
    Longest Proper Prefix which is also Suffix (LPS) array
    to avoid redundant character comparisons while searching
    for all pattern occurrences.
  </td>
  <td>
    LPS Construction: O(m)<br>
    Pattern Search: O(n)<br>
    Total: O(n + m)
  </td>
  <td>O(m + k) auxiliary, including LPS and k match indices</td>
  <td>
    KMP, String Matching, LPS Array, Prefix Function,
    Pattern Searching, Linear-Time Algorithms
  </td>
</tr>

<tr>
  <td><code>rabin-karp.cpp</code></td>
  <td>
    Rabin-Karp string searching algorithm that uses rolling hashes
    to compare a pattern against text windows, verifies matching
    hashes character by character, and returns all match positions.
  </td>
  <td>
    Average: O(n + m)<br>
    Worst Case: O(nm)<br>
    Hash Preprocessing: O(m)
  </td>
  <td>O(k) auxiliary for storing k matches</td>
  <td>
    Rabin-Karp, Rolling Hash, String Matching, Hashing,
    Substring Search, Pattern Searching
  </td>
</tr>
</tbody>
</table>