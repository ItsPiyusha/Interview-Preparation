# 📚 Stack Patterns Summary for DSA Interviews

---

## 🧱 1. **Basic Stack Operations**
- Learn how to implement and use a stack (array or linked list based)
- 🔗 [Implement Stack using Array](https://leetcode.com/problems/implement-stack-using-arrays/)
- 🔗 [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

---

## 🧮 2. **Next Greater / Smaller Element (NGE / NSE)**
Use a monotonic stack (increasing or decreasing order).

- 🔗 [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
- 🔗 [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)
- 🔗 [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
- 🔗 [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)

---

## 📉 3. **Stock Span Pattern**
Find the number of consecutive days before today with smaller prices.

- 🔗 [Online Stock Span](https://leetcode.com/problems/online-stock-span/)
- 🔗 [Stock Span Problem – GFG](https://www.geeksforgeeks.org/stock-span-problem/)

---

## 🏗️ 4. **Largest Rectangle in Histogram**
Hard problem that uses monotonic stack to find maximum area.

- 🔗 [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

---

## 🧱 5. **Stack in Expression Evaluation**
Use stack for postfix/prefix/infix evaluations.

- 🔗 [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
- 🔗 [Basic Calculator](https://leetcode.com/problems/basic-calculator/)
- 🔗 [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

---

## 🧩 6. **Balanced Parentheses / Valid Expressions**
Check balanced brackets using a stack.

- 🔗 [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- 🔗 [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
- 🔗 [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

---

## 🧃 7. **Remove Duplicates / Decode Strings**
Use stack to simulate decoding or cleaning a string.

- 🔗 [Remove All Adjacent Duplicates in String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
- 🔗 [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)
- 🔗 [Decode String](https://leetcode.com/problems/decode-string/)

---

## 🧠 8. **Design Stack Variants**
Stacks with special features: getMin, getMax, etc.

- 🔗 [Min Stack](https://leetcode.com/problems/min-stack/)
- 🔗 [Max Stack](https://leetcode.com/problems/max-stack/) *(Premium)*
- 🔗 [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

---

## 🔀 9. **Reverse Stack / Queue**
Use recursion or stack operations to reverse elements.

- 🔗 [Reverse a Stack using Recursion – GFG](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/)
- 🔗 [Reverse a Queue – GFG](https://www.geeksforgeeks.org/reverse-a-queue/)

---

## 🚦10. **Largest Rectangle / Max Area in Binary Matrix**
Use histogram logic with stacks on every row of matrix.

- 🔗 [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- 🔗 [Max Area of Rectangle in Binary Matrix – GFG](https://www.geeksforgeeks.org/max-rectangle-area-binary-matrix/)

---

# ✅ Tips:
- Use **monotonic stacks** (increasing/decreasing) for NGE/NSE problems.
- In expression problems, push operands or operators and process when needed.
- For decoding/duplicate removal, push characters and resolve when conditions match.


---

# 🧱 1. Basic Stack Operations

## 🔗 Implement Stack using Array

This is a basic implementation of a stack using a static array.  
We perform these main operations:

- `push(x)` – Add element `x` to the top
- `pop()` – Remove the top element
- `top()` – Return the top element
- `isEmpty()` – Check if stack is empty
- `isFull()` – Check if stack is full

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int topIndex;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    cout << "Top: " << st.top() << endl;  // Output: 20
    st.pop();
    cout << "Top: " << st.top() << endl;  // Output: 10
    return 0;
}
```

## 🔗 Implement Stack using Queues
We can use two queues to implement a stack.  
Two approaches:  
* **Push costly:** Push takes O(n), Pop takes O(1)

* **Pop costly:** Push takes O(1), Pop takes O(n)

# ✅ Push Costly Version
```
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Top: " << st.top() << endl;  // Output: 3
    st.pop();
    cout << "Top: " << st.top() << endl;  // Output: 2
    return 0;
}
```

# 💡 Tip to Remember:
* "Stack = LIFO (Last In First Out)"

* "push() goes to the top"

* "pop() removes from the top"

* "When using queues, reverse their nature to simulate stack"

# 🧱 Stack STL in C++

## 🧰 What is Stack?
A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.

### ✅ Common Operations:
| Operation     | Description                        |
|---------------|------------------------------------|
| `push(x)`     | Adds an element `x` on top         |
| `pop()`       | Removes the top element            |
| `top()`       | Returns the top element            |
| `empty()`     | Returns true if stack is empty     |
| `size()`      | Returns the number of elements     |

### 📦 Header File
```cpp
#include <stack>
using namespace std;
```
# 📌 Example: Using stack STL in C++
```
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Size: " << st.size() << endl; // 2
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl; // No
    return 0;
}
```
# ⭐ Most Important Stack Question
## 🔥 Valid Parentheses
📌 Leetcode #20. 
📚 Category: Stack, String.  

> Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

> An input string is valid if:

> * Open brackets must be closed by the same type of brackets.

> * Open brackets must be closed in the correct order.

# ✅ Approach:
* Use a stack to store opening brackets.

* When a closing bracket is found, check if it matches the top of the stack.

* If mismatch or stack is empty → invalid.

* If stack is empty at the end → valid.

# 💡 C++ Code:

```
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl; // Output: Valid
    return 0;
}
```
# 🧠 Tips to Remember:
* Push when open, pop when close.

* Check top element before popping.

* Final stack should be empty if balanced.

* [🔗 Leetcode 20 - Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
