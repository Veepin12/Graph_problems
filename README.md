# 🧬 Graph Algorithms & Representations in C++

🚀 A comprehensive repository of Graph data structures, traversal algorithms, and classical grid/pathfinding problems implemented from scratch in C++. This project serves as a structured reference guide for learning, implementing, and mastering Graph Theory and interview-style problems using C++.

---

## 📂 Repository Structure

```
Graph_problems/
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md      # Pull Request template for contributors
├── .gitignore                        # Git ignore configuration
├── README.md                         # Project documentation
│
├── 🔹 Graph Representations
│   ├── adjecency_list.cpp            # Unweighted Graph representation using Vector of Lists
│   ├── unweighted_adjecency_set.cpp  # Unweighted Graph representation using Vector of Sets
│   ├── weighted_adjecency_list.cpp    # Weighted Graph representation using Vector of List of Pairs
│   ├── weighted_adjecency_map.cpp     # Weighted Graph representation using Vector of Hash Maps
│   ├── graph_implemetation.cpp       # Object-Oriented Class-based node and edge design
│   └── referrel.cpp                  # Dynamic Adjacency List display & input handler
│
├── 🔹 Traversals & Pathfinding
│   ├── DFS.cpp                       # Depth-First Search for target reachability
│   ├── BFS_shortest_path.cpp         # Breadth-First Search for shortest paths on unweighted graphs
│   ├── all_path.cpp                  # Backtracking-based DFS to find all paths from Src to Dest
│   ├── connected_component.cpp       # Finding and counting components in undirected graphs
│   └── key_and_room.cpp              # Reachability graph traversal (LeetCode 841)
│
└── 🔹 Matrix & Grid Problems (Implicit Graphs)
    ├── NumberOfIsland.cpp            # Grid BFS to count connected components (LeetCode 200)
    ├── Rooting_Orange.cpp            # Multi-source BFS for rotten orange propagation (LeetCode 994)
    ├── floodfill.cpp                 # Area recoloring DFS/BFS (LeetCode 733)
    ├── flood.cpp                     # Alternate implementation of grid coloring
    ├── ColoringBordar.cpp            # Connected component border coloring (LeetCode 1034)
    ├── repalce_zero_with_1.cpp       # Boundary-connected component protection & replacement
    └── seminar.cpp                   # Interval scheduling / meeting room overlapping logic
```

---

## 🗺️ Algorithmic Catalog

Below is a detailed map of the implementations included in this repository.

