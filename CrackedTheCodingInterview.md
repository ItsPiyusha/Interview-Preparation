##### Arrays
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0; i<nums.size(); i++){
            for(int j =0; j<nums.size(); j++){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
    }
};
```
  
few improvements and one major bug to consider:  
  
1. Infinite Loop / Undefined Behavior
If no two indices are found that sum to the target, your function does not return anything. This leads to undefined behavior. You should always return a value or throw an exception.  
  
2. Duplicate Pairs (i == j)  
Your solution allows i and j to be the same index, which is usually not allowed in Two Sum problems. Typically, you want two distinct indices.  
* when both loops starts at 0, duplicates are allowed   
3. Inefficiency  
Your approach is O(n²). For large input, consider using a hash map for O(n) performance.  

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) { // start j from i+1
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {}; // return empty vector if not found
    }
};
```
*how we return indices as a vector in cpp ->return {i, j}  
Hashmap is a general concept in computer science describing a data structure that stores key-value pairs for fast lookup, insertion, and deletion using a hash function.  
  
Language Implementations  
C++: std::unordered_map  
Java: HashMap  
Python: dict  
JavaScript: Map (or plain object {})  
C#: Dictionary<TKey, TValue>  
Go: map[keyType]valueType  
Rust: HashMap  
```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if(seen.count(complement))
                return {seen[complement], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};
```
because: Hashmap operations(get, insert, delete) are O(1) on average, but can degrade to O(n) in the worst case.  
*unordered_map<int,int>   
*.count() function  
*notice correct placement of seen[nums[i]] = i;// This line should be outside the if block  
  
  
*Problem-Solving Sequence  
Start with easy problems to build confidence, then progress to medium and hard. Recommended sequence:  

Arrays & Strings:  
Two Sum, Reverse String, Rotate Array  
Linked Lists:  
Merge Two Sorted Lists, Reverse Linked List  
Stacks & Queues:  
Valid Parentheses, Min Stack  
Trees:  
Binary Tree Inorder Traversal, Maximum Depth of Binary Tree  
Graphs:  
Number of Islands, Clone Graph  
Hash Tables:  
Group Anagrams, Top K Frequent Elements  
Dynamic Programming:  
Climbing Stairs, Longest Increasing Subsequence  
  
  
Reverse string  
1. Ask clarifying questions:  
Output requirement:Should I reverse the string in place or return a new string?  
Input type:What type of string (e.g., std::string, vector<char>, etc.)?Is it a mutable string (e.g., vector<char> in C++) or immutable (e.g., string in Java)?  
Constraints:Are there any constraints (e.g., can the string contain special characters or be empty)? : Unicode? Large string size? Special characters?  
  
2. Discuss an Approach   
For In-Place Reversal:	
Use two pointers: one at the start, one at the end.  
Swap the characters, move pointers towards each other until they meet.  
  
For Returning a New String:  
Create a new string and append characters from the original string in reverse order.  

Example: Reverse string in place (C++)  
```cpp
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}
```
Example: Return a reversed string (C++)  
```cpp
string reverseString(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}
```
```cpp
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}
```
Complexity:  
  
Time: O(n)  
Space: O(1)  
  
When to use:  
When you need to reverse in-place (e.g., mutable array/vector).  
If memory usage is important.  
  
B. Use Built-In Functions  
How:  
Most languages offer a reverse utility. Code (C++):  
  
C++  
reverse(s.begin(), s.end());  
  
Code (Python):  
Python  
s = s[::-1]  
  
Complexity:  
Time: O(n)  
Space: O(n) (Python, creates a new string)  
  
When to use:  
When allowed to use library functions (quick, concise).  
  
C. Stack Approach  
How:  
Push all characters onto a stack, then pop to build the reversed string. Code (C++):  
  
C++  
```cpp
string reverseString(string s) {
    stack<char> st;
    for(char c : s) st.push(c);
    string rev;
    while(!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}
```
Complexity:  
Time: O(n)  
Space: O(n)  
  
When to use:  
To demonstrate understanding of data structures.  
If interviewer asks for a stack-based solution.  
  
D. Recursion  
How:  
Recursively reverse substring, append first character at the end.   
  
