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
