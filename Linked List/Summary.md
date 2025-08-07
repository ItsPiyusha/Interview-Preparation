# 🧵 Linked List Patterns Summary

## 🔹 1. Reverse a Linked List
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
```  
          

🔗 [LeetCode #206 – Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## 🔹 2. Detect a Cycle in Linked List (Floyd’s Algorithm)

```  
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```
🔗 [LeetCode #141 – Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

## 🔹 3. Find Start of the Cycle
```
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return NULL;
}
```
🔗 [LeetCode #142 – Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

## 🔹 4. Merge Two Sorted Linked Lists
```
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
```
🔗 [LeetCode #21 – Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## 🔹 5. Remove N-th Node From End


```
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *first = &dummy, *second = &dummy;

    for (int i = 0; i <= n; i++) first = first->next;
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy.next;
}
```
🔗 [LeetCode #19 – Remove Nth Node From End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)




# 📚 Linked List in C++ Using Class Format

## ✅ Why Use Class Instead of Struct?
- `struct` is generally used for **POD** (Plain Old Data) types.
- `class` allows better control via access specifiers (like `private`, `protected`).
- Better OOP-style encapsulation when building real-world software.

---

## 🧱 Node Class

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;  // ✅ nullptr works perfectly fine in a class
    }
};

```

data: stores the value of the node.
  
next: pointer to the next node.
  
Constructor initializes data and sets next to nullptr.
  
## ⚙️ LinkedList Class

```
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // 🔧 Insert at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 🧩 Insert at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 🗑️ Delete a node by value
    void deleteByValue(int val) {
        if (head == nullptr) return;

        // Delete at head
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;  // Value not found

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // 🔍 Search for a value
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // 🖨️ Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

```
```
int main() {
    LinkedList ll;

    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtTail(30);
    ll.display();  // 20 -> 10 -> 30 -> NULL

    ll.deleteByValue(10);
    ll.display();  // 20 -> 30 -> NULL

    std::cout << (ll.search(30) ? "Found\n" : "Not Found\n");  // Found
    return 0;
}
```
#### 💡 Key Points to Remember
nullptr is the standard way to represent null in modern C++ (nullptr came in C++11).
  
new dynamically allocates memory; don't forget to delete nodes to prevent memory leaks.
  
head always points to the start of the list.
  
It's better to keep head private and access it via public methods.  


## 🧠 Concept-First, Code-Second Strategy for Linked Lists
# 🔗 Basic Analogy
* Think of a linked list as a chain of train compartments.
  
- Each compartment = a node.
  
- The connector = a pointer to the next compartment.  
---

## 🔁 Common Operations & Intuition
# 1. Insert at Head
* **Concept:** Place new node before the first node (new engine in the train).
  
* **Code Flow:**  
  
- Create a node. 
  
- Point new node’s next to current head. 
  
- Update head to new node. 
```
Node* temp = new Node(val);
temp->next = head;
head = temp;
```
# 2. Insert at Tail
* **Concept:**  Add node at the end (new compartment at end).
* **Code Flow:**

* Traverse till tail->next == NULL

* Add node after that

```
Node* temp = new Node(val);
if (head == NULL) head = temp;
else {
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = temp;
}
```
# 3. Insert at Position
* **Concept:** Add a node between two nodes (between 3rd and 4th compartment).

* **Code Flow:**

* Traverse till position-1

* Insert node, adjusting pointers

```
Node* temp = new Node(val);
Node* prev = head;
for (int i = 1; i < pos-1; i++) prev = prev->next;
temp->next = prev->next;
prev->next = temp;
```
# 4. Delete Node
* **Concept:** Unhook a node from the chain.

* Types:

* At head:

```
Node* temp = head;
head = head->next;
delete temp;
```
* At position:


```
Node* prev = head;
for (int i = 1; i < pos-1; i++) prev = prev->next;
Node* temp = prev->next;
prev->next = temp->next;
delete temp;
```
-----

# 🔍 Tips to Remember

| Operation      | Mental Model                | Pointer Involved            | Trick to Remember            |
| -------------- | --------------------------- | --------------------------- | ---------------------------- |
| Insert at Head | New node becomes new engine | newNode → oldHead           | Always point new to old      |
| Insert at Tail | Add node at NULL            | tail → newNode              | Traverse till `next == NULL` |
| Insert at Pos  | Stitch between two nodes    | prev → new → next           | Stop 1 before position       |
| Delete         | Unlink and delete           | prev → skip → delete target | Always unlink before delete  |

## 🧠 Memory Aids
1. **Draw each step** on paper (boxes + arrows).

2. **Say out loud:** "I want to place this node here, so I need to point this to that."

3. Practice with **empty list, single node, multi-node** variations.

4. **Dry run** on examples like:

* [10] → insert at head → [5 → 10]

* [5 → 10 → 20] → delete at pos 2 → [5 → 20]