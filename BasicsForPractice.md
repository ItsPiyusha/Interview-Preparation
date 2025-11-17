```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Brute-force solution
    // Time Complexity: O(N^2), where N is the length of the array
    // Space Complexity: O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    // Optimized solution using a hash map
    // Time Complexity: O(N), where N is the length of the array
    // Space Complexity: O(N)
    vector<int> twoSumOptimized(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_to_index.count(complement)) {
                return {num_to_index[complement], i};
            }
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Brute-force test
    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Brute-force Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found (brute-force)." << endl;
    }

    // Optimized test
    result = sol.twoSumOptimized(nums, target);
    if (!result.empty()) {
        cout << "Optimized Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found (optimized)." << endl;
    }

    return 0;
}
```




```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using std::reverse (in-place)
    // Time Complexity: O(N), where N is the length of the string
    void reverseStringInPlace(string &s) {
        reverse(s.begin(), s.end());
    }

    // Approach 2: Two pointers (in-place)
    // Time Complexity: O(N), where N is the length of the string
    void reverseStringTwoPointers(string &s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    // Approach 3: Using a new string (not in-place)
    // Time Complexity: O(N), where N is the length of the string
    string reverseStringNewString(const string &s) {
        string reversed = "";
        for (int i = s.length() - 1; i >= 0; --i) {
            reversed += s[i];
        }
        return reversed;
    }

    // Approach 4: Using recursion
    // Time Complexity: O(N^2), due to string concatenation at each recursion level
    string reverseStringRecursion(const string &s) {
        if (s.empty()) return "";
        return reverseStringRecursion(s.substr(1)) + s[0];
    }
};

int main() {
    Solution sol;
    string s1 = "hello";
    string s2 = "world";
    string s3 = "openai";
    string s4 = "github";

    // Approach 1
    string tmp1 = s1;
    sol.reverseStringInPlace(tmp1);
    cout << "Approach 1 (std::reverse): " << tmp1 << endl;

    // Approach 2
    string tmp2 = s2;
    sol.reverseStringTwoPointers(tmp2);
    cout << "Approach 2 (Two pointers): " << tmp2 << endl;

    // Approach 3
    string result3 = sol.reverseStringNewString(s3);
    cout << "Approach 3 (New string): " << result3 << endl;

    // Approach 4
    string result4 = sol.reverseStringRecursion(s4);
    cout << "Approach 4 (Recursion): " << result4 << endl;

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

class Solution {
public:
    // Approach 1: Using Extra Array
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    void rotateExtraArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; ++i)
            temp[(i + k) % n] = nums[i];
        nums = temp;
    }

    // Approach 2: Rotate One by One
    // Time Complexity: O(N * k)
    // Space Complexity: O(1)
    void rotateOneByOne(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < k; ++i) {
            int last = nums[n - 1];
            for (int j = n - 1; j > 0; --j)
                nums[j] = nums[j - 1];
            nums[0] = last;
        }
    }

    // Approach 3: Using Reverse
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    void rotateReverse(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // Approach 4: Cyclic Replacements
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    void rotateCyclic(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
                ++count;
            } while (start != current);
        }
    }
};

// Helper function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;
    vector<int> arr4 = arr1;
    int k = 3;

    // Approach 1
    sol.rotateExtraArray(arr1, k);
    cout << "Approach 1 (Extra Array): ";
    printArray(arr1);

    // Approach 2
    sol.rotateOneByOne(arr2, k);
    cout << "Approach 2 (One by One): ";
    printArray(arr2);

    // Approach 3
    sol.rotateReverse(arr3, k);
    cout << "Approach 3 (Reverse): ";
    printArray(arr3);

    // Approach 4
    sol.rotateCyclic(arr4, k);
    cout << "Approach 4 (Cyclic Replacement): ";
    printArray(arr4);

    return 0;
}
```

