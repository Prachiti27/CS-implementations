
<h1 align="center">Mathematics</h1>

<p>
This folder contains implementations of fundamental mathematical
algorithms and concepts, with a focus on number theory, arithmetic,
and computational mathematics.
</p>

<p>
The implementations demonstrate how mathematical properties and
efficient algorithms can be used to solve computational problems.
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
      <td><code>gcd.cpp</code></td>
      <td>
        The Euclidean Algorithm computes the Greatest Common Divisor
        of two integers by repeatedly applying the modulo operation
        until the remainder becomes zero.
      </td>
      <td>O(log(min(a, b)))</td>
      <td>O(1) iterative</td>
      <td>
        Number Theory, GCD, Modulo Operation,
        Euclidean Algorithm, LCM
      </td>
    </tr>
    <tr>
      <td><code>sieve.cpp</code></td>
      <td>
        The Sieve of Eratosthenes efficiently finds all prime numbers up to a given limit by repeatedly marking the multiples of each prime number as non-prime.
      </td>
      <td>O(n log log n)</td>
      <td>O(n)</td>
      <td>
        Number Theory, Prime Numbers, Sieve of Eratosthenes,
        Prime Factorization, Mathematical Algorithms
      </td>
    </tr>
    <tr>
      <td><code>matrix_multiplication.cpp</code></td>
      <td>
      Multiplies two matrices by calculating the dot product
      of each row of the first matrix and each column of the
      second matrix. Multiplication is possible only when the
      number of columns in the first matrix equals the number
      of rows in the second matrix.
      </td>
      <td>O(r1 * c1 * c2)</td>
      <td>O(r1 * c2) for the result matrix</td>
      <td>
      Matrices, 2D Arrays, Nested Loops, Linear Algebra,
      Row-Column Dot Product
      </td>
    </tr>
  </tbody>
</table>

<hr>