Code (Python):  
Python  
```python
def reverse_string(s):
    if len(s) <= 1:
        return s
    return reverse_string(s[1:]) + s[0]
```
Complexity:  
Time: O(n)  
Space: O(n) (due to call stack)  
When to use:  
Interviewer asks for recursive solution.  
To show recursion skills.  


    
3. Edge Cases
Empty string: Should return empty.  
Single character: Should return itself.  
Unicode/Multibyte: Clarify if you need to handle.  
Immutable type: Must return a new object.  
4. Follow-up Interview Questions  
Can you do it in-place?  
Use two-pointer method.  
Can you do it with O(1) space?  
Two-pointer in-place for mutable types.  
Can you handle immutable strings?  
Return a new string.  
Can you use recursion?  
Show recursive solution.  
What if string is very large?  
Avoid recursive (stack overflow), prefer iteration.  
  
  
  
4. Explain Your Solution  
I use two pointers to swap elements from both ends, which gives O(n) time complexity and O(1) space if done in-place.  
This works for all string types and handles empty strings.  
5. Test Edge Cases  
Empty string  
String with one character  
String with special or Unicode characters  
6. Optimize/Discuss Alternatives  
Mention use of built-in functions (like reverse() in C++) for simplicity.  
Discuss time and space complexity.  

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string s) {
    stack<char> st;
    for(char c : s) st.push(c);
    string rev;
    while(!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

int main() {
    string input = "hello world"; // Hardcoded string
    string reversed = reverseString(input);
    cout << "Original string: " << input << endl;
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
```
```cpp
int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
```
* note that s in string is always small.
```cpp
#include <bits/stdc++.h>
using namespace std;

string reverseString( string s){
    stack<char> st;
    for(char c : s) st.push(c);
    string rev;
    while (!st.empty()){
        rev += st.top();
        st.pop();
    }
    return rev;
}

int main() {
	// your code goes here
	string input = "Hello World";
	cout << "original string: "<< input << endl;
	cout << "reversed string: "<< reverseString(input) << endl;
    return 0;
}
```
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Original array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Input direction to rotate (right/left): ";
    string direction;
    cin >> direction;

    cout << "Input number of positions to rotate (k): ";
    int k;
    cin >> k;
    int n = nums.size();
    k = k % n; // To handle k > n

    if (direction == "right") {
        rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    } else if (direction == "left") {
        rotate(nums.begin(), nums.begin() + k, nums.end());
    } else {
        cout << "Invalid input. Please enter 'right' or 'left'." << endl;
        return 1;
    }

    cout << "Rotated array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
```

rotate(begin, middle, end)  
After rotation, the element pointed by middle becomes the new first element.  
All elements before middle are moved to the end in the same order.  
You can use std::rotate for both left and right rotations by adjusting the middle iterator accordingly.  

```cpp
if (direction != "right" && direction != "left" && direction != "r" && direction != "l") {
    // invalid input
}

if (direction == "right" || direction == "left" || direction == "r" || direction == "l") {
    // valid input
} else {
    // invalid input
}
```
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rightrotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    for (int i = 0; i < n; ++i)
        temp[(i + k) % n] = nums[i];
    nums = temp;
}

void leftrotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    for (int i = 0; i < n; ++i)
        temp[i] = nums[(i + k) % n];
    nums = temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    string direction;
    int k;

    // Input direction with validation
    while (true) {
        cout << "Input direction to rotate (right/left): ";
        cin >> direction;
        if (direction == "right" || direction == "left") {
            break;
        } else {
            cout << "Invalid input, please try again." << endl;
        }
    }

    // Input k with validation
    cout << "Input number of positions to rotate (k): ";
    cin >> k;

    if (direction == "right") {
        rightrotate(nums, k);
    } else {
        leftrotate(nums, k);
    }

    cout << "Rotated array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
```
##### Linked Lists
# Problem: Merge Two Sorted Lists
Description:  
Given two singly-linked lists where each list is already sorted in ascending order, merge them into a single sorted linked list. The merged list should also be in ascending order.  

Example  
Input:  
List 1: 1 → 4 → 6  
List 2: 2 → 3 → 5  
  
Output:  
1 → 2 → 3 → 4 → 5 → 6  
  
Clarifying Questions  
Are the input lists empty sometimes? (Yes, either or both could be empty)  
Can we modify the original lists, or do we need to create a new list? (Usually, you should reuse the existing nodes)  
Are there any constraints on the size of the lists? (No special constraints unless specified)  
Approach  
Two-Pointer Technique:  
Use pointers to traverse both lists:  
  
Compare the current node of both lists.  
Append the smaller node to the result and move that pointer forward.  
Continue until you reach the end of one list.  
Attach the remaining nodes from the other list to the result.  
Edge Cases:  
  
One or both lists are empty.  
Lists with duplicate elements.  
Pseudo-code  
Code  
```
function mergeTwoLists(l1, l2):
    create a dummy node to start the result list
    current = dummy

    while l1 is not null and l2 is not null:
        if l1.val < l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next

    # Attach the remaining part, if any
    if l1 is not null:
        current.next = l1
    else:
        current.next = l2

    return dummy.next
```
Complexity  
Time: O(n + m), where n and m are the lengths of the two lists.  
Space: O(1) (if you’re reusing the existing nodes; O(n + m) if creating new nodes).  

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify edge cases
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // Traverse both lists and attach the smaller node each time
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    // Attach the remaining nodes, if any
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}
```

 The use of a dummy node in linked list problems is a common technique, especially in merge operations like this. Here’s why it’s used and how it simplifies edge cases:

Why Use a Dummy Node?
1. Simplifies List Initialization
Without a dummy node, you’d have to write special logic for initializing the head of the merged list, because for the very first node, tail doesn’t point anywhere yet.  
With a dummy node, you always have a starting point. tail always points to a valid node (the dummy at first), so you can just set tail->next each time without worrying if you’re still at the head.  
2. Avoids Special Cases  
If you don’t use a dummy node, you’d need an extra check for the first insertion:  
```cpp
if (head == nullptr) {
    head = newNode;
    tail = head;
} else {
    tail->next = newNode;
    tail = tail->next;
}
```
With a dummy node, all insertions are handled identically in the loop, and at the end you just return dummy.next as the real head.  
3. Cleaner and Less Error-Prone Code  
It makes the code shorter, more readable, and less prone to bugs related to head initialization or empty input lists.  
Is the Dummy Node Only for Edge Cases?  
The dummy node is primarily to simplify edge cases, such as:  

The merged list is empty (both input lists are empty).  
The merged list’s head is the first node picked from either list.  
Handling the first insertion without separate logic.  
But more broadly, it streamlines the merging process by allowing you to treat every node insertion the same way, regardless of its position in the merged list.  

Summary Table
_______________________________________________________________
|Without Dummy Node	              |With Dummy Node (as above)  |
|---------------------------------|----------------------------|
|Special logic for head insertion |No special logic needed     |
|More lines of code               |	Cleaner, shorter code      |
|More edge cases to handle	      |Edge cases handled easily   |
_______________________________________________________________
In short:
The dummy node is a simple trick to avoid special-case logic at the start of your list, making your code more robust and readable!



 In C++, both struct and class can be used to define custom types like linked list nodes, and they are almost identical except for one key difference:  

struct members are public by default  
class members are private by default  
Why use struct for ListNode?  
In the context of a ListNode for a linked list, you typically want all members (like val and next) to be public, since you need to easily access and modify them in your algorithms. Using struct makes the code more concise and signals that this is a simple data container, not an abstraction with encapsulation or invariants.  

Example:  
C++  
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```
Members val and next are public and easily accessible.  
If you used class, you would need to explicitly declare them as public:  
  
C++  
```cpp
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```
When to use class?  
Use class when you need encapsulation, private/protected members, or member functions that enforce invariants or control access. For simple data structures (like nodes in a linked list or trees), struct is usually preferred for its simplicity and clarity.  

Summary  
Use struct for plain data containers with public members (like ListNode).  
Use class when you need encapsulation or more complex behavior.  
  
# OOP concepts, examples and explain in detail
  
1. Objects and Classes  
Class: A blueprint or template for creating objects. It defines data (attributes) and behavior (methods).  
Object: An instance of a class, representing a real-world entity with state and behavior.  
Example (C++):  
  
C++
```cpp
class Car {
public:
    string brand;
    void honk() {
        cout << "Beep!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";
    myCar.honk(); // Output: Beep!
}
```  
Here, Car is the class, and myCar is an object.
  
2. Encapsulation  
Definition: Bundling data (attributes) and methods (functions) that operate on that data into a single unit (class), and restricting access to some of the object's components.  
Purpose: To protect the internal state of an object and only allow access via well-defined interfaces (getters/setters).  
Example (C++):  
  
C++  
```cpp
class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) { balance += amount; }
    double getBalance() { return balance; }
};
```
Here, balance is private, so it cannot be accessed directly from outside the class.  
  
3. Inheritance  
Definition: Mechanism by which one class (child/subclass) can inherit properties and behaviors (methods and fields) from another class (parent/superclass).  
Purpose: To promote code reusability and hierarchical relationships.  
Example (C++):    
  
C++  
```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking" << endl; }
};

