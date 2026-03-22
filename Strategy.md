# 1) Standardize your C++ toolkit (stop reinventing code structure)
Use one template and one set of go-to containers.

Arrays/strings: vector, string  
Hashing: unordered_map, unordered_set  
Stack/queue: stack, queue, deque  
Sorting: sort(v.begin(), v.end())  
Min/max heap: priority_queue<T, vector<T>, greater<T>>  
Traversals: recursion for DFS, queue for BFS  
Also keep a fixed skeleton you always write:  
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // helper functions here
};
int main(){} //outside of the solution class
```
(If LeetCode provides its own includes, adapt, but keep the structure.)
# 2) Learn 6 “implementation templates” and reuse them everywhere
Most Easy/Medium interview solutions are just these with different conditions.
```cpp
// 1) Frequency map
unordered_map<char,int> cnt;
for (char c : s) cnt[c]++;
//One common caution
//If you only want to check existence without creating keys, use count:
if (cnt.count(c)) {/* key exists */}
// 2) Two Sum / index map
unordered_map<int,int> pos;
for (int i=0;i<n;i++){
    int need = target - a[i];
    if (pos.count(need)) return {pos[need], i};
    pos[a[i]] = i;
}

// 3) Two pointers (shrink/expand)
int l=0;
for (int r=0;r<n;r++){
    // add a[r]
    while (l<=r && /*window invalid*/) {
        // remove a[l]
        l++;
    }
    // update answer
}

// 4) Prefix sum + hashmap (subarray sum)
unordered_map<long long,int> freq;
freq[0]=1;
long long sum=0;
for (int x: a){
    sum += x;
    // use freq[sum - k]
    freq[sum]++;
}

// 5) BFS
queue<int> q;
vector<int> dist(n, -1);
q.push(src); dist[src]=0;
while(!q.empty()){
    int u=q.front(); q.pop();
    for(int v: g[u]) if(dist[v]==-1){
        dist[v]=dist[u]+1;
        q.push(v);
    }
}

// 6) DFS recursion on tree
int dfs(TreeNode* node){
    if(!node) return 0;
    int L=dfs(node->left), R=dfs(node->right);
    return 1 + max(L,R);
}

```
1) frequency - count map- When to use it
anagrams (compare frequency maps)
finding first non-repeating char
checking duplicates
counting letters/digits/symbols


* q.front() returns a reference to the front element (you can read it).
* q.pop() only removes the front element and returns void.
* ```int u = q.pop(); // error: pop() returns void```
* correct version is:
  ```int u = q.front(); q.pop();```
Your job during interviews becomes: “Which template is this?” not “How do I code it from scratch?”

# 3) Do “micro-implementation drills” (this is what you’re missing)
Daily 20–30 minutes:

* Pick 1 template.
* Implement it from memory on a tiny prompt you create.
* Compile/run locally (or LeetCode) and test 3 cases.
Examples of drills:

* “Implement twoSum”
* “Implement isAnagram”
* “Implement validParentheses”
* “Implement sliding window max sum of size k”
* “Implement reverse linked list”
* “Implement BFS level order”
After ~10 repetitions, your speed and correctness jump.

# 4) A debugging checklist for C++ (prevents 80% of misses)
When your idea is right but code fails, it’s usually:

* off-by-one (< vs <=, loop bounds)
* not initializing (freq[0]=1, dist = -1)
* wrong types (use long long for sums)
* unordered_map pitfalls: prefer count() before reading; beware operator[] creates keys
* edge cases: empty input, size 1, duplicates, negative values
In interviews, after coding, do a 60-second mental test:

* smallest input
* one normal input
* edge input (duplicates/negative/empty)
# 5) Practice “write outline, then code” (prevents getting lost)
Before typing, write 4 bullets:

data structures used
loop structure
what you update each step
complexity
This keeps implementation aligned with idea.

For interviews, most Easy problems are variations of these. Master them deliberately:

# Arrays/Strings (most common)
frequency map (anagrams, duplicates)
two-sum family (hashmap)
two pointers (reverse, palindrome, remove duplicates)
sliding window (max sum subarray, longest substring with condition)
prefix sums (range sum, subarray sum equals k)
# Linked list
fast/slow pointer (cycle, middle)
reverse list
merge two lists
# Stack/Queue
valid parentheses
min stack / monotonic stack basics
# Trees
DFS traversals (pre/in/post)
BFS level order
recursion base cases
# Sorting + intervals
sort then merge intervals
sort then greedy select

Don’t move on until these feel “automatic”.
