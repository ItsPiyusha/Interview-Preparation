# 🌳 Tree Patterns Summary – DSA

Mastering Trees is essential for coding interviews. Below is a list of common **patterns**, their use-cases, and **practice problems** to strengthen your skills.

---

## 1. Binary Tree Traversals

### 🌐 Pattern: DFS (Preorder, Inorder, Postorder)
- Recursive or Iterative traversal of tree.
- Used for reconstructing trees or solving substructure problems.

**Problems:**
- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
- [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

---

### 🌀 Pattern: BFS (Level Order Traversal)
- Traverse level by level using a queue.
- Good for shortest path or structure-related problems.

**Problems:**
- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

---

## 2. Construct Tree from Traversals

### 🔧 Pattern: Build Tree from Inorder + Pre/Postorder
- Use recursion with indices.
- Find root and divide into left/right subtrees.

**Problems:**
- [Construct Binary Tree from Inorder and Preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [Construct Binary Tree from Inorder and Postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

---

## 3. Diameter / Height / Depth

### 📏 Pattern: Postorder DFS to calculate height
- Combine height info from subtrees and track max diameter.

**Problems:**
- [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

---

## 4. Path-Related Problems

### 🛤️ Pattern: Recursively explore all paths
- DFS or backtracking
- Keep track of path sum or path list

**Problems:**
- [Path Sum](https://leetcode.com/problems/path-sum/)
- [Path Sum II](https://leetcode.com/problems/path-sum-ii/)
- [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

---

## 5. Lowest Common Ancestor (LCA)

### 🧬 Pattern: Postorder Recursion
- Check both subtrees for presence of nodes.

**Problems:**
- [Lowest Common Ancestor of Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [Lowest Common Ancestor in BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

---

## 6. Symmetry and Identical Trees

### 🔄 Pattern: Recursively compare subtrees
- Mirror left/right or exact match.

**Problems:**
- [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
- [Same Tree](https://leetcode.com/problems/same-tree/)

---

## 7. Tree to Linked List / Flatten

### 🧹 Pattern: Modify pointers during traversal
- Use right pointers and nullify left pointers.

**Problems:**
- [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

---

## 8. Binary Search Tree (BST) Specific Patterns

### 🌲 BST Traversal or Properties
- Use BST property: left < root < right

**Problems:**
- [Validate BST](https://leetcode.com/problems/validate-binary-search-tree/)
- [Kth Smallest Element in BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)

---

## 9. Serialize and Deserialize Tree

### 🧩 Pattern: Use Preorder with Null Markers
- Maintain structure with DFS + markers or BFS with queue.

**Problems:**
- [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

---

## 10. Tree Views

### 👀 Pattern: Level Order with Index Tracking
- Use BFS to track leftmost/rightmost at each level.

**Problems:**
- [Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [Left View of Binary Tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)
- [Top View of Binary Tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
- [Bottom View of Binary Tree](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

---

## 🧠 Tips

- Use recursion for cleaner DFS-based solutions.
- Use queues for level-order traversal.
- Trace every recursive call on paper for clarity.
- Know the difference between tree vs BST patterns.

---
