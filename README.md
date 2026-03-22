* quick habit: whenever you use array for counting, always write array<int,26> cnt{}; (with {}) so you never forget initialization.
* size() vs length()
        * For **string**: .size() == .length()
        * For general containers: .size() exists, .length() usually doesn’t
        * Watch out for unsigned type (size_t) in comparisons and indexing
  ```cpp
  int n = s.size(); // possible warning: conversion from size_t to int
  ```
  Better:
  ```cpp
  size_t n = s.size();
  //or
  int n = (int)s.size();
  ```
# 0) General C++ skeleton (reuse every time)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // put helpers here
};
int main(){
return 0;
}
```
# 1) Frequency map (counts) — strings/arrays
**Use when:** anagrams, duplicates, “count occurrences”.
```cpp
unordered_map<char,int> cnt;
for (char c : s) cnt[c]++;

for (auto &p : cnt) {
    char ch = p.first;
    int freq = p.second;
}
```

[217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)  
[242. Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)  
[387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/description/)  
[383. Ransom Note](https://leetcode.com/problems/ransom-note/description/)  
[349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)    

## How to “detect” frequency-map problems quickly
If the problem asks about:
  
anagrams / permutations  
duplicates / unique  
“can we build string A from string B”  
first/non-repeating  
intersection counts  
…it’s almost always a counting problem.  
## 3 mini-templates
### 1) Count lowercase letters (fastest, simplest)
```cpp
array<int,26> cnt{};
for (char c : s) cnt[c - 'a']++;
```
### 2) Count general characters (ASCII)
```cpp
array<int,256> cnt{};
for (unsigned char c : s) cnt[c]++;
```
### 3) Count integers (array values)
```cpp
unordered_map<int,int> cnt;
for (int x : nums) cnt[x]++;
```
**note that arrays are initialised with {} but unordered_map need not.**
* array<int,N> cnt; → elements uninitialized → use cnt{} or fill(0)
* unordered_map<K,V> cnt; → starts empty → safe; counts become 0 when first inserted via cnt[key]
* Important nuance: unordered_map also has {} but it’s optional
```cpp
unordered_map<int,int> a;    // empty
unordered_map<int,int> b{};  // also empty
```
* in unordered_map, when we do ```cnt[x]++;``` operator[] does this:
       * if key x doesn’t exist, it inserts x with default value 0 (for int)
       * then increments it
# 2) Two Sum / complement map
**Use when:** “find pair with sum”, or need previous seen index.
```cpp
vector<int> twoSum(vector<int>& a, int target) {
    unordered_map<int,int> pos;
    for (int i = 0; i < (int)a.size(); i++) {
        int need = target - a[i];
        if (pos.count(need)) return {pos[need], i};
        pos[a[i]] = i;
    }
    return {};
}
```
[1.Two Sum](https://leetcode.com/problems/two-sum/)  
[217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)  
[219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)  
[242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)  
[409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)  
# 3) Two pointers (opposite ends)
**Use when:** sorted array, palindrome, reverse, pair sum in sorted.
```cpp
int l = 0, r = (int)a.size() - 1;
while (l < r) {
    // use a[l], a[r]
    if (/*move left*/) l++;
    else r--;
}
```
[Valid Palindrome (LeetCode 125))](https://leetcode.com/problems/valid-palindrome/)  
[Two Sum II – Input Array Is Sorted (LeetCode 167)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)  
[Reverse String (LeetCode 344)](https://leetcode.com/problems/reverse-string/)  
[Squares of a Sorted Array (LeetCode 977)](https://leetcode.com/problems/squares-of-a-sorted-array/)  
[Remove Duplicates from Sorted Array (LeetCode 26)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
# 4) Sliding window (expand r, shrink l)
**Use when:** longest/shortest subarray/substring satisfying condition.
```cpp
int l = 0;
for (int r = 0; r < n; r++) {
    // add a[r] to window

    while (l <= r && /*window invalid*/) {
        // remove a[l] from window
        l++;
    }

    // window [l..r] is valid here -> update answer
}
```
Common variant: “at most K” with frequency map:
```cpp
int atMostKDistinct(const vector<int>& a, int K) {
    unordered_map<int,int> cnt;
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < (int)a.size(); r++) {
        cnt[a[r]]++;
        while ((int)cnt.size() > K) {
            if (--cnt[a[l]] == 0) cnt.erase(a[l]);
            l++;
        }
        ans += (r - l + 1); // number of valid subarrays ending at r
    }
    return (int)ans;
}
```
[643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)  
Why it fits: fixed-size window k; expand r, once window size > k shrink l.  
Core pattern: maintain sum of current window.  
[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
Why it fits: r scans prices; l tracks best buy point; when prices[r] < prices[l], move l = r.  
Core pattern: maximize prices[r] - prices[l].  
[485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)  
Why it fits: simplest “window of 1s”; expand r; reset/shrink when you hit 0.  
Core pattern: count current streak / or use l reset.  
[1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)  
Why it fits: variable-size window with constraint “at most k zeros”; expand r, if zeros > k then shrink l.  
Core pattern: maintain zeroCount and enforce zeroCount <= k.  
[424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)  
Why it fits: variable window; expand r, track char frequencies; if replacements needed exceed k, shrink l.
Core pattern: keep maxFreq in window; valid if windowLen - maxFreq <= k.
# 5) Prefix sum (range sum fast)
**Use when:** many range sum queries, or subarray sums.
```cpp
vector<long long> pref(n+1, 0);
for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];