```cpp
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Approach 1: Iterative (using a dummy node)
    // Time Complexity: O(N + M), where N and M are lengths of the two lists
    // Space Complexity: O(1)
    ListNode* mergeTwoListsIterative(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
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
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // Approach 2: Recursive
    // Time Complexity: O(N + M)
    // Space Complexity: O(N + M) due to recursion stack
    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoListsRecursive(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }
};

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int val : vals) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to free a linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;
    vector<int> vals1 = {1, 2, 4};
    vector<int> vals2 = {1, 3, 4};

    ListNode* l1 = createList(vals1);
    ListNode* l2 = createList(vals2);

    // Iterative approach
    ListNode* mergedIterative = sol.mergeTwoListsIterative(l1, l2);
    cout << "Merged List (Iterative): ";
    printList(mergedIterative);

    // Need new lists for recursive since the above merged them
    l1 = createList(vals1);
    l2 = createList(vals2);

    // Recursive approach
    ListNode* mergedRecursive = sol.mergeTwoListsRecursive(l1, l2);
    cout << "Merged List (Recursive): ";
    printList(mergedRecursive);

    // Free memory
    freeList(mergedIterative);
    freeList(mergedRecursive);

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Approach 1: Iterative
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(1)
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // Approach 2: Recursive
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N) due to recursion stack
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }

    // Approach 3: Using Stack
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N) for the stack
    ListNode* reverseListStack(ListNode* head) {
        vector<ListNode*> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push_back(curr);
            curr = curr->next;
        }
        if (stack.empty()) return nullptr;
        ListNode* newHead = stack.back();
        stack.pop_back();
        curr = newHead;
        while (!stack.empty()) {
            curr->next = stack.back();
            curr = curr->next;
            stack.pop_back();
        }
        curr->next = nullptr;
        return newHead;
    }
};

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int val : vals) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to free a linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;
    vector<int> vals = {1, 2, 3, 4, 5};

    ListNode* l1 = createList(vals);
    ListNode* l2 = createList(vals);
    ListNode* l3 = createList(vals);

    // Iterative approach
    ListNode* reversedIterative = sol.reverseListIterative(l1);
    cout << "Reversed List (Iterative): ";
    printList(reversedIterative);

    // Recursive approach
    ListNode* reversedRecursive = sol.reverseListRecursive(l2);
    cout << "Reversed List (Recursive): ";
    printList(reversedRecursive);

    // Stack approach
    ListNode* reversedStack = sol.reverseListStack(l3);
    cout << "Reversed List (Stack): ";
    printList(reversedStack);

    // Free memory
    freeList(reversedIterative);
    freeList(reversedRecursive);
    freeList(reversedStack);

    return 0;
}
```

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

/*
Problem: Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Example:
Input: s = "{[()]}"
Output: true

Input: s = "([)]"
Output: false
*/

