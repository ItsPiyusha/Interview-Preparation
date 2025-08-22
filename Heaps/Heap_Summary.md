# Heap: Data Structure Overview
A **heap** is a complete binary tree where each node follows a specific ordering property:
* **Max-heap:** Every parent node is ≥ its children.
* **Min-heap:** Every parent node is ≤ its children.  

Heaps are mainly used for:
* Priority queues (efficient min/max extraction)
* Sorting (heapsort)
* Scheduling, event simulation, etc.  

**Time complexities:**
* Insert: *O(log N)*
* Extract min/max: *O(log N)*
* Peek: *O(1)*

## Example: Min-Heap in C++ (Google Interview Style)
Using `priority_queue` (STL, default is max-heap)
```cpp
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Min-heap: invert comparison
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(2);

    // Extract elements in sorted order
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    // Output: 1 2 3
    return 0;
}
```
**Explanation:**  
* `priority_queue<int, vector<int>, greater<int>>` constructs a min-heap.  
* `.push()` inserts, `.top()` gets the minimum, `.pop()` removes the minimum.
  
`priority_queue<int, vector<int>, greater<int>> minHeap` is a way to create a min-heap using the C++ STL. Here’s how it works:
  

**Syntax Breakdown**
* priority_queue<T> by default creates a max-heap: the largest element is at the top.
* The full template signature is:
  
`priority_queue<Type, Container, Compare>`
  
* Type: Data type (int here)

* Container: Internal container (vector<int> by default)

* Compare: Comparison functor; defaults to less<Type>, which creates a max-heap. 

  
**Making a Min-Heap** 
  
* To create a min-heap, you provide `greater<int>` as the third argument:  
`priority_queue<int, vector<int>, greater<int>> minHeap;`
* Now, the smallest element is always at the top

  
**What is** `greater<int>` **in C++?**
`greater<int>` is called a **function object** ("functor") in C++—a special object that behaves like a function. It’s defined in the `<functional>` header.  
Syntax
  
```cpp
#include <functional>
std::greater<int> comp;
```
You can use it in places where you need a comparison function—like algorithms (sort, priority_queue, etc.).  

**What does it do?**  
* greater<int>(a, b) returns true if a > b.
* Used as a sorting or comparison rule: it prioritizes larger values before smaller ones.  

**Example**  
```cpp
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {4, 1, 7, 3};
    sort(v.begin(), v.end(), greater<int>());
    // v is now {7, 4, 3, 1}
    for (int x : v) cout << x << " ";
}
```

Output: 7 4 3 1—sorted descending.

  
**Why are there parentheses?**  
* `greater<int>` is a type; `greater<int>()` is an object.

* No need for new—the STL automatically constructs the object to use for comparisons.
  
**Summary:**  

* `greater<int>` is a functor for comparing if one value is greater than another.

* Used in STL containers and algorithms to change how things are sorted or prioritized.


**Custom Heap Implementation**
  

```cpp
#include <vector>
#include <iostream>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (2*i + 1 < n) {
            int j = 2*i + 1;
            if (j+1 < n && heap[j+1] < heap[j]) j++;
            if (heap[i] <= heap[j]) break;
            swap(heap[i], heap[j]);
            i = j;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int top() { return heap.front(); }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() { return heap.empty(); }
};

int main() {
    MinHeap h;
    h.push(3); h.push(1); h.push(2);

    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    // Output: 1 2 3
    return 0;
}
```
#### Google Interview Tips
* Know both STL and custom heap implementation.
* Explain heap property, complexity, and practical applications.
* Practice coding heapify up/down, and using heaps in real tasks (e.g., merging sorted arrays, scheduling, etc.).  
**Pro tip:** Focus on clean, clear, and robust code with concise comments—this aligns with Google's coding style and interview expectations.