int main() {
    Dog d;
    d.eat(); // Inherited from Animal
    d.bark();
}
```
Dog inherits eat() from Animal.  
  
4. Polymorphism  
Definition: The ability to present the same interface for different data types or the ability for different classes to provide different implementations of methods that are called through the same name.  
Types:  
Compile-time (method overloading, operator overloading)  
Runtime (method overriding using virtual functions)  
Example (C++ - Runtime Polymorphism):  
  
C++  
```cpp
class Animal {
public:
    virtual void sound() { cout << "Some sound" << endl; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Bark" << endl; }
};

void makeSound(Animal* a) {
    a->sound();
}

int main() {
    Dog d;
    makeSound(&d); // Output: Bark
}
```
Here, the method sound() behaves differently depending on the object type.  
  
5. Abstraction  
Definition: Hiding complex implementation details and showing only the necessary features of an object.  
Purpose: To reduce complexity and allow the programmer to focus on interactions at a higher level.  
Example (C++ - Abstract Class):  
  
C++
```cpp
class Shape {
public:
    virtual double area() = 0; // Pure virtual function
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14 * radius * radius; }
};
```
Shape provides an abstract interface, and Circle implements it.  
# Problem: Reverse a Singly Linked List
Description  
Given the head of a singly linked list, reverse the list and return the new head.  
  
Example:
  
Input: 1 → 2 → 3 → 4 → 5 → NULL  
Output: 5 → 4 → 3 → 2 → 1 → NULL  
Clarifying Questions  
Is the input list empty? (Yes, handle empty list case)  
Can I modify the input list, or do I need to create a new list? (Typically, modify in-place)  
Is it a singly or doubly linked list? (Usually singly unless specified)  
Approach  
Iterative Approach (Common in Interviews)  
Initialize three pointers:  
prev (set to NULL)  
curr (set to head)  
next (to temporarily store the next node)  
Traverse the list:  
At each step, store the next node.  
Reverse the current node’s pointer to point to prev.  
Move prev and curr one step forward.  
When curr becomes NULL, prev will be the new head.  
Pseudo-code:  
  
Code  
```
prev = NULL
curr = head
while curr is not NULL:
    next = curr.next
    curr.next = prev
    prev = curr
    curr = next
