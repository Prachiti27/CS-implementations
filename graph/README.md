<h1 align="center">Graph Algorithms</h1>

<p>
This folder contains implementations of fundamental graph traversal,
shortest-path, minimum spanning tree, and directed graph algorithms in C++.
</p>

<p>
The implementations cover both traversal techniques such as BFS and DFS and
important algorithms such as Dijkstra, Bellman-Ford, Kruskal, Prim's and
Kahn's Algorithm.
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
      <td><code>a-star.cpp</code></td>
      <td>
        A* pathfinding algorithm that uses the actual distance from the source
        and a heuristic estimate to efficiently find a path to the destination.
      </td>
      <td>O(E log V) typical</td>
      <td>O(V)</td>
      <td>Heuristics, Priority Queue, Shortest Path</td>
    </tr>
    <tr>
      <td><code>bellman-ford.cpp</code></td>
      <td>
        Single-source shortest path algorithm capable of handling graphs with
        negative edge weights and detecting negative cycles.
      </td>
      <td>O(VE)</td>
      <td>O(V)</td>
      <td>Relaxation, Negative Weights, Negative Cycles</td>
    </tr>
    <tr>
      <td><code>bfs.cpp</code></td>
      <td>
        Breadth-First Search traverses a graph level by level using a queue.
        It can also be used to find shortest paths in unweighted graphs.
      </td>
      <td>O(V + E)</td>
      <td>O(V)</td>
      <td>Queue, Traversal, Unweighted Shortest Path</td>
    </tr>
    <tr>
      <td><code>dfs.cpp</code></td>
      <td>
        Depth-First Search explores a graph by going as deep as possible before
        backtracking.
      </td>
      <td>O(V + E)</td>
      <td>O(V)</td>
      <td>Recursion, Backtracking, Traversal</td>
    </tr>
    <tr>
      <td><code>dijkstra.cpp</code></td>
      <td>
        Single-source shortest path algorithm for graphs with non-negative
        edge weights, implemented using a priority queue.
      </td>
      <td>O((V + E) log V)</td>
      <td>O(V)</td>
      <td>Greedy Algorithm, Priority Queue, Relaxation</td>
    </tr>
    <tr>
      <td><code>iterative-dfs.cpp</code></td>
      <td>
        Iterative implementation of Depth-First Search using an explicit stack
        instead of recursive function calls.
      </td>
      <td>O(V + E)</td>
      <td>O(V)</td>
      <td>Stack, Graph Traversal</td>
    </tr>
    <tr>
      <td><code>kahns-algorithm.cpp</code></td>
      <td>
        Topological sorting algorithm for Directed Acyclic Graphs using
        indegree tracking and BFS-style processing.
      </td>
      <td>O(V + E)</td>
      <td>O(V)</td>
      <td>DAG, Topological Sort, Indegree</td>
    </tr>
    <tr>
      <td><code>kruskals.cpp</code></td>
      <td>
        Minimum Spanning Tree algorithm that sorts edges by weight and uses
        Disjoint Set Union to avoid cycles.
      </td>
      <td>O(E log E)</td>
      <td>O(V)</td>
      <td>MST, Greedy, DSU, Union-Find</td>
    </tr>
    <tr>
      <td><code>multi-src-bfs.cpp</code></td>
      <td>
        Multi-source BFS starts traversal simultaneously from multiple source
        vertices and is useful for distance propagation problems.
      </td>
      <td>O(V + E)</td>
      <td>O(V)</td>
      <td>BFS, Multiple Sources, Distance</td>
    </tr>
    <tr>
      <td><code>prims.cpp</code></td>
      <td>
        Minimum Spanning Tree algorithm that grows the spanning tree by
        repeatedly selecting the minimum-weight edge connecting a new vertex.
      </td>
      <td>O((V + E) log V)</td>
      <td>O(V)</td>
      <td>MST, Greedy, Priority Queue</td>
    </tr>
  </tbody>
</table>
<hr>
<h2>Core Concepts</h2>
<ul>
  <li>Graph Representation</li>
  <li>Adjacency List and Matrix</li>
  <li>BFS and DFS</li>
  <li>Shortest Path Algorithms</li>
  <li>Negative Edge Weights</li>
  <li>Topological Sorting</li>
  <li>Minimum Spanning Trees</li>
  <li>Disjoint Set Union</li>
  <li>Greedy Graph Algorithms</li>
  <li>Heuristic Search</li>
</ul>