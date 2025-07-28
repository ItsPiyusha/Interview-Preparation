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