class Solution {
public:
    // Approach 1: Using Stack (Standard Approach)
    // Time Complexity: O(N), N is the length of the string
    // Space Complexity: O(N), for the stack
    bool isValidStack(const string& s) {
        stack<char> st;
        unordered_map<char, char> mp = {{')','('}, {']','['}, {'}','{'}};
        for (char ch : s) {
            // If opening bracket, push to stack
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                // If closing and stack empty or top doesn't match, invalid
                if (st.empty() || st.top() != mp[ch]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    // Approach 2: Replace pairs iteratively (Brute Force)
    // Time Complexity: O(N^2) in worst case due to repeated string scans and replacements
    // Space Complexity: O(N) for the new string
    bool isValidReplace(string s) {
        int len;
        do {
            len = s.size();
            for (const string& p : {"()", "[]", "{}"})
                s = replaceAll(s, p, "");
        } while (len != s.size());
        return s.empty();
    }

    // Helper for Approach 2: Replace all occurrences of sub in s with ""
    string replaceAll(string s, const string& sub, const string& repl) {
        size_t pos = 0;
        while ((pos = s.find(sub, pos)) != string::npos) {
            s.replace(pos, sub.length(), repl);
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {"()", "()[]{}", "(]", "([)]", "{[]}", "{[()]}", "{[(])}"};

    cout << "Approach 1: Stack\n";
    for (const string& s : testCases) {
        cout << "Input: " << s << " -> " << (sol.isValidStack(s) ? "true" : "false") << endl;
    }

    cout << "\nApproach 2: Replace pairs\n";
    for (const string& s : testCases) {
        cout << "Input: " << s << " -> " << (sol.isValidReplace(s) ? "true" : "false") << endl;
    }

    return 0;
}
```

```cpp
#include <iostream>
#include <stack>
#include <vector>
#include <limits>
using namespace std;

/*
Problem: Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- void push(int val)      : Pushes the element val onto the stack.
- void pop()              : Removes the element on the top of the stack.
- int top()               : Gets the top element of the stack.
- int getMin()            : Retrieves the minimum element in the stack.

Example:
Input:
push(-2)
push(0)
push(-3)
getMin()   // returns -3
pop()
top()      // returns 0
getMin()   // returns -2
*/

class MinStackSingleStack {
    // Approach 1: Single stack with pair (value, current min)
    // Time Complexity: O(1) for all operations
    // Space Complexity: O(N)
    stack<pair<int, int>> st;
public:
    void push(int val) {
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }
    void pop() {
        if (!st.empty()) st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

class MinStackTwoStacks {
    // Approach 2: Two stacks (one for values, one for min values)
    // Time Complexity: O(1) for all operations
    // Space Complexity: O(N)
    stack<int> data, minSt;
public:
    void push(int val) {
        data.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }
    void pop() {
        if (!data.empty()) {
            data.pop();
            minSt.pop();
        }
    }
    int top() {
        return data.top();
    }
    int getMin() {
        return minSt.top();
    }
};

class MinStackOptimized {
    // Approach 3: Optimized two stacks (min stack only stores new minimums)
    // Time Complexity: O(1) for all operations
    // Space Complexity: O(N) (better in practice if many duplicates)
    stack<int> data, minSt;
public:
    void push(int val) {
        data.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    void pop() {
        if (data.top() == minSt.top())
            minSt.pop();
        data.pop();
    }
    int top() {
        return data.top();
    }
    int getMin() {
        return minSt.top();
    }
};

// Helper function to run operations and demonstrate MinStack
void runMinStackDemo(auto& minStack, const vector<string>& ops, const vector<int>& vals) {
    int valIdx = 0;
    for (const string& op : ops) {
        if (op == "push") {
            cout << "push(" << vals[valIdx] << ")\n";
            minStack.push(vals[valIdx++]);
        } else if (op == "pop") {
            cout << "pop()\n";
            minStack.pop();
        } else if (op == "top") {
            cout << "top() -> " << minStack.top() << endl;
        } else if (op == "getMin") {
            cout << "getMin() -> " << minStack.getMin() << endl;
        }
    }
    cout << endl;
}

int main() {
    vector<string> ops = {"push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<int> vals = {-2, 0, -3};

    cout << "MinStack: Single Stack Approach\n";
    MinStackSingleStack minStack1;
    runMinStackDemo(minStack1, ops, vals);

    cout << "MinStack: Two Stacks Approach\n";
    MinStackTwoStacks minStack2;
    runMinStackDemo(minStack2, ops, vals);

    cout << "MinStack: Optimized Two Stacks Approach\n";
    MinStackOptimized minStack3;
    runMinStackDemo(minStack3, ops, vals);

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem: Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Inorder traversal visits nodes in the order: left subtree, root, right subtree.

Example:
Input:    1
           \
            2
           /
          3
Output: [1, 3, 2]

Explanation: The inorder traversal visits node 1, then left child of 2 (which is 3), then node 2.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Approach 1: Recursive
    // Time Complexity: O(N), where N = number of nodes
    // Space Complexity: O(N) for recursion stack
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
    void inorderHelper(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorderHelper(node->left, res);
        res.push_back(node->val);
        inorderHelper(node->right, res);
    }

    // Approach 2: Iterative using stack
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }

    // Approach 3: Morris Traversal (Threaded Binary Tree)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    vector<int> inorderTraversalMorris(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};

// Helper function to create the tree from the example: [1, null, 2, 3]
TreeNode* createExampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << endl;
}

// Helper function to free tree memory
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    TreeNode* root = createExampleTree();

    cout << "Recursive Inorder Traversal: ";
    printVector(sol.inorderTraversalRecursive(root));

    cout << "Iterative Inorder Traversal: ";
    printVector(sol.inorderTraversalIterative(root));

    cout << "Morris Inorder Traversal: ";
    printVector(sol.inorderTraversalMorris(root));

    freeTree(root);
    return 0;
}
```

```cpp
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
Problem: Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:
Input:       3
           /   \
          9     20
               /  \
              15   7
Output: 3

Explanation: The longest path is [3,20,7] or [3,20,15], so the depth is 3.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Approach 1: Recursive (DFS)
    // Time Complexity: O(N), where N is the number of nodes in the tree
    // Space Complexity: O(N) for recursion stack in worst case (skewed tree)
    int maxDepthRecursive(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepthRecursive(root->left), maxDepthRecursive(root->right));
    }

    // Approach 2: Iterative (BFS using Queue)
    // Time Complexity: O(N)
    // Space Complexity: O(N) for the queue
    int maxDepthBFS(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }

    // Approach 3: Iterative (DFS using stack)
    // Time Complexity: O(N)
    // Space Complexity: O(N) for the stack
    int maxDepthDFS(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int maxDepth = 0;
        while (!stk.empty()) {
            auto [node, depth] = stk.top(); stk.pop();
            if (node) {
                maxDepth = max(maxDepth, depth);
                if (node->left) stk.push({node->left, depth + 1});
                if (node->right) stk.push({node->right, depth + 1});
            }
        }
        return maxDepth;
    }
};

// Helper to build the example tree:
//      3
//     / \
//    9  20
//       / \
//      15  7
TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

// Helper to free tree memory
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    TreeNode* root = buildExampleTree();

    cout << "Recursive (DFS) Max Depth: " << sol.maxDepthRecursive(root) << endl;
    cout << "Iterative (BFS) Max Depth: " << sol.maxDepthBFS(root) << endl;
    cout << "Iterative (DFS) Max Depth: " << sol.maxDepthDFS(root) << endl;

    freeTree(root);
    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem: Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example:
Input:
grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]
Output: 3

Explanation: There are three islands: top-left, middle, and bottom-right.
*/

class Solution {
public:
    // Approach 1: DFS (Depth-First Search)
    // Time Complexity: O(M*N), where M is number of rows and N is number of columns
    // Space Complexity: O(M*N) for recursion stack in the worst case (grid full of land)
    int numIslandsDFS(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c, rows, cols);
                    ++count;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1') return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }

    // Approach 2: BFS (Breadth-First Search)
    // Time Complexity: O(M*N)
    // Space Complexity: O(min(M, N)) for the queue
    int numIslandsBFS(vector<vector<char>> grid) {
        if (grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        vector<vector<char>> visited = grid;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (visited[r][c] == '1') {
                    bfs(visited, r, c, rows, cols);
                    ++count;
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        static vector<pair<int, int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = row + dr, nc = col + dc;
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }

    // Approach 3: Union Find (Disjoint Set Union, DSU)
    // Time Complexity: O(M*N * α(M*N)), where α is the inverse Ackermann function, very slow-growing
    // Space Complexity: O(M*N)
    int numIslandsUnionFind(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> parent(rows * cols, -1);
        int count = 0;

        auto find = [&](int i) {
            while(parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };

        auto unite = [&](int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                parent[pa] = pb;
                return true;
            }
            return false;
        };

        // Initialize parents and count
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    int id = r * cols + c;
                    parent[id] = id;
                    ++count;
                }
            }
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    int id = r * cols + c;
                    // Check right and down neighbors
                    if (r + 1 < rows && grid[r + 1][c] == '1' && unite(id, (r + 1) * cols + c)) --count;
                    if (c + 1 < cols && grid[r][c + 1] == '1' && unite(id, r * cols + (c + 1))) --count;
                }
            }
        }
        return count;
    }
};

// Helper to print the grid (for debug)
void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row)
            cout << cell << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution sol;

    // Copy grid for independent testing
    vector<vector<char>> gridForDFS = grid, gridForBFS = grid, gridForUF = grid;

    cout << "Number of Islands (DFS): " << sol.numIslandsDFS(gridForDFS) << endl;
    cout << "Number of Islands (BFS): " << sol.numIslandsBFS(gridForBFS) << endl;
    cout << "Number of Islands (Union Find): " << sol.numIslandsUnionFind(gridForUF) << endl;

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Problem: Clone Graph

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node in the graph contains an integer value and a list of its neighbors.

