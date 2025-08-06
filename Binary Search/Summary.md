## Sliding Window vs Two Pointer Approach

### ✨ 1. Key Differences

| Feature         | Sliding Window                          | Two Pointer                                          |
| --------------- | --------------------------------------- | ---------------------------------------------------- |
| Use Case        | Subarrays or substrings with conditions | Sorted arrays, or comparing two ends                 |
| Window Size     | Dynamic (grows/shrinks)                 | Often static or both pointers move toward each other |
| Data Structures | Often HashSet/HashMap                   | Often no extra space                                 |
| Direction       | Usually one expanding, one contracting  | Both pointers move based on logic                    |

---

### 🛠️ 2. Sliding Window Templates

#### ✅ Fixed Size Window

```cpp
// Find the maximum sum of a subarray of size k
int windowSum = 0;
int maxSum = 0;
for (int i = 0; i < s.size(); i++) {
    windowSum += s[i];
    if (i >= k - 1) {
        maxSum = max(maxSum, windowSum);
        windowSum -= s[i - k + 1];
    }
}
```

#### ✅ Variable Size Window

```cpp
// Longest substring without repeating characters
unordered_map<char, int> freq;
int left = 0;
for (int right = 0; right < s.size(); right++) {
    freq[s[right]]++;

    while (/* condition violated */) {
        freq[s[left]]--;
        left++;
    }
    // update max length or min window
}
```

---

### 🛠️ 3. Two Pointer Template

```cpp
// Find a pair with target sum in a sorted array
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
        // process the pair
    } else if (sum < target) {
        left++;
    } else {
        right--;
    }
}
```

---

### 🚀 4. Longest Substring Without Repeating Characters – All Approaches

#### 🔹 Brute Force

```cpp
// Check all substrings and verify if they have all unique characters
int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        unordered_set<char> seen;
        for (int j = i; j < s.size(); j++) {
            if (seen.count(s[j])) break;
            seen.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
```

#### 🔹 Better (Map + Index Tracking)

```cpp
// Track last seen positions using map to skip repeated characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, start = 0;
    for (int end = 0; end < s.length(); end++) {
        if (lastIndex.count(s[end])) {
            start = max(start, lastIndex[s[end]] + 1);
        }
        lastIndex[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
```

#### 🔹 Optimal Sliding Window (Set-Based)

```cpp
// Use set and two pointers to maintain a window of unique characters
int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.length()) {
        if (seen.count(s[right]) == 0) {
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            seen.erase(s[left]);
            left++;
        }
    }
    return maxLen;
}
```

---

### 📚 5. Must-Practice Problems

#### Sliding Window:

| Problem                                        | Type               | Link                                                                                        |
| ---------------------------------------------- | ------------------ | ------------------------------------------------------------------------------------------- |
| Longest Substring Without Repeating Characters | Variable window    | [LeetCode #3](https://leetcode.com/problems/longest-substring-without-repeating-characters) |
| Minimum Size Subarray Sum                      | Variable window    | [LeetCode #209](https://leetcode.com/problems/minimum-size-subarray-sum)                    |
| Maximum Sum Subarray of Size K                 | Fixed window       | [GFG](https://www.geeksforgeeks.org/window-sliding-technique/)                              |
| Permutation in String                          | Sliding + freq map | [LeetCode #567](https://leetcode.com/problems/permutation-in-string)                        |

#### Two Pointer:

| Problem                   | Type                        | Link                                                                            |
| ------------------------- | --------------------------- | ------------------------------------------------------------------------------- |
| Two Sum II                | Pair search in sorted array | [LeetCode #167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) |
| 3Sum                      | Triplet sum                 | [LeetCode #15](https://leetcode.com/problems/3sum)                              |
| Container With Most Water | Area optimization           | [LeetCode #11](https://leetcode.com/problems/container-with-most-water)         |
| Trapping Rain Water       | Hard, elevation map         | [LeetCode #42](https://leetcode.com/problems/trapping-rain-water)               |

---

### 🔍 Spot the Pattern:

* “Maximum/Minimum Subarray/Substrings” → Sliding Window
* “Pair or triplet in sorted array” → Two Pointer

---

### 🎯 Interview Tip:

“Since the array is sorted and I needed a pair that satisfies a condition, I used a two-pointer approach — one from the start and one from the end — to minimize unnecessary checks.”

---

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
