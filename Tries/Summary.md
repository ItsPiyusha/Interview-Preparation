# 🧵 Trie (Prefix Tree) Patterns in DSA

Tries are specialized tree-based data structures used to store associative data structures where keys are usually strings. Great for **prefix-based searches**, **autocomplete systems**, and **dictionary-related problems**.

---

## 🪢 Core Concepts

- Each node represents a character of a word.
- Words are stored from root to leaf.
- Typically implemented with arrays/maps for 26 lowercase English letters (or more for Unicode).
- Supports insert, search, and delete operations.

---

## 📚 Basic Template

```cpp
struct TrieNode {
    TrieNode* links[26]; // or unordered_map<char, TrieNode*>
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a']) 
                node->links[ch - 'a'] = new TrieNode();
            node = node->links[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a']) return false;
            node = node->links[ch - 'a'];
        }
        return node->isEnd;
    }
};


# 🔤 Trie (Prefix Tree) Patterns – Important Questions

Tries are useful for efficiently storing and searching strings, especially for prefix-based queries. This is a key data structure in problems involving dictionaries, auto-complete, and word searches.

---

## ✅ Core Concepts:
- Each node represents a character.
- Paths from root to leaf represent words.
- Great for prefix lookups.
- Space-optimized using arrays or hashmaps.

---

## 🔑 Pattern 1: **Basic Trie Implementation**
Implement insert, search, and startsWith operations.

- [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

---

## 🔑 Pattern 2: **Prefix Queries / Auto-Complete**
Count or list words with a given prefix.

- [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)
- [Replace Words](https://leetcode.com/problems/replace-words/)
- [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)

---

## 🔑 Pattern 3: **Word Search in Grid using Trie**
Use Trie + DFS for efficient lookup of multiple words in a board.

- [Word Search II](https://leetcode.com/problems/word-search-ii/)
- [Boggle (GFG)](https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/)

---

## 🔑 Pattern 4: **Bitwise Trie (for XOR / Binary operations)**
Trie can be used for binary representation of numbers to solve XOR problems.

- [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
- [Trie | (Insert and Search)](https://www.geeksforgeeks.org/trie-insert-and-search/)

---

## 🔑 Pattern 5: **Count Unique Substrings using Trie**
Useful in string analysis for uniqueness and compression.

- [Count of Distinct Substrings (GFG)](https://www.geeksforgeeks.org/count-number-of-distinct-substrings-string-using-suffix-trie/)
- [Distinct Substrings](https://www.spoj.com/problems/SUBSTR/)

---

## 🔑 Pattern 6: **Palindrome Pairs**
Store reverse strings in a trie to match palindromic prefixes/suffixes.

- [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)

---

## 🔑 Pattern 7: **Advanced Applications**
Combining Trie with DFS, DP, or Bitmask for enhanced performance.

- [Concatenated Words](https://leetcode.com/problems/concatenated-words/)
- [Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/)

---

## 📌 Tips:
- Use `unordered_map<char, Node*>` for generic Trie.
- Use arrays (`Node* children[26]`) for lowercase English letters.
- Keep a `bool isEnd` flag at each node.
- Trie + DFS is powerful for board-based search problems.
- Memory-heavy; optimize with shared prefixes or compressed tries if needed.

---