Example:
Input:
A graph node 1 connected to nodes 2 and 4.
2 is connected to 1 and 3.
3 is connected to 2 and 4.
4 is connected to 1 and 3.

Graph visualization:
1 -- 2
|    |
4 -- 3

Output:
A deep copy of the above graph.

Note: The returned node should not reference any node from the original input graph.

Node definition:
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
*/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    // Approach 1: DFS with HashMap
    // Time Complexity: O(N), where N is the number of nodes
    // Space Complexity: O(N) for the hashmap and recursion stack
    Node* cloneGraphDFS(Node* node) {
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        return clone;
    }

    // Approach 2: BFS with HashMap
    // Time Complexity: O(N)
    // Space Complexity: O(N) for the hashmap and queue
    Node* cloneGraphBFS(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);
        Node* clone = new Node(node->val);
        visited[node] = clone;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return clone;
    }
};

// Helper function to print the graph (BFS traversal)
void printGraph(Node* node) {
    if (!node) {
        cout << "Empty Graph" << endl;
        return;
    }
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << "Node " << curr->val << " neighbors: ";
        for (Node* neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}

// Helper to build the example graph:
// 1 -- 2
// |    |
// 4 -- 3
Node* buildExampleGraph() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};
    return n1;
}

// Helper to free the graph
void freeGraph(Node* node) {
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        for (Node* neighbor : curr->neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        delete curr;
    }
}

