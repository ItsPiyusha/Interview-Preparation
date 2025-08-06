# 🧠 Greedy Algorithms - Patterns & Problems

Greedy algorithms make a locally optimal choice at each step with the hope that it leads to a globally optimal solution. They are often used when **the problem has an optimal substructure and a greedy choice property**.

---

## 📚 Key Greedy Patterns

### 1. **Activity Selection / Interval Scheduling**
Select the maximum number of non-overlapping intervals.

- [N Meetings in One Room (GFG)](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0)
- [Maximum Number of Events That Can Be Attended (LC #1353)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
- [Non-overlapping Intervals (LC #435)](https://leetcode.com/problems/non-overlapping-intervals/)

---

### 2. **Fractional Knapsack**
Take the most valuable items first based on ratio of value/weight.

- [Fractional Knapsack (GFG)](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)

---

### 3. **Huffman Encoding / Greedy Tree Building**
Use a greedy strategy to build an optimal prefix code.

- [Huffman Encoding (GFG)](https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1)

---

### 4. **Job Sequencing Problem**
Schedule jobs to maximize profit before deadlines.

- [Job Sequencing Problem (GFG)](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)

---

### 5. **Minimum Platforms / Overlapping Intervals**
Find the minimum resources (like platforms) required.

- [Minimum Platforms (GFG)](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1)
- [Meeting Rooms II (LC #253)](https://leetcode.com/problems/meeting-rooms-ii/)

---

### 6. **Greedy Jumping / Reaching Goal**
Make minimum steps or jumps using a greedy decision at each step.

- [Jump Game (LC #55)](https://leetcode.com/problems/jump-game/)
- [Jump Game II (LC #45)](https://leetcode.com/problems/jump-game-ii/)

---

### 7. **Greedy for String Problems**
Make lexicographically smallest/largest results using stack + greedy logic.

- [Remove K Digits (LC #402)](https://leetcode.com/problems/remove-k-digits/)
- [Smallest Subsequence of Distinct Characters (LC #1081)](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

---

### 8. **Greedy Coins / Money Change**
Use the largest denominations first.

- [Minimum Coins (GFG)](https://practice.geeksforgeeks.org/problems/number-of-coins1824/1)

---

### 9. **Gas Station Problems**
Greedily simulate circular tours.

- [Gas Station (LC #134)](https://leetcode.com/problems/gas-station/)

---

### 10. **Greedy for Scheduling / Timelines**
Greedy choice of start/end time, or deadlines.

- [IPO (LC #502)](https://leetcode.com/problems/ipo/)
- [Course Schedule III (LC #630)](https://leetcode.com/problems/course-schedule-iii/)

---

## 🧠 Tips to Identify Greedy Problems

- Problem asks for **maximum/minimum** (profit, events, jobs, platforms).
- Choices can be **sorted** based on some key property (start time, profit, deadline).
- Often solvable with **heap**, **sort**, and **greedy condition check**.
- Dynamic programming might work too, but greedy is **more efficient** if applicable.

---

## 🧰 Related Resources

- [Greedy Algorithm - TakeUForward](https://takeuforward.org/data-structure/greedy-algorithm-introduction/)
- [LeetCode Greedy Tag](https://leetcode.com/tag/greedy/)
- [GFG Greedy Archive](https://practice.geeksforgeeks.org/explore/?category%5B%5D=Greedy)

