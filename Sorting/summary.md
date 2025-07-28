# 🔢 Sorting Summary

---

## 🔢 **Basic Sorting Algorithms**

| Algorithm         | Time Complexity (Best / Avg / Worst) | Space | Stable | In-Place | Notes                                   |
|------------------|----------------------------------------|--------|--------|----------|-----------------------------------------|
| **Bubble Sort**   | O(n) / O(n²) / O(n²)                  | O(1)   | ✅     | ✅       | Repeatedly swaps adjacent elements      |
| **Selection Sort**| O(n²) / O(n²) / O(n²)                 | O(1)   | ❌     | ✅       | Always picks min and places it in front |
| **Insertion Sort**| O(n) / O(n²) / O(n²)                  | O(1)   | ✅     | ✅       | Good for nearly sorted arrays           |

---

## ⚡ **Efficient Sorting Algorithms**

| Algorithm        | Time Complexity (Best / Avg / Worst) | Space     | Stable | In-Place | Notes                                |
|------------------|----------------------------------------|-----------|--------|----------|--------------------------------------|
| **Merge Sort**    | O(n log n) / O(n log n) / O(n log n)  | O(n)      | ✅     | ❌       | Divide & conquer; good for Linked Lists |
| **Quick Sort**    | O(n log n) / O(n log n) / O(n²)       | O(log n)  | ❌     | ✅       | Fast, but bad pivot choice → O(n²)   |
| **Heap Sort**     | O(n log n) / O(n log n) / O(n log n)  | O(1)      | ❌     | ✅       | Based on binary heap                 |

---

## 🧠 **Non-Comparison Based Sorting**

| Algorithm         | Time Complexity (Best / Avg / Worst) | Space     | Stable | In-Place | Notes                               |
|-------------------|----------------------------------------|-----------|--------|----------|-------------------------------------|
| **Counting Sort**  | O(n + k) / O(n + k) / O(n + k)        | O(k)      | ✅     | ❌       | Works for small range integers      |
| **Radix Sort**     | O(nk) / O(nk) / O(nk)                 | O(n + k)  | ✅     | ❌       | k = number of digits                |
| **Bucket Sort**    | O(n + k) / O(n + k) / O(n²)           | O(n + k)  | ✅     | ❌       | Good for uniform distribution       |

---

## ✅ **When to Use What**

- **Nearly sorted array?** → Use **Insertion Sort**
- **Linked list?** → Use **Merge Sort**
- **Large dataset, fast average-case?** → Use **Quick Sort**
- **Need guaranteed O(n log n) and stable?** → Use **Merge Sort**
- **Sorting integers in known range?** → Use **Counting/Radix/Bucket Sort**
- **Heap operations needed (like priority queue)?** → Use **Heap Sort**

---

## 🔍 Stability & In-Place Meaning

- **Stable Sort**: Maintains relative order of equal elements.
- **In-Place**: Uses constant extra space (O(1)), modifies input array directly.

# Beginner Level – Basics & Implementation
| Problem                  | Concept                    | Platform         |
| ------------------------ | -------------------------- | ---------------- |
| Sort an Array            | Basic sorting (any method) | LeetCode \[#912] |
| Bubble Sort              | Manual implementation      | GFG              |
| Insertion Sort           | Manual implementation      | GFG              |
| Selection Sort           | Manual implementation      | GFG              |
| Check if Array is Sorted | Observation                | GFG              |


# Intermediate – Custom & Efficient Sorts
| Problem                   | Concept                               | Platform         |
| ------------------------- | ------------------------------------- | ---------------- |
| Merge Sort on Array       | Recursion + merge logic               | GFG              |
| Quick Sort                | Partition logic                       | GFG              |
| Count Inversions in Array | Merge Sort variant                    | GFG / LeetCode   |
| Sort Colors               | Dutch National Flag (3-way partition) | LeetCode \[#75]  |
| Meeting Rooms II          | Custom sorting with intervals         | LeetCode \[#253] |
| Minimum Platforms         | Sort + Greedy                         | GFG              |


# Advanced – Sorting + Extra Logic
| Problem                      | Concept            | Platform          |
| ---------------------------- | ------------------ | ----------------- |
| Largest Number               | Custom comparator  | LeetCode \[#179]  |
| Merge Intervals              | Sort + Merge logic | LeetCode \[#56]   |
| Relative Sort Array          | Counting + custom  | LeetCode \[#1122] |
| Top K Frequent Elements      | Heap + Map + Sort  | LeetCode \[#347]  |
| Sort Characters by Frequency | Map + Sort         | LeetCode \[#451]  |


# Expert – Non-Comparison Sorts & Applications
| Problem                         | Concept                     | Platform         |
| ------------------------------- | --------------------------- | ---------------- |
| Radix Sort (LSD/MSD)            | Digits-based sorting        | GFG              |
| Count Sort                      | Fixed-range elements        | GFG              |
| Bucket Sort on Floats           | Range division              | GFG              |
| Find All Anagrams               | Sorting with sliding window | LeetCode \[#438] |
| Minimum Number of Swaps to Sort | Cycles in graph + sorting   | GFG              |


# Bonus Challenges
| Problem                       | Concept             | Platform          |
| ----------------------------- | ------------------- | ----------------- |
| K-th Largest Element in Array | Heap + Quickselect  | LeetCode \[#215]  |
| Median in a Stream            | Two Heaps           | LeetCode \[#295]  |
| Sort a Linked List            | Merge Sort on LL    | LeetCode \[#148]  |
| Max Number of Events Attended | Sort + Greedy + Set | LeetCode \[#1353] |
