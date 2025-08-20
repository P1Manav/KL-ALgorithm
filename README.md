---

# 🖥️ Kernighan–Lin Graph Partitioning (C++)

## 📌 Overview

This project is a **C++ implementation of the Kernighan–Lin (KL) algorithm** for graph (or circuit) partitioning.
The main goal is to split a graph into **two balanced groups of nodes** while minimizing the number of edges that cross between the groups (called the **cut size**).

This is especially useful in **VLSI design**, **parallel computing**, and **clustering problems**, where reducing cross-connections improves performance and efficiency.

---

## ✨ Key Features

* Build a graph from user input (netlist of connections).
* Start with a random partition of nodes.
* Iteratively swap nodes to minimize the cut size.
* Display both the initial and optimized partitions.
* Works on **any undirected graph** provided by the user.

---

## 📖 How the Algorithm Works (Simplified)

1. **Input graph** → User provides the number of connections (edges) and their endpoints.
2. **Initial partition** → Nodes are split randomly into two equal groups.
3. **Cut size calculation** → Counts how many edges cross between the two groups.
4. **Optimization** → Nodes are swapped between groups if it reduces the cut size.
5. **Result** → Final optimized partition and cut size are shown.

---

## 🚀 How to Run

### 1. Compile the code:

```bash
g++ -std=c++17 -O2 -o kl_partition main.cpp
```

### 2. Run the program:

```bash
./kl_partition
```

### 3. Example input:

```
Enter the number of connections in the netlist: 4
Enter connections (e.g., '0 1' for a connection between gates 0 and 1):
0 1
0 2
1 3
2 3
```

### Example output:

```
Initial Cut Size: 2

Optimized Partition:
Group A: 0 3
Group B: 1 2
Final Cut Size: 1
```

---

## 📂 File Structure

```
main.cpp      # C++ source code implementing KL algorithm
README.md     # Project documentation
```

---

## 🧑‍🎓 Authors

* **Manav Prajapati** – CSE
* **Vivek Dhaamecha** – E\&I

This project is part of a practical implementation of the **Kernighan–Lin algorithm** for Course Physical Design using CMOS.

---
