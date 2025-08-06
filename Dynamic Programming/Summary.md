# 🧠 Dynamic Programming Patterns

Dynamic Programming (DP) involves solving problems by breaking them down into smaller subproblems, solving each once, and storing their results for reuse. Below are the key patterns with essential problems.

---

## 📌 1. **0/1 Knapsack Pattern**

Use when you have to **choose or not choose** each element, and you can't reuse items.

- **Key Decisions**: Pick or not pick
- **DP State**: `dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])`

**Problems:**
- [0/1 Knapsack](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- [Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)
- [Target Sum](https://leetcode.com/problems/target-sum/)
- [Count Subsets with Given Sum](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)

---

## 📌 2. **Unbounded Knapsack Pattern**

Items can be picked multiple times.

- **Key Difference**: Instead of `dp[i-1]`, we use `dp[i]` for repeated use.

**Problems:**
- [Coin Change (Min Coins)](https://leetcode.com/problems/coin-change/)
- [Coin Change II (Total Ways)](https://leetcode.com/problems/coin-change-ii/)
- [Rod Cutting](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)
- [Perfect Squares](https://leetcode.com/problems/perfect-squares/)

---

## 📌 3. **DP on Subsequences**

Used when we decide **to include or exclude** each element.

**Problems:**
- [Longest Common Subsequence (LCS)](https://leetcode.com/problems/longest-common-subsequence/)
- [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
- [Edit Distance](https://leetcode.com/problems/edit-distance/)
- [Shortest Common Supersequence](https://www.geeksforgeeks.org/shortest-common-supersequence/)

---

## 📌 4. **DP on Strings**

Character-based transitions, used for string matching or forming sequences.

**Problems:**
- [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)
- [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)
- [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
- [Minimum Insertions to Make String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

---

## 📌 5. **Partition DP**

Splitting the array or string into parts and solving them individually.

**Problems:**
- [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)
- [Burst Balloons](https://leetcode.com/problems/burst-balloons/)
- [Matrix Chain Multiplication](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)

---

## 📌 6. **DP on Grids**

Used when movement is limited (e.g., right/down) in a 2D grid.

**Problems:**
- [Unique Paths](https://leetcode.com/problems/unique-paths/)
- [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
- [Cherry Pickup II](https://leetcode.com/problems/cherry-pickup-ii/)
- [Gold Mine Problem](https://www.geeksforgeeks.org/gold-mine-problem/)

---

## 📌 7. **DP on Trees**

When recursive decisions are made on a tree structure.

**Problems:**
- [House Robber III](https://leetcode.com/problems/house-robber-iii/)
- [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
- [Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

---

## 📌 8. **Bitmask DP**

Use when you need to track subsets using bits.

**Problems:**
- [Count of Subsets with OR](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)
- [Travelling Salesman Problem (TSP)](https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/)

---

## 📌 9. **Memoization + Recursion**

Top-down approach with caching, ideal for problems where recursion leads to TLE.

**Problems:**
- [Fibonacci (Memoized)](https://leetcode.com/problems/fibonacci-number/)
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [Decode Ways](https://leetcode.com/problems/decode-ways/)

---

## 📌 10. **Tabulation (Bottom-Up)**

Iterative approach, often optimized for space.

**Problems:**
- [House Robber](https://leetcode.com/problems/house-robber/)
- [Max Sum Non-Adjacent](https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/)
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

---

## 📌 11. **State Compression DP**

Compress multi-dimensional DP states to 1D for optimization.

**Problems:**
- [Space Optimized LCS](https://leetcode.com/problems/longest-common-subsequence/)
- [Space Optimized Edit Distance](https://leetcode.com/problems/edit-distance/)

---

> 📝 Tip: Always define your DP state clearly. Decide:
> - What are your changing parameters (indices, remaining capacity, etc.)?
> - What is your base case?
> - What transitions are allowed?