// sum of a[l..r]
auto rangeSum = [&](int l, int r) -> long long {
    return pref[r+1] - pref[l];
};
```
[303. Range Sum Query – Immutable](https://leetcode.com/problems/range-sum-query-immutable/)  
Why prefix sum fits: You precompute prefix[i] = sum(nums[0..i-1]), then any range sum is prefix[r+1] - prefix[l] in O(1).  
Pattern: Many queries on a fixed array.  
[1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)  
Why prefix sum fits: It literally asks you to compute prefix sums (running totals).  
Pattern: “Build prefix sums” in its simplest form.  
[724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)  
Why prefix sum fits: Total sum and a running prefix sum let you check leftSum == totalSum - leftSum - nums[i].  
Pattern: Compare left vs right sums efficiently.  
[1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)  
Why prefix sum fits: Altitude changes are deltas; prefix-summing deltas gives altitude at each point; track max.  
Pattern: Prefix sum over differences.  
[560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
Why prefix sum fits: Use prefix sums + hashmap counts: number of prior prefixes equal to currentPrefix - k.  
Pattern: Count subarrays with given sum (classic prefix sum + frequency map).  
# 6) Prefix sum + hashmap (subarray sum equals K)
**Use when:** count subarrays with given sum / 0-sum etc.
```cpp
int subarraySum(vector<int>& a, int k) {
    unordered_map<long long,int> freq;
    freq[0] = 1;
    long long sum = 0;
    int ans = 0;
    for (int x : a) {
        sum += x;
        if (freq.count(sum - k)) ans += freq[sum - k];
        freq[sum]++;
    }
    return ans;
}
```
[#1 Two Sum (Array + HashMap)](https://leetcode.com/problems/two-sum/)  
[#20 Valid Parentheses (Stack)](https://leetcode.com/problems/valid-parentheses/)  
[#21 Merge Two Sorted Lists (Linked List / Two pointers)](https://leetcode.com/problems/merge-two-sorted-lists/)  
[#121 Best Time to Buy and Sell Stock (Greedy / One pass)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
[#217 Contains Duplicate (HashSet)](https://leetcode.com/problems/contains-duplicate/)  
[#560 Prefix sum + hashmap (Subarray Sum Equals K)](https://leetcode.com/problems/subarray-sum-equals-k/)  

# 7) Sorting + greedy (intervals classic)
**Use when:** select non-overlapping, merge intervals, schedule.

Merge intervals:
```cpp
vector<vector<int>> merge(vector<vector<int>>& in) {
    sort(in.begin(), in.end());
    vector<vector<int>> out;
    for (auto &cur : in) {
        if (out.empty() || out.back()[1] < cur[0]) out.push_back(cur);
        else out.back()[1] = max(out.back()[1], cur[1]);
    }
    return out;
}
```
[56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)  
[252. Meeting Rooms (LeetCode Premium)](https://leetcode.com/problems/meeting-rooms/)  
[455. Assign Cookies](https://leetcode.com/problems/assign-cookies/)  
[860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)  
[605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)
  
# 8) Monotonic stack (next greater/smaller)
**Use when:** “next greater element”, “daily temperatures”, ranges.
```cpp
vector<int> nextGreater(const vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st; // indices, values decreasing
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```
[496 — Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)  
[1475 — Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)  
[682 — Baseball Game](https://leetcode.com/problems/baseball-game/)  
[503 — Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)  
[739 — Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)  

# 9) Heap / priority queue
**Use when:** “top K”, “kth largest”, “merge k sorted”.

Min-heap of size K (keep largest K):
```cpp
vector<int> topKLargest(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : a) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop();
    }
    vector<int> res;
    while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); }
    reverse(res.begin(), res.end());
    return res;
}
```
[703. Kth Largest Element in a Stream (Easy)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)  
[1046. Last Stone Weight (Easy)](https://leetcode.com/problems/last-stone-weight/)  
[506. Relative Ranks (Easy)](https://leetcode.com/problems/relative-ranks/)  
[1337. The K Weakest Rows in a Matrix (Easy)](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)  
[703. Kth Largest Element in a Stream (Easy) (alternate practice: same pattern, great for repetition)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)  

# 10) Binary search (classic)
**Use when:** sorted search, lower/upper bound.
```cpp
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] == x) return mid;
    else if (a[mid] < x) l = mid + 1;
    else r = mid - 1;
}
return -1;
```
704. Binary Search — https://leetcode.com/problems/binary-search/
35. Search Insert Position — https://leetcode.com/problems/search-insert-position/
69. Sqrt(x) — https://leetcode.com/problems/sqrtx/
278. First Bad Version — https://leetcode.com/problems/first-bad-version/
367. Valid Perfect Square — https://leetcode.com/problems/valid-perfect-square/
# 11) Binary search on answer + feasibility check
**Use when:** “minimize maximum”, “maximize minimum”, partitioning.
```cpp
bool can(const vector<int>& a, long long mid) {
    // return true if answer <= mid is feasible
    return true;
}