return prev
```
Recursive Approach (Less common, but sometimes asked)  
Recursively reverse the rest of the list.  
Change the next pointer of the next node to point back to current node.  
Edge Cases  
Empty list (head == NULL)  
List with one node  
Complexity  
Time: O(n), where n is the number of nodes  
Space: O(1) for iterative, O(n) for recursive (due to stack)  
C++ Example Implementation  
C++  
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```
This problem tests your understanding of pointer manipulation, linked list traversal, and edge case handling—core topics for technical interviews at Google and other top tech companies.  

##### Stacks and Queues
# Problem: Valid Parentheses
Description  
Given a string containing just the characters '(', ')', '{', '}', '[', and ']', determine if the input string is valid.  
  
A string is valid if:  
  
Open brackets are closed by the same type of brackets.  
Open brackets are closed in the correct order.  
Every closing bracket has a corresponding opening bracket of the same type.  
Examples:  
  
Input: "()[]{}" → Output: true  
Input: "(]" → Output: false  
Input: "([)]" → Output: false  
Input: "{[]}" → Output: true  
Approach (with Explanation):  
Core Idea  
Use a stack data structure.  
Push opening brackets onto the stack.  
For closing brackets, check if the stack is not empty and the top of the stack is the matching opening bracket. If not, the string is not valid.  
At the end, the stack should be empty if all brackets are matched.  
Why a Stack?  
A stack helps maintain the order of opening brackets, letting you check the most recent opening bracket when a closing bracket is encountered.  
C++ Solution  
```cpp
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    for (char c : s) {
        // If it's a closing bracket
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        } else {
            // It's an opening bracket
            st.push(c);
        }
    }
    return st.empty();
}
```
Edge Cases to Discuss  
Empty string ("") should return true (nothing to match is still valid).  
Odd-length strings can never be valid (each open must have a close).  
Strings with only opening or only closing brackets are invalid.  
Time and Space Complexity  
Time: O(n), where n is the length of the string (one pass through input).  
Space: O(n), in the worst case (all opening brackets).  
Sample Interview Explanation  
“I’d use a stack to keep track of opening brackets. When I see a closing bracket, I’d check if the stack’s top is the matching opening bracket. If yes, I pop it; if not, or if the stack is empty, return false. At the end, if the stack is empty, the string is valid; otherwise, it’s not.”  
# Problem: Min Stack
Description  
Design a stack that, in addition to standard stack operations (push, pop, top), can also retrieve the minimum element in constant time (getMin).  
  
