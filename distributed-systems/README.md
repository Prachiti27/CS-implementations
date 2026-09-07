<h1 align="center">Distributed Systems</h1>

<p>

This folder contains implementations of fundamental distributed systems
algorithms and components from scratch in C++. The implementations focus on
understanding the internal mechanisms behind distributed coordination,
consensus, communication, fault tolerance, and data distribution rather than
relying on existing distributed systems frameworks.

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
      <td><code>two-phase-commit.cpp</code></td>
      <td>
        Implementation of the Two-Phase Commit (2PC) distributed transaction
        protocol using a coordinator and multiple participants. The coordinator
        first asks participants to prepare and then broadcasts a global commit
        or abort decision based on their votes.
      </td>
      <td>
        Prepare Phase: O(n)<br>
        Commit/Abort Phase: O(n)<br>
        Overall: O(n)
      </td>
      <td>O(n)</td>
      <td>
        Distributed Transactions, Coordinator, Participants,
        Prepare Phase, Commit Phase, Atomicity
      </td>
    </tr>

  </tbody>

</table>

<hr>

<h2>Core Concepts</h2>

<ul>

  <li>Distributed Processes and Nodes</li>

  <li>Client-Server and Coordinator-Participant Models</li>

  <li>Inter-Process Communication</li>

  <li>Distributed Transactions</li>

  <li>Atomic Commit Protocols</li>

  <li>Two-Phase Commit (2PC)</li>

  <li>Consensus and Coordination</li>

  <li>Replication and Fault Tolerance</li>

  <li>Leader Election</li>

  <li>Distributed Locking</li>

  <li>Data Partitioning and Sharding</li>

  <li>Consistency Models</li>

  <li>Failure Detection and Recovery</li>

  <li>Distributed Logging</li>

  <li>Time, Ordering and Clocks</li>

  <li>Scalability and Fault Tolerance</li>

</ul>