<h1 align="center">Operating Systems</h1>

<p>
This folder contains implementations of fundamental Operating System
algorithms, with a focus on CPU scheduling and process scheduling concepts.
</p>

<p>
The implementations demonstrate how different scheduling policies determine
the order in which processes are selected for CPU execution.
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
      <td><code>fcfs.cpp</code></td>
      <td>
        First Come First Serve scheduling executes processes in the order in
        which they arrive in the ready queue.
      </td>
      <td>O(n)</td>
      <td>O(n)</td>
      <td>
        CPU Scheduling, Arrival Time, Burst Time,
        Waiting Time, Turnaround Time
      </td>
    </tr>
    <tr>
      <td><code>priority.cpp</code></td>
      <td>
        Priority Scheduling selects processes according to their assigned
        priority, allowing higher-priority processes to execute first.
      </td>
      <td>O(n log n) or O(n²)</td>
      <td>O(n)</td>
      <td>
        Priority Scheduling, Waiting Time,
        Turnaround Time, Starvation
      </td>
    </tr>
  </tbody>
</table>

<hr>

<h2>Core Concepts</h2>

<ul>
  <li>Process Scheduling</li>
  <li>Ready Queue</li>
  <li>Arrival Time</li>
  <li>Burst Time</li>
  <li>Completion Time</li>
  <li>Turnaround Time</li>
  <li>Waiting Time</li>
  <li>Response Time</li>
  <li>Scheduling Algorithms</li>
  <li>Starvation</li>
</ul>