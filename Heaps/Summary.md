# 🌳 Binary Search Tree (BST) Patterns - DSA Prep

A **Binary Search Tree (BST)** is a binary tree where the left subtree contains only nodes with values **less than the node’s value**, and the right subtree contains only nodes with values **greater than the node’s value**.

Understanding common problem patterns in BST helps in solving a wide variety of coding interview problems.

---

## 🧠 Key Patterns in BST Problems

---

### 1. **Search & Insert in BST**
- Recursively or iteratively move left/right based on value comparison.
- Problems:
  - 🔗 [Search in a BST](https://leetcode.com/problems/search-in-a-binary-search-tree/)
  - 🔗 [Insert into a BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

---

### 2. **Delete in BST**
- Handle 3 cases: node has no child, one child, or two children.
- Problems:
  - 🔗 [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)

---

### 3. **Validate a BST**
- Use inorder traversal or recursive min-max bounds.
- Problems:
  - 🔗 [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

---

### 4. **BST Traversals with Properties**
- Inorder of BST is always sorted.
- Problems:
  - 🔗 [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
  - 🔗 [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)

---

### 5. **Lowest Common Ancestor (LCA) in BST**
- Use BST properties to go left or right.
- Problems:
  - 🔗 [Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

---

### 6. **Recover or Fix a Corrupted BST**
- Two nodes are swapped; fix using inorder traversal.
- Problems:
  - 🔗 [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

---

### 7. **Build BST from Sorted Data**
- Use divide and conquer to maintain balance.
- Problems:
  - 🔗 [Convert Sorted Array to BST](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
  - 🔗 [Convert Sorted List to BST](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

---

### 8. **Inorder Successor/Predecessor**
- Use BST traversal or Morris traversal.
- Problems:
  - 🔗 [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/)
  - 🔗 [Inorder Predecessor and Successor](https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1)

---

### 9. **Range Problems in BST**
- Use BST bounds to prune traversal.
- Problems:
  - 🔗 [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
  - 🔗 [Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/)

---

### 10. **Flatten BST to Sorted List**
- Do inorder traversal and relink nodes.
- Problems:
  - 🔗 [Flatten BST to Sorted List](https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/)

---

## ✨ Tips:
- Inorder traversal gives sorted order in BST.
- BSTs are naturally recursive due to their tree structure.
- Use BST properties to optimize problems over brute force.

---