You must support:  
  
push(x): Push element x onto stack.  
pop(): Removes the element on top of the stack.  
top(): Get the top element.  
getMin(): Retrieve the minimum element in the stack.  
All operations should run in O(1) time.  
  
Constraints & Follow-ups  
Only standard stack data structures allowed.  
You must not use sorting or search for the minimum on demand.  
Intuition & Approach  
Naive Approach  
With a single stack, getMin() would require scanning all elements—O(n) time.  
To achieve O(1) for getMin(), use an auxiliary stack to keep track of the minimum.  
Optimal Solution: Two Stacks  
Use one main stack to store all values.  
Use a second stack (minStack) to store the minimum at each level of the stack.  
How does it work?  
  
When pushing, push the value onto the main stack.  
For minStack, push the minimum of the new value and the current min (i.e., min(x, minStack.top())).  
When popping, pop from both stacks.  
getMin() is simply the top of minStack.  
C++ Implementation  
C++  
```cpp
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minStack;
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }
    }
    void pop() {
        s.pop();
        minStack.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return minStack.top();
    }
};
```
Key Points to Discuss in an Interview  
Why two stacks? To keep track of the min at each state of the stack.  
All operations are O(1), including getMin().  
Edge cases: Stack is empty, multiple minimums with the same value.  
Sample Usage  
C++  
MinStack minStack;  
minStack.push(-2);  
minStack.push(0);  
minStack.push(-3);  
minStack.getMin();   // Returns -3  
minStack.pop();  
minStack.top();      // Returns 0  
minStack.getMin();   // Returns -2  

# Binary Tree Inorder Traversal
Problem Statement
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Inorder traversal means visiting the left subtree, then the root, then the right subtree.

Step-by-Step Solution
Let’s solve it both recursively and iteratively, and explain the logic as you would in an interview.

1. Recursive Approach
Explanation (How to explain to an interviewer):
In an inorder traversal, we need to process nodes in the Left, Root, Right order.
For recursion:
Recursively traverse the left subtree.
Visit the root node.
Recursively traverse the right subtree.
```cpp
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
}
```
Interview explanation:
- “I’ll use a helper function to visit nodes recursively. For each node, I’ll visit its left child, then process its value, then visit its right child. The base case is when the node is None.”
- Time Complexity: O(n), visiting each node once.
- Space Complexity: O(n) in the worst case (for recursion stack).

2. Iterative Approach
Explanation (How to explain to an interviewer):
- Sometimes recursion is not allowed due to stack overflow or interviewer's request. We'll use a stack to simulate recursion.
- The idea is to go as left as possible, pushing nodes onto the stack, then process the nodes, and finally go right.

```cpp
#include <vector>
#include <stack>
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top(); stk.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}
```
Interview explanation:
- “I’ll use a stack to keep track of nodes. First, I push left children onto the stack until I reach the leftmost node. Then, I process the node, and move to its right child. Repeat until the stack is empty and there are no more nodes.”
- Time Complexity: O(n), since each node is pushed and popped once.
- Space Complexity: O(n), for the stack in the worst case (skewed tree).
What Interviewers Look For
- Understanding of tree traversals.
- Ability to convert recursion to iteration.
- Clear explanation and handling of edge cases (like empty tree).
- Awareness of time and space complexity.

# Maximum Depth of Binary Tree
Problem Statement
Given the root of a binary tree, find its maximum depth.

- The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


Approach & Explanation
Recursive Solution
How to explain:

- At each node, the maximum depth is 1 (for the current node) plus the maximum of the depths of its left and right subtrees.
- The base case is when the node is null; in that case, the depth is 0.
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}
```
* What to say in the interview: *
- At each node, I check if it is null. If so, depth is 0.
- Otherwise, I recursively compute the depth of the left and right subtrees and return one plus the greater of those depths.
- Time complexity: O(n), where n is the number of nodes (every node is visited once).
- Space complexity: O(h), where h is the tree height (due to the call stack).

  Iterative Solution (using BFS / Queue)
- We can use a queue for level order traversal (BFS).
- For every level, increment the depth counter.

```cpp
#include <queue>
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++depth;
    }
    return depth;
}
```
What to say in the interview:

- I use a queue for BFS, adding child nodes level by level.
- After processing all nodes at one level, I increment the depth counter.
- Time complexity: O(n).
- Space complexity: O(n) (at worst, all nodes at the largest level in the queue).
Interview Tips
- Always mention base case and edge case (e.g., empty tree).
- Explain both recursive and iterative approaches if time allows.
- Mention time and space complexities.
- Clearly describe how you traverse the tree and how you update the depth.

# Graphs
### Number of islands
Problem Statement
Given a 2D grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
```
Input:
11110
11010
11000
00000

Output: 1
```
```
Input:
11000
11000
00100
00011

Output: 3
```
# Key Points for Interview
- Use DFS (or BFS) to traverse and mark visited land.
- Iterate over each cell; if it’s '1', start a DFS/BFS and increment the island count.
- Modify the grid in-place to mark visited cells, or use a separate visited matrix if you need to preserve the input.

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0'; // Mark as visited

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++count;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
    }
};
```
Time complexity: O(m * n), where m and n are grid dimensions.

#### Clone Graph

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a value (int val) and a list of its neighbors.  

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.count(node))
            return visited[node];

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        return clone;
    }
};

// Example usage:
int main() {
    // Create a very simple graph: 1--2
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n1);

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    // Print values to verify (should print 1 and 2 for the new nodes)
    cout << cloned->val << endl; // 1
    for (auto neighbor : cloned->neighbors) {
        cout << neighbor->val << endl; // 2
    }
    // Cleanup omitted for brevity

    return 0;
}
```
### Hash Tables

## Group Anagrams
Given an array of strings, group the anagrams together. You can return the answer in any order.
```
Input:  ["eat", "tea", "tan", "ate", "nat", "bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
```
Anagrams are words with the same letters in different orders. The most common way to group them is to sort the characters of each word, and use that sorted string as a key.
```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sorted string is the key
            anagramMap[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(move(pair.second));
        }
        return result;
    }
};
```
Key Points for Interviews
- Use a hash map (unordered_map) to group words by their sorted string.
- Sorting each word gives a unique key for its anagram group.
- Time complexity is O(N * K log K), where N = number of strings, K = max length of a string (for sorting).

## Top K frequent element
problem statement:   
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.
```
Input: nums = [1,1,1,2,2,3], k = 2  
Output: [1,2]
```
```
Input: nums = [1], k = 1  
Output: [1]
```
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // Min-heap to keep k most frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```

# Dynamic Programming
## climbing stairs
problem:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
How many distinct ways can you climb to the top?  


*Solution Explanation*
This is a classic dynamic programming problem, similar to computing the Fibonacci sequence:
  
If you have n steps, the number of ways to reach the nth step is the sum of the ways to reach (n-1) steps and (n-2) steps, because you could have come from either one step below or two steps below.  
Base cases:  
If n == 1, only 1 way.  
If n == 2, two ways: (1+1) or (2).  
The code iteratively computes the answer using two variables (space-optimized DP).  


```cpp
#include <iostream>
#include <vector>
using namespace std;

// Climbing Stairs: DP solution
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev1 = 2, prev2 = 1, curr;
        for (int i = 3; i <= n; ++i) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
```

## Longest Increasing Subsequence (LIS)
problem: Given an integer array nums, return the length of the longest strictly increasing subsequence.

Solution Explanation
This uses dynamic programming:
- dp[i] stores the length of the LIS ending at index i.
- For each i, iterate over all previous elements (j < i). If nums[i] > nums[j], then dp[i] can be at least dp[j] + 1.
- The result is the maximum value in dp.
- Double for-loop: O(n^2) time complexity.
- dp[i] always at least 1 (the element itself).
- At the end, maxLen holds the length of the LIS.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Longest Increasing Subsequence: DP with O(n^2) time
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}
```