long long solve(const vector<int>& a) {
    long long lo = 0, hi = 1e18; // set proper bounds
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (can(a, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```
Key: can(mid) must be monotonic (true...true then false...false, or vice versa).
374. Guess Number Higher or Lower
Link: https://leetcode.com/problems/guess-number-higher-or-lower/

441. Arranging Coins
Link: https://leetcode.com/problems/arranging-coins/

69. Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/

367. Valid Perfect Square
Link: https://leetcode.com/problems/valid-perfect-square/

1608. Special Array With X Elements Greater Than or Equal X
Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

# 12) BFS (shortest path in unweighted graph / grid)
**Use when:** shortest steps, level order traversal, grid distance.
```cpp
int bfsGrid(vector<string>& g, int sr, int sc) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    while (!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        for (int k=0;k<4;k++){
            int nr=r+dr[k], nc=c+dc[k];
            if (nr<0||nr>=n||nc<0||nc>=m) continue;
            if (g[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});
        }
    }
    return 0;
}
```
LeetCode 733 — Flood Fill
Link: https://leetcode.com/problems/flood-fill/
Why it fits: Classic grid BFS/DFS; use BFS from (sr, sc) to recolor all 4-directionally connected cells of the same original color.
LeetCode 994 — Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges/
Why it fits: Multi-source BFS on a grid; push all rotten oranges initially and expand level-by-level to compute minutes (shortest time).
LeetCode 542 — 01 Matrix
Link: https://leetcode.com/problems/01-matrix/
Why it fits: Multi-source BFS; start from all 0 cells and compute shortest distance to a 0 for every 1.
LeetCode 1091 — Shortest Path in Binary Matrix
Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
Why it fits: Straight shortest path in an unweighted grid (8 directions); BFS from (0,0) to (n-1,n-1).
LeetCode 1926 — Nearest Exit from Entrance in Maze
Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
Why it fits: BFS from the entrance; first time you reach any boundary cell (other than entrance) is the shortest exit distance.
# 13) DFS recursion (tree)
**Use when:** tree properties: depth, sum, validate.
```cpp
// LeetCode TreeNode is assumed
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

Copilot said: 1) **104. Maximum Depth of Binary Tree**
104. Maximum Depth of Binary Tree
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
DFS recursion pattern: compute maxDepth(node) = 1 + max(depth(left), depth(right)).

100. Same Tree
Link: https://leetcode.com/problems/same-tree/
DFS recursion pattern: recursively verify both nodes match and their subtrees match.

101. Symmetric Tree
Link: https://leetcode.com/problems/symmetric-tree/
DFS recursion pattern: helper isMirror(a,b) comparing a.left with b.right and a.right with b.left.

112. Path Sum
Link: https://leetcode.com/problems/path-sum/
DFS recursion pattern: carry remaining sum down the tree; check leaf condition.

226. Invert Binary Tree
Link: https://leetcode.com/problems/invert-binary-tree/
DFS recursion pattern: recursively invert children, then swap left/right.

# 14) Backtracking (subsets/permutations)
**Use when:** generate all combinations with pruning.
```cpp
void dfs(int i, vector<int>& a, vector<int>& cur, vector<vector<int>>& out) {
    if (i == (int)a.size()) { out.push_back(cur); return; }
    dfs(i+1, a, cur, out);          // skip
    cur.push_back(a[i]);
    dfs(i+1, a, cur, out);          // take
    cur.pop_back();
}
```
#78 — Subsets
https://leetcode.com/problems/subsets/

#46 — Permutations
https://leetcode.com/problems/permutations/

#77 — Combinations
https://leetcode.com/problems/combinations/

#784 — Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/

#17 — Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

# 15) DP 1D (classic)
**Use when:** best up to i, choose/skip (house robber, etc.)
```cpp
int dpSolve(const vector<int>& a) {
    int n = a.size();
    vector<int> dp(n+1, 0);
    // dp[i] = answer for first i elements
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-1] + a[i-1]); // placeholder transition
    }
    return dp[n];
}
```
LeetCode #70 — Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

LeetCode #746 — Min Cost Climbing Stairs
https://leetcode.com/problems/min-cost-climbing-stairs/

LeetCode #198 — House Robber
https://leetcode.com/problems/house-robber/

LeetCode #1137 — N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/

LeetCode #392 — Is Subsequence
https://leetcode.com/problems/is-subsequence/
# 16) Union-Find (DSU) — connectivity
**Use when:** components, dynamic connections.
```cpp
struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};
```
LeetCode 1971 — Find if Path Exists in Graph
https://leetcode.com/problems/find-if-path-exists-in-graph/

LeetCode 547 — Number of Provinces
https://leetcode.com/problems/number-of-provinces/

LeetCode 323 — Number of Connected Components in an Undirected Graph (Premium)
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

LeetCode 684 — Redundant Connection
https://leetcode.com/problems/redundant-connection/

LeetCode 305 — Number of Islands II (Premium)
https://leetcode.com/problems/number-of-islands-ii/
