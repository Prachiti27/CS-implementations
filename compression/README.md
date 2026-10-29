
<h1 align="center">Data Compression</h1>

<p>
This folder contains implementations of fundamental data
compression techniques used to represent information with
fewer bits or bytes.
</p>

<p>
The implementations explore redundancy in data, encoding
strategies, and the relationship between representation size,
compression efficiency, and the preservation of information.
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
    <td><code>huffman-coding.cpp</code></td>
    <td>
        Lossless data compression algorithm that assigns variable-length binary codes to characters based on their frequencies using a min-heap and
    a binary tree.
    </td>
    <td>
        Build Tree: O(n log n)<br>
        Generate Codes: O(n)<br>
        Encode: O(n)
    </td>
    <td>O(n)</td>
    <td>Greedy, Min-Heap, Binary Tree, Data Compression, Prefix Codes</td>
    </tr>
<tr>
  <td><code>run-length-encoding.cpp</code></td>
  <td>Implements Run-Length Encoding (RLE) to compress strings by replacing consecutive repeated characters with the character followed by its frequency.</td>
  <td>O(n)</td>
  <td>O(n)</td>
  <td>Run-Length Encoding, String Compression, Strings, Two Pointers, Data Compression</td>
</tr>
  </tbody>
</table>