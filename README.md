# DSA Lab Exam

A collection of C programs and their corresponding pseudocode for Data Structures and Algorithms (DSA) lab practice.

## Repository Structure

```
DSA-Lab-exam/
├── programs/
│   ├── 1_student_marks.c
│   ├── 2_stack_linked_list.c
│   ├── 3_dfs_adjacency_matrix.c
│   ├── 4_dfs_from_edges.c
│   ├── 5_patient_queue.c
│   └── 6_merge_linked_lists.c
│
└── pseudocodes/
    ├── 1_student_marks_pseudocode.txt
    ├── 2_stack_linked_list_pseudocode.txt
    ├── 3_dfs_adjacency_matrix_pseudocode.txt
    ├── 4_dfs_from_edges_pseudocode.txt
    ├── 5_patient_queue_pseudocode.txt
    ├── 6_merge_linked_lists_pseudocode.txt
    ├── 8_bfs_read_matrix_pseudocode.txt
    └── 9_bfs_read_edges_pseudocode.txt
```

## Programs Included

| No. | Program | Pseudocode: | Main Concept |
|---|---|---|---|
| 1 | [Student Marks](programs/1_student_marks.c) | [View pseudocode](pseudocodes/1_student_marks_pseudocode.txt) | Selection Sort and Linear Search |
| 2 | [Stack Using Linked List](programs/2_stack_linked_list.c) | [View pseudocode](pseudocodes/2_stack_linked_list_pseudocode.txt) | Stack operations |
| 3 | [DFS Using Adjacency Matrix](programs/3_dfs_adjacency_matrix.c) | [View pseudocode](pseudocodes/3_dfs_adjacency_matrix_pseudocode.txt) | Depth First Search |
| 4 | [DFS From Edges](programs/4_dfs_from_edges.c) | [View pseudocode](pseudocodes/4_dfs_from_edges_pseudocode.txt) | Graph representation and DFS |
| 5 | [Patient Queue](programs/5_patient_queue.c) | [View pseudocode](pseudocodes/5_patient_queue_pseudocode.txt) | Queue using Linked List |
| 6 | [Merge Linked Lists](programs/6_merge_linked_lists.c) | [View pseudocode](pseudocodes/6_merge_linked_lists_pseudocode.txt) | Merging two singly linked lists |
| 8 | [BFS Using Adjacency Matrix](programs/8_bfs_read_matrix.c) | [View pseudocode](pseudocodes/8_bfs_read_matrix_pseudocode.txt) | Breadth First Search using a queue |
| 9 | [BFS From Vertices and Edges](programs/9_bfs_read_edges.c) | [View pseudocode](pseudocodes/9_bfs_read_edges_pseudocode.txt) | Construct adjacency matrix and perform BFS |

## How to Compile and Run

You need a C compiler such as GCC.

1. Open a terminal in the repository folder.
2. Compile a program:

   ```bash
   gcc programs/1_student_marks.c -o student_marks
   ```

3. Run it:

   **Windows**
   ```bash
   .\\student_marks.exe
   ```

   **Linux / macOS**
   ```bash
   ./student_marks
   ```

Replace the source filename and output name to compile another program.

## Purpose

This repository is intended for DSA lab practice and revision. The `programs/` folder contains the C source files, while the `pseudocodes/` folder contains the corresponding algorithm steps.

---

**Language:** C  
**Subject:** Data Structures and Algorithms (DSA)
