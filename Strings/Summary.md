# 📚 Important String Patterns for Coding Interviews

## 1. Sliding Window

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [Permutation in String](https://leetcode.com/problems/permutation-in-string/)
- [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

## 2. Two Pointers

- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [Reverse String](https://leetcode.com/problems/reverse-string/)

## 3. HashMap/Frequency Count

- [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
- [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## 4. Pattern Matching

- [Word Pattern](https://leetcode.com/problems/word-pattern/)
- [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

## 5. String Building and Manipulation

- [Multiply Strings](https://leetcode.com/problems/multiply-strings/)
- [Add Binary](https://leetcode.com/problems/add-binary/)

## 6. Trie / Prefix Matching

- [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [Replace Words](https://leetcode.com/problems/replace-words/)



| STL Container        | `.count(x)` returns | Notes                                            |
| -------------------- | ------------------- | ------------------------------------------------ |
| `set<T>`             | `0` or `1`          | Stores unique keys only                          |
| `unordered_set<T>`   | `0` or `1`          | Same as `set` but faster (hash-based)            |
| `map<K, V>`          | `0` or `1`          | Checks if key `K` exists                         |
| `unordered_map<K,V>` | `0` or `1`          | Same for hash maps                               |
| `multiset<T>`        | `>= 0`              | Can return >1 because multiset allows duplicates |
| `multimap<K,V>`      | `>= 0`              | Same logic                                       |


| Feature            | `.count(x)`                                        | `.find(x)`                                        |
| ------------------ | -------------------------------------------------- | ------------------------------------------------- |
| ✅ Purpose          | Checks if element exists (returns count)           | Returns **iterator** to element if found          |
| 🔁 Return Type     | `int` (0 or 1 in `set`/`map`, ≥0 in `multi*`)      | `iterator` (points to element or `.end()`)        |
| 🧠 Use Case        | When you only need **existence check**             | When you want to **access or delete** the element |
| ⚡ Time Complexity  | O(1) avg for `unordered_*`, O(log n) for `set/map` | Same as `.count()`                                |
| 🧽 Code Simplicity | Simpler for condition checks                       | More control (useful for modifying)               |


💬 In Interviews: How to Explain
"I use .count() when I just need to check if a character has already been seen.
It’s fast and clear. If I need to modify or delete the element, I use .find() to get the iterator."