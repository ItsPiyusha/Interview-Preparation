## 🧭 Binary Search Pattern Summary

### 🧠 What is Binary Search?

Efficient method to find elements or optimal values in a **sorted space**. Always halves the problem space.

---

### 🧩 1. Classic Binary Search

Find a target in a sorted array.

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

🔗 [LeetCode #704 – Binary Search](https://leetcode.com/problems/binary-search/)

---

### 🧩 2. First / Last Occurrence (With Duplicates)

```cpp
int firstOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            ans = mid;
            right = mid - 1; // look left
        } else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}
```

🔗 [LeetCode #34 – First and Last Position](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

---

### 🧩 3. Search Insert Position

Find where the target should be placed if not found.

```cpp
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}
```

🔗 [LeetCode #35 – Search Insert Position](https://leetcode.com/problems/search-insert-position/)

---

### 🧩 4. Search in Rotated Sorted Array

Use binary search in rotated sorted arrays.

```cpp
if (nums[left] <= nums[mid]) {
    if (nums[left] <= target && target < nums[mid])
        right = mid - 1;
    else
        left = mid + 1;
} else {
    if (nums[mid] < target && target <= nums[right])
        left = mid + 1;
    else
        right = mid - 1;
}
```

🔗 [LeetCode #33 – Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

---

### 🧩 5. Binary Search on Answer

Used when you're not searching in an array but trying to **minimize/maximize** a value.

```cpp
int left = 1, right = 1e9;
while (left <= right) {
    int mid = (left + right) / 2;
    if (check(mid)) right = mid - 1;
    else left = mid + 1;
}
return left;
```

🔗 [LeetCode #875 – Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas)
🔗 [GFG – Aggressive Cows](https://www.geeksforgeeks.org/aggressive-cows-puzzle/)

---

### 💡 How to Choose Pattern?

| Pattern          | When to Use                             |
| ---------------- | --------------------------------------- |
| Classic          | Sorted array, unique values             |
| First/Last       | Want leftmost or rightmost occurrence   |
| Insert Position  | Target not found? Find where it belongs |
| Rotated Array    | Sorted but rotated data                 |
| Search on Answer | Optimize value in range, not index      |

---

### 🧠 Pro Tip:

> If you can rephrase the question as a **yes/no check**, use Binary Search on Answer. 💪