| Implementation File | Core Concept / Category | Description | LeetCode / Platform Ref | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **📂 Representations** | | | | | |
| [graph_implemetation.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/graph_implemetation.cpp) | OOP Design | Class-based nodes & directed/undirected edge design. | Concept | $O(1)$ | $O(V + E)$ |
| [adjecency_list.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/adjecency_list.cpp) | Adjacency List | Standard graph representation using `std::vector<std::list<int>>`. | Concept | $O(V + E)$ | $O(V + E)$ |
| [unweighted_adjecency_set.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/unweighted_adjecency_set.cpp) | Adjacency Set | Graph representation using `std::vector<std::unordered_set<int>>` for $O(1)$ edge existence checks. | Concept | $O(V + E)$ | $O(V + E)$ |
| [weighted_adjecency_list.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/weighted_adjecency_list.cpp) | Weighted Adjacency List | Weighted graph representation using list of pairs `std::vector<std::list<std::pair<int, int>>>`. | Concept | $O(V + E)$ | $O(V + E)$ |
| [weighted_adjecency_map.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/weighted_adjecency_map.cpp) | Adjacency Map | Advanced graph representation using `std::vector<std::unordered_map<int, int>>` for weighted lookup. | Concept | $O(V + E)$ | $O(V + E)$ |
| [referrel.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/referrel.cpp) | Referral System | Adjacency List builder with formatted output utilities. | Concept | $O(V + E)$ | $O(V + E)$ |
| [center_node.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/center_node.cpp) | Graph Properties | Finding the center node in a star graph. | [LeetCode 1791](https://leetcode.com/problems/find-center-of-star-graph/) | $O(1)$ | $O(1)$ |
| [clone_graph.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/clone_graph.cpp) | Graph Copying | Creating a deep copy of an undirected graph. | [LeetCode 133](https://leetcode.com/problems/clone-graph/) | $O(V + E)$ | $O(V)$ |
| **🏃 Traversals & Pathfinding** | | | | | |
| [DFS.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/DFS.cpp) | DFS Traversal | Path check between source and target using recursive DFS. | Concept | $O(V + E)$ | $O(V)$ |
| [BFS_shortest_path.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/BFS_shortest_path.cpp) | BFS / Shortest Path | Finding single-source shortest path distances in an unweighted graph. | Concept | $O(V + E)$ | $O(V)$ |
| [all_path.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/all_path.cpp) | DFS Backtracking | Print all simple paths between a given source and destination. | [LeetCode 797](https://leetcode.com/problems/all-paths-from-source-to-target/) | $O(2^V \cdot V)$ | $O(V)$ |
| [connected_component.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/connected_component.cpp) | Graph Components | Finding the number of disconnected subgraphs / components. | [LeetCode 323](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | $O(V + E)$ | $O(V)$ |
| [key_and_room.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/key_and_room.cpp) | BFS Reachability | Determining if all rooms are visitable starting from room `0`. | [LeetCode 841](https://leetcode.com/problems/keys-and-rooms/) | $O(V + E)$ | $O(V)$ |
| **🏁 Grid/Matrix Problems** | | | | | |
| [NumberOfIsland.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/NumberOfIsland.cpp) | BFS on Grid | Finding the number of 4-directionally connected land components ('1's). | [LeetCode 200](https://leetcode.com/problems/number-of-islands/) | $O(R \cdot C)$ | $O(\min(R, C))$ |
| [Rooting_Orange.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/Rooting_Orange.cpp) | Multi-Source BFS | Finding the minimum time for rotting all oranges using queue boundaries. | [LeetCode 994](https://leetcode.com/problems/rotting-oranges/) | $O(R \cdot C)$ | $O(R \cdot C)$ |
| [floodfill.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/floodfill.cpp) | BFS/DFS Recoloring | Recolors connected regions matching original starting pixels. | [LeetCode 733](https://leetcode.com/problems/flood-fill/) | $O(R \cdot C)$ | $O(R \cdot C)$ |
| [flood.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/flood.cpp) | Area Coloring | Flood Fill variant for coordinate coloring. | [LeetCode 733](https://leetcode.com/problems/flood-fill/) | $O(R \cdot C)$ | $O(R \cdot C)$ |
| [ColoringBordar.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/ColoringBordar.cpp) | Component Border | Color only the outer boundary of a connected grid component. | [LeetCode 1034](https://leetcode.com/problems/coloring-a-border/) | $O(R \cdot C)$ | $O(R \cdot C)$ |
| [repalce_zero_with_1.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/repalce_zero_with_1.cpp) | Multi-Source Grid BFS | Captures and fills surrounded components starting from boundaries. | [LeetCode 130](https://leetcode.com/problems/surrounded-regions/) | $O(R \cdot C)$ | $O(R \cdot C)$ |
| [seminar.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/seminar.cpp) | Greedy / Intervals | Sorting and checking for scheduling overlaps in 1D matrix intervals. | [LeetCode 252](https://leetcode.com/problems/meeting-rooms/) | $O(N \log N)$ | $O(1)$ |

---

## 🛠️ Graph Representation Cheat Sheet

We implement several ways of storing graphs, each serving specific efficiency requirements:

1. **Adjacency List (`std::vector<std::list<int>>`)**
   - **Pros**: Space-efficient ($O(V + E)$), easy traversal of neighbors.
   - **Cons**: Checking if edge $(u, v)$ exists takes $O(\text{degree}(u))$.
2. **Adjacency Set (`std::vector<std::unordered_set<int>>`)**
   - **Pros**: $O(1)$ lookup to check if an edge exists.
   - **Cons**: Slightly higher memory overhead due to hash tables.
3. **Adjacency Map (`std::vector<std::unordered_map<int, int>>`)**
   - **Pros**: Perfect for weighted graphs requiring fast edge existence checks and weight lookups.
   - **Cons**: Higher constant factors.

---

## 🚀 How to Run the Code

### 📋 Prerequisites
Ensure you have a C++ compiler (`g++` or `clang++`) installed on your system supporting C++17 or later.

To check your compiler installation:
```bash
g++ --version
```

### 💻 Compilation & Execution

To compile and run any of the files, follow these steps:

1. **Compile the program:**
   ```bash
   g++ -std=c++17 <filename>.cpp -o <executable_name>
   ```
   *Example:*
   ```bash
   g++ -std=c++17 BFS_shortest_path.cpp -o bfs_shortest_path
   ```

2. **Run the compiled executable:**
   ```bash
   ./<executable_name>
   ```
   *Example:*
   ```bash
   ./bfs_shortest_path
   ```

### 📥 Example Input Format

For algorithms accepting dynamic inputs like [DFS.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/DFS.cpp) or [BFS_shortest_path.cpp](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/BFS_shortest_path.cpp), the input format is as follows:
```text
<number_of_vertices>
<number_of_edges>
<edge_1_source> <edge_1_destination>
<edge_2_source> <edge_2_destination>
...
<source_node_query> <destination_node_query>
```

---

## 🤝 Contributing

We welcome contributions! Whether you want to add a new graph representation, solve a new classic problem, or improve existing documentation/optimizations:

1. **Fork the Repository**.
2. **Check the Pull Request Template**: Read our [PR guidelines](file:///Users/veepinchaudhary8115/Documents/GitHub/Graph_problems/.github/PULL_REQUEST_TEMPLATE.md) to align on formatting.
3. **Create a Feature Branch**: `git checkout -b feature/awesome-algorithm`
4. **Commit your changes**: `git commit -m 'Add Dijkstra Algorithm implementation'`
5. **Push to the branch**: `git push origin feature/awesome-algorithm`
6. **Open a Pull Request** 🚀
