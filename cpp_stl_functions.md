# C++ STL Interview Cheat Sheet (1 page)

Notation: `n` = number of elements in container. Complexities are typical/average unless noted.

---

## 1) `vector<T>` (dynamic array)
### Access
- `v[i]` **O(1)** (unchecked)
- `v.at(i)` **O(1)** (checked; may throw)
- `v.front()`, `v.back()` **O(1)**
- `v.size()`, `v.empty()` **O(1)**

### Insert / Remove
- `v.push_back(x)` **amortized O(1)**
- `v.pop_back()` **O(1)**
- `v.insert(pos, x)` **O(n)** (shifts elements)
- `v.erase(pos)` / `v.erase(l,r)` **O(n)**
- `v.clear()` **O(n)** (destroys elements)

### Search
- `find(v.begin(), v.end(), x)` **O(n)**
- `binary_search(v.begin(), v.end(), x)` **O(log n)** (requires sorted)
- `lower_bound/upper_bound` **O(log n)** (requires sorted)

### Iteration
- `for (auto &e : v) {}` **O(n)**
- `for (auto it=v.begin(); it!=v.end(); ++it) {}` **O(n)**

---

## 2) `string` (like `vector<char>`)
### Access
- `s[i]`, `s.at(i)` **O(1)**
- `s.size()` / `s.length()` **O(1)** (same)
- `s.front()`, `s.back()` **O(1)**

### Insert / Remove
- `s.push_back(c)` **amortized O(1)**
- `s.pop_back()` **O(1)**
- `s += t` / `s.append(t)` **O(|t|)**
- `s.substr(pos, len)` **O(len)**
- `s.clear()` **O(n)**

### Search
- `s.find(x)` **O(n)** typical
- `s.find(x, pos)` **O(n)** typical

### Iteration
- `for (char c : s) {}` **O(n)**

---

## 3) `array<T, N>` (fixed-size)
### Access
- `a[i]`, `a.at(i)` **O(1)**
- `a.size()` **O(1)**

### Insert / Remove
- None (size fixed)
- `a.fill(val)` **O(N)**

### Search / Iteration
- `for (auto &x : a)` **O(N)**

Tip: Use `array<int,26> cnt{};` for counting letters.

---

## 4) `unordered_map<K,V>` (hash map)
### Access
- `mp[key]` **avg O(1)**  
  *Creates key with default value if missing*.
- `mp.at(key)` **avg O(1)** (throws if missing)
- `mp.size()`, `mp.empty()` **O(1)**

### Insert / Remove
- `mp[key] = val` **avg O(1)**
- `mp.insert({k,v})` **avg O(1)** (won’t overwrite existing key)
- `mp.erase(key)` **avg O(1)**
- `mp.clear()` **O(n)**

### Search
- `mp.count(key)` **avg O(1)** (0 or 1)
- `mp.find(key)` **avg O(1)** (iterator or `mp.end()`)

### Iteration
- `for (auto &p : mp) { p.first, p.second }` **O(n)** (order not guaranteed)

---

## 5) `map<K,V>` (ordered map, balanced BST)
Same API as `unordered_map`, but:
- **ordered by key**
- operations **O(log n)**

### Access
- `mp[key]` **O(log n)** (inserts default if missing)
- `mp.at(key)` **O(log n)**

### Insert / Remove
- `mp.insert(...)` / `mp.erase(...)` **O(log n)**

### Search (ordered extras)
- `mp.find(key)` **O(log n)**
- `mp.lower_bound(key)` **O(log n)** (first key >= key)
- `mp.upper_bound(key)` **O(log n)** (first key > key)

### Iteration
- in increasing key order: `for (auto &p : mp)` **O(n)**

---

## 6) `unordered_set<T>` (hash set)
### Access / Search
- `st.count(x)` **avg O(1)** (0/1)
- `st.find(x)` **avg O(1)**

### Insert / Remove
- `st.insert(x)` **avg O(1)** returns `pair<it,bool>`
- `st.erase(x)` **avg O(1)**
- `st.clear()` **O(n)**

### Iteration
- `for (auto &x : st)` **O(n)** (order not guaranteed)

Pro tip (duplicate detection):
- `if (!st.insert(x).second) { /* duplicate */ }`
- insert returns: ```pair<iterator, bool>``` .second == true if insertion happened (value was not present), false if value already existed

---

## 7) `set<T>` (ordered set, balanced BST)
All ops are **O(log n)**, elements are sorted.
- `insert`, `erase`, `find`, `count` **O(log n)**
- `lower_bound/upper_bound` **O(log n)**
Iteration is sorted order **O(n)**.

---

## 8) `queue<T>` (FIFO)
### Access
- `q.front()`, `q.back()` **O(1)**
- `q.size()`, `q.empty()` **O(1)**

### Insert / Remove
- `q.push(x)` **O(1)**
- `q.pop()` **O(1)**

Iteration: not supported directly (you pop to traverse).

---

## 9) `stack<T>` (LIFO)
- `st.top()` **O(1)**
- `st.push(x)` **O(1)**
- `st.pop()` **O(1)**
- `st.size()`, `st.empty()` **O(1)**

---

## 10) `deque<T>` (double-ended queue)
- `push_back`, `push_front`, `pop_back`, `pop_front` **O(1)**
- `front`, `back`, `size`, `empty` **O(1)**
Used for sliding window / monotonic queue patterns.

---

## 11) `priority_queue<T>` (heap)
(Default: max-heap)
- `pq.push(x)` **O(log n)**
- `pq.pop()` **O(log n)**
- `pq.top()` **O(1)**
- `pq.size()`, `pq.empty()` **O(1)**

Min-heap:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## Algorithms you use constantly with containers
- `sort(v.begin(), v.end())` **O(n log n)**
- `reverse(v.begin(), v.end())` **O(n)**
- `max_element(...)`, `min_element(...)` **O(n)**
- `accumulate(..., 0LL)` **O(n)**
- `count(...)` **O(n)**
- `find(...)` **O(n)**