int main() {
    Solution sol;
    Node* graph = buildExampleGraph();

    cout << "Original Graph:" << endl;
    printGraph(graph);

    // Approach 1: DFS
    Node* clonedDFS = sol.cloneGraphDFS(graph);
    cout << "\nCloned Graph (DFS):" << endl;
    printGraph(clonedDFS);

    // Approach 2: BFS
    Node* clonedBFS = sol.cloneGraphBFS(graph);
    cout << "\nCloned Graph (BFS):" << endl;
    printGraph(clonedBFS);

    // Free memory (for demonstration purposes, ideally use smart pointers to avoid double-free)
    freeGraph(clonedDFS);
    freeGraph(clonedBFS);
    freeGraph(graph);

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Problem: Group Anagrams

Given an array of strings, group the anagrams together.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]

Explanation: "eat", "tea", and "ate" are anagrams of each other, and so are "tan" and "nat".
*/

class Solution {
public:
    // Approach 1: Sort each string and use as key
    // Time Complexity: O(N * K log K), where N is number of strings and K is the max length of a string
    // Space Complexity: O(N * K)
    vector<vector<string>> groupAnagramsSort(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& it : mp) {
            res.push_back(it.second);
        }
        return res;
    }

    // Approach 2: Use character count as key
    // Time Complexity: O(N * K), where N is number of strings and K is the max length of a string
    // Space Complexity: O(N * K)
    vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;
            string key;
            for (int i = 0; i < 26; ++i) {
                key += '#' + to_string(count[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};

// Helper function to print groups of anagrams
void printGroups(const vector<vector<string>>& groups) {
    cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            cout << "\"" << groups[i][j] << "\"";
            if (j != groups[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != groups.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    cout << "Approach 1 (Sort as key):" << endl;
    vector<vector<string>> result1 = sol.groupAnagramsSort(strs);
    printGroups(result1);

    cout << "Approach 2 (Count as key):" << endl;
    vector<vector<string>> result2 = sol.groupAnagramsCount(strs);
    printGroups(result2);

    return 0;
}

```

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

/*
Problem: Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Example:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Explanation: 1 appears 3 times, 2 appears 2 times, and 3 appears once. The top 2 frequent elements are 1 and 2.
*/

class Solution {
public:
    // Approach 1: Min Heap (Priority Queue)
    // Time Complexity: O(N log K), where N is the number of elements in nums
    // Space Complexity: O(N) for the hash map and heap
    vector<int> topKFrequentHeap(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end()); // Optional, for order
        return res;
    }

    // Approach 2: Bucket Sort
    // Time Complexity: O(N), where N is the number of elements in nums
    // Space Complexity: O(N)
    vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        vector<int> res;
        for (int i = n; i >= 0 && res.size() < k; --i) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }

    // Approach 3: Sorting
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    vector<int> topKFrequentSorting(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        vector<pair<int, int>> freqList(freq.begin(), freq.end());
        sort(freqList.begin(), freqList.end(), [](auto& a, auto& b){
            return b.second < a.second;
        });
        vector<int> res;
        for (int i = 0; i < k && i < freqList.size(); ++i) {
            res.push_back(freqList[i].first);
        }
        return res;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    cout << "Approach 1: Min Heap (Priority Queue): ";
    printVector(sol.topKFrequentHeap(nums, k));

    cout << "Approach 2: Bucket Sort: ";
    printVector(sol.topKFrequentBucketSort(nums, k));

    cout << "Approach 3: Sorting: ";
    printVector(sol.topKFrequentSorting(nums, k));

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example:
Input: n = 3
Output: 3

Explanation: There are three ways to climb to the top:
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    // Approach 1: Recursive (Brute Force)
    // Time Complexity: O(2^n)
    // Space Complexity: O(n) (recursion stack)
    int climbStairsRecursive(int n) {
        if (n <= 2) return n;
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }

    // Approach 2: Dynamic Programming (Memoization)
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int climbStairsMemo(int n) {
        vector<int> memo(n + 1, -1);
        return climbStairsMemoHelper(n, memo);
    }
    int climbStairsMemoHelper(int n, vector<int>& memo) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];
        memo[n] = climbStairsMemoHelper(n - 1, memo) + climbStairsMemoHelper(n - 2, memo);
        return memo[n];
    }

    // Approach 3: Dynamic Programming (Tabulation)
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int climbStairsDP(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Approach 4: Optimized DP (Constant Space)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int climbStairsOptimized(int n) {
        if (n <= 2) return n;
        int first = 1, second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs:" << endl;

    cout << "1. Recursive: " << sol.climbStairsRecursive(n) << endl;
    cout << "2. DP (Memoization): " << sol.climbStairsMemo(n) << endl;
    cout << "3. DP (Tabulation): " << sol.climbStairsDP(n) << endl;
    cout << "4. Optimized DP: " << sol.climbStairsOptimized(n) << endl;

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.

Example:
Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4

Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
*/

class Solution {
public:
    // Approach 1: Dynamic Programming (O(N^2))
    // Time Complexity: O(N^2), where N is the length of the nums array
    // Space Complexity: O(N)
    int lengthOfLIS_DP(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        int lis = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }

    // Approach 2: Patience Sorting with Binary Search (O(N log N))
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    int lengthOfLIS_BinarySearch(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }

    // Approach 3: Recursive with Memoization (Top-Down DP)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N^2)
    int lengthOfLIS_Memoization(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(n, -1));
        return helper(nums, -1, 0, memo);
    }
    int helper(vector<int>& nums, int prevIdx, int curr, vector<vector<int>>& memo) {
        if (curr == nums.size()) return 0;
        if (memo[prevIdx + 1][curr] != -1) return memo[prevIdx + 1][curr];
        int taken = 0;
        if (prevIdx == -1 || nums[curr] > nums[prevIdx]) {
            taken = 1 + helper(nums, curr, curr + 1, memo);
        }
        int notTaken = helper(nums, prevIdx, curr + 1, memo);
        return memo[prevIdx + 1][curr] = max(taken, notTaken);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Input: [10, 9, 2, 5, 3, 7, 101, 18]" << endl;

    cout << "Approach 1 (DP O(N^2)): ";
    cout << sol.lengthOfLIS_DP(nums) << endl;

    cout << "Approach 2 (Binary Search O(N log N)): ";
    cout << sol.lengthOfLIS_BinarySearch(nums) << endl;

    cout << "Approach 3 (Recursive + Memoization O(N^2)): ";
    cout << sol.lengthOfLIS_Memoization(nums) << endl;

    return 0;
}
```
