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
