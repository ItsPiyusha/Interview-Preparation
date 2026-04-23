# 30-Hour Interview Prep Plan

## Hour Allocation

| Block | Hours | Focus |
|-------|-------|-------|
| **Java Core** | 5 | Fundamentals that get asked every time |
| **DSA/Coding** | 12 | Patterns + LeetCode practice |
| **Spring Boot** | 5 | Key concepts for design discussions |
| **AWS/Cloud** | 4 | Services you must be able to draw on a whiteboard |
| **System Design** | 4 | 2 full mock designs end-to-end |

---

## 🕐 Detailed Breakdown

### Block 1 — Java Core (5 hrs)

| Hr | Topic | What to nail |
|----|-------|-------------|
| 1 | OOP + SOLID | Explain each principle with a real example |
| 2 | Collections internals | HashMap (hashing, collisions, resize at 0.75), ConcurrentHashMap vs synchronized map |
| 3 | Concurrency | `volatile` vs `synchronized`, `ExecutorService`, `CompletableFuture` chaining |
| 4 | Java 8+ | Streams (`map/filter/reduce/collect`), `Optional`, functional interfaces |
| 5 | Memory + Immutability | GC basics (G1), string pool, how to create an immutable class |

### Block 2 — DSA/Coding (12 hrs)

**Focus on only 6 high-ROI patterns** — 2 hrs each (learn pattern + solve 2–3 problems):

| Hr | Pattern | Must-Do LeetCode |
|----|---------|-------------------|
| 1–2 | **HashMap/Set** | Two Sum (#1), Group Anagrams (#49), Subarray Sum = K (#560) |
| 3–4 | **Two Pointers** | 3Sum (#15), Container With Most Water (#11) |
| 5–6 | **Sliding Window** | Longest Substring Without Repeating (#3), Max Subarray of Size K |
| 7–8 | **BFS/DFS + Trees** | Number of Islands (#200), LCA of BST (#235), Level Order (#102) |
| 9–10 | **Binary Search** | Search Rotated Array (#33), Find Peak (#162) |
| 11–12 | **DP (basics only)** | Climbing Stairs (#70), Coin Change (#322), LCS (#1143) |

> ⚡ **Rule:** If stuck > 15 min, read the solution, understand it, then re-code from scratch.

### Block 3 — Spring Boot (5 hrs)

| Hr | Topic |
|----|-------|
| 1 | Auto-config, `@Component` vs `@Bean`, DI, profiles |
| 2 | REST APIs — `@RestController`, `@ControllerAdvice`, `@Valid` |
| 3 | `@Transactional` (propagation, isolation), JPA N+1, pagination |
| 4 | Spring Security basics — filter chain, JWT flow |
| 5 | Testing — `@WebMvcTest`, `@MockBean`, Mockito essentials |

### Block 4 — AWS/Cloud (4 hrs)

| Hr | Services | One-liner to remember |
|----|----------|----------------------|
| 1 | EC2, ECS/Fargate, Lambda | VMs → Containers → Serverless spectrum |
| 2 | S3, RDS/Aurora, DynamoDB | Object store, relational, key-value; know when to pick which |
| 3 | SQS, SNS, EventBridge | Decouple with queues, fan-out with topics, event-driven with bus |
| 4 | ElastiCache, ALB, API Gateway, IAM | Caching, routing, auth — glue it all in design |

### Block 5 — System Design (4 hrs)

| Hr | Do this |
|----|---------|
| 1 | Learn the framework: **Clarify → API → Data → High-Level → Deep Dive → Trade-offs** |
| 2 | Design a **URL Shortener** end-to-end (base62, read-heavy caching with Redis, DynamoDB) |
| 3 | Design a **Notification Service** (SNS fan-out, SQS per channel, retry with DLQ, rate limiting) |
| 4 | Re-draw both from memory under a 35-min timer |

---

## 🎯 Top 10 Questions You WILL Get Asked

| # | Question |
|---|----------|
| 1 | How does HashMap work internally? What happens on collision? |
| 2 | Explain `volatile` vs `synchronized` |
| 3 | What are SOLID principles? Give real examples |
| 4 | How does Spring Boot auto-configuration work? |
| 5 | Explain `@Transactional` propagation levels |
| 6 | SQS vs SNS — when to use which? |
| 7 | How would you handle the N+1 query problem? |
| 8 | Design a URL shortener at scale |
| 9 | How do you secure a REST API? |
| 10 | Explain CAP theorem with a real AWS example |

---

# 🎯 Top 25 Must-Do for Amazon SDE 2
1, 2, 3, 5, 15, 21, 23, 42, 49, 56, 127, 139, 146, 200, 207, 215, 236, 238, 253, 273, 295, 297, 347, 937, 994

Also, here are the **1:1 C++ → Java mappings** you’ll use constantly during conversion:

- `vector<int>` → `int[]` or `ArrayList<Integer>`
- `unordered_map<int,int>` → `HashMap<Integer,Integer>`
- `unordered_set<int>` → `HashSet<Integer>`
- `queue<int>` → `ArrayDeque<Integer>`
- `stack<int>` → `ArrayDeque<Integer>` (use `push/pop/peek`)
- `priority_queue<int>` → `PriorityQueue<Integer>` (min-heap by default; use comparator for max-heap)
- `long long` → `long`
- `INT_MAX` → `Integer.MAX_VALUE`


```java
import java.util.*;

class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt(); // number of test cases
        while (t-- > 0) {
            int n = sc.nextInt();      // size of array
            int target = sc.nextInt(); // target sum

            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();

            // Two Sum using HashMap: value -> index
            HashMap<Integer, Integer> map = new HashMap<>();
            int ans1 = -1, ans2 = -1;

            for (int i = 0; i < n; i++) {
                int need = target - a[i];
                if (map.containsKey(need)) {
                    ans1 = map.get(need);
                    ans2 = i;
                    break;
                }
                map.put(a[i], i);
            }

            if (ans1 == -1) {
                System.out.println("-1");              // no pair found
            } else {
                System.out.println(ans1 + " " + ans2); // 0-based indexes
                // If you want 1-based indexes, print: (ans1+1) + " " + (ans2+1)
            }
        }

        sc.close();
    }
}
```
```java
import java.util.*;
import java.io.*;

class Codechef {
    // Node definition (since CodeChef won't provide ListNode like LeetCode)
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    // Add two numbers represented by linked lists in reverse order
    static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int sum = carry;

            if (l1 != null) { sum += l1.val; l1 = l1.next; }
            if (l2 != null) { sum += l2.val; l2 = l2.next; }

            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            carry = sum / 10;
        }
        return dummy.next;
    }

    // Helper: build linked list from a string of digits (normal order), but store in reverse order
    // Example input "342" -> list 2->4->3
    static ListNode buildReverseListFromString(String s) {
        ListNode head = null;
        for (int i = 0; i < s.length(); i++) {
            int digit = s.charAt(i) - '0';
            ListNode node = new ListNode(digit);
            node.next = head;
            head = node;
        }
        return head;
    }

    // Helper: print list as digits in reverse order (like LeetCode output format: 7 0 8 ...)
    static void printList(ListNode head) {
        boolean first = true;
        while (head != null) {
            if (!first) System.out.print(" ");
            System.out.print(head.val);
            first = false;
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Example input format for CodeChef (you can change as per problem):
        // t
        // num1
        // num2
        // where num1 and num2 are strings like 342 465
        int t = sc.nextInt();
        while (t-- > 0) {
            String num1 = sc.next();
            String num2 = sc.next();

            ListNode l1 = buildReverseListFromString(num1);
            ListNode l2 = buildReverseListFromString(num2);

            ListNode ans = addTwoNumbers(l1, l2);
            printList(ans);
        }

        sc.close();
    }
}
```

21 – Merge Two Sorted Lists (linked list, two pointers)  
937 – Reorder Data in Log Files (custom sorting)  
49 – Group Anagrams (hashing / canonical key)  
238 – Product of Array Except Self (prefix/suffix products)  
347 – Top K Frequent Elements (heap or bucket sort)  
146 – LRU Cache (hash map + doubly linked list)  
56 – Merge Intervals (sort + merge)  
215 – Kth Largest Element in an Array (heap or quickselect)  
253 – Meeting Rooms II (min-heap / sweep line)  
42 – Trapping Rain Water (two pointers or monotonic stack)  
273 – Integer to English Words (implementation-heavy recursion)  
295 – Find Median from Data Stream (two heaps + invariants)  
200 – Number of Islands (DFS/BFS grid traversal)  
994 – Rotting Oranges (multi-source BFS on grid)  
139 – Word Break (DP over indices)  
127 – Word Ladder (BFS + intermediate patterns)  
207 – Course Schedule (topological sort / cycle detection)  
236 – Lowest Common Ancestor of a Binary Tree (tree recursion)  
297 – Serialize and Deserialize Binary Tree (tree traversal + encoding/decoding edge cases)  

```java
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // Dummy node to start the merged list
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;

        // While both lists have nodes, take the smaller one
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;      // splice list1 node
                list1 = list1.next;     // advance list1
            } else {
                tail.next = list2;      // splice list2 node
                list2 = list2.next;     // advance list2
            }
            tail = tail.next;           // advance tail
        }

        // Append the remaining nodes (only one of these is non-null)
        tail.next = (list1 != null) ? list1 : list2;

        return dummy.next;
    }
}
```

```java
import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            char[] ch = s.toCharArray();
            Arrays.sort(ch);                 // pattern recognition step
            String key = new String(ch);     // key = sorted letters

            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
```
```java
import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            int[] freq = new int[26];
            for (char c : s.toCharArray()) {
                freq[c - 'a']++;
            }

            StringBuilder key = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                key.append('#').append(freq[i]);
            }

            map.putIfAbsent(key.toString(), new ArrayList<>());
            map.get(key.toString()).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
```
```java
import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
	public int ladderLength(String beginword, String endword, List<String> wordList)
	{
		// your code goes here
		Set<String> dict = new HashSet<>(wordList);
		if(!dict.contains(endword)) return 0;
		Map<String, List<String>> patternToWords = new HashMap<>();
		int L = beginword.length();
		
		for(String word :dict){
		    for(int i = 0; i < L; i++){
		        String pattern = word.substring(0,i) + "*" + word.substring(i+1);
		        patternToWords.computeIfAbsent(pattern, k-> new ArrayList<>()).add(word);
		    }
		}
		
		
		
		//BFS
		Queue<String> q = new ArrayDeque<>();
		q.offer(beginword);
		Set<String> visited = new HashSet<>();
		visited.add(beginword);
		int distance = 1;
		while(!q.isEmpty()){
		    int size = q.size();
		    for(int s = 0; s < size; s++){
		        String cur = q.poll();
		        if(cur.equals(endword)) return distance;
		        for(int i = 0; i < L; i++){
		            String pattern = cur.substring(0,i) + "*" + cur.substring(i+1);
		            List<String> neighbors = patternToWords.getOrDefault(pattern, Collections.emptyList());
		            for(String next : neighbors){
		                if(!visited.contains(next)){
		                    visited.add(next);
		                    q.offer(next);
		                }
		            }
		        }
		    }
		    distance++;
		}
		return 0;

	}
}
```
I can do that, but I need one clarification first: do you want **(A)** “just code” solutions (no explanation) and **(B)** LeetCode-style class/method signatures (e.g., `class Solution { ... }`)?

Meanwhile, below are **simple Java reference implementations** (kept as straightforward as possible). Some are “premium” on LeetCode (e.g., 937) but the core logic is the same.

---

## 937 – Reorder Data in Log Files
```java name=LC937_ReorderDataInLogFiles.java
import java.util.*;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (a, b) -> {
            int i = a.indexOf(' ');
            int j = b.indexOf(' ');
            String ida = a.substring(0, i), ca = a.substring(i + 1);
            String idb = b.substring(0, j), cb = b.substring(j + 1);

            boolean da = Character.isDigit(ca.charAt(0));
            boolean db = Character.isDigit(cb.charAt(0));
            if (!da && !db) {
                int cmp = ca.compareTo(cb);
                if (cmp != 0) return cmp;
                return ida.compareTo(idb);
            }
            if (da && db) return 0;      // keep original order for digit logs
            return da ? 1 : -1;          // letter logs first
        });
        return logs;
    }
}
```

## 238 – Product of Array Except Self
```java name=LC238_ProductOfArrayExceptSelf.java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = 1;

        for (int i = 1; i < n; i++) ans[i] = ans[i - 1] * nums[i - 1];

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
}
```

## 347 – Top K Frequent Elements
```java name=LC347_TopKFrequentElements.java
import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) freq.put(x, freq.getOrDefault(x, 0) + 1);

        List<Integer>[] buckets = new List[nums.length + 1];
        for (var e : freq.entrySet()) {
            int f = e.getValue();
            if (buckets[f] == null) buckets[f] = new ArrayList<>();
            buckets[f].add(e.getKey());
        }

        int[] ans = new int[k];
        int idx = 0;
        for (int f = buckets.length - 1; f >= 0 && idx < k; f--) {
            if (buckets[f] == null) continue;
            for (int val : buckets[f]) {
                ans[idx++] = val;
                if (idx == k) break;
            }
        }
        return ans;
    }
}
```

## 146 – LRU Cache
```java name=LC146_LRUCache.java
import java.util.*;

class LRUCache {
    static class Node {
        int k, v;
        Node prev, next;
        Node(int k, int v) { this.k = k; this.v = v; }
    }

    private final int cap;
    private final Map<Integer, Node> map = new HashMap<>();
    private final Node head = new Node(0, 0); // dummy
    private final Node tail = new Node(0, 0); // dummy

    public LRUCache(int capacity) {
        this.cap = capacity;
        head.next = tail; tail.prev = head;
    }

    public int get(int key) {
        Node n = map.get(key);
        if (n == null) return -1;
        moveToFront(n);
        return n.v;
    }

    public void put(int key, int value) {
        Node n = map.get(key);
        if (n != null) {
            n.v = value;
            moveToFront(n);
            return;
        }
        if (map.size() == cap) {
            Node lru = tail.prev;
            remove(lru);
            map.remove(lru.k);
        }
        Node nn = new Node(key, value);
        addFront(nn);
        map.put(key, nn);
    }

    private void moveToFront(Node n) { remove(n); addFront(n); }

    private void addFront(Node n) {
        n.next = head.next; n.prev = head;
        head.next.prev = n;
        head.next = n;
    }

    private void remove(Node n) {
        n.prev.next = n.next;
        n.next.prev = n.prev;
    }
}
```

## 56 – Merge Intervals
```java name=LC56_MergeIntervals.java
import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        int[] cur = intervals[0];

        for (int i = 1; i < intervals.length; i++) {
            int[] in = intervals[i];
            if (in[0] <= cur[1]) cur[1] = Math.max(cur[1], in[1]);
            else { res.add(cur); cur = in; }
        }
        res.add(cur);
        return res.toArray(new int[res.size()][]);
    }
}
```

## 215 – Kth Largest Element in an Array
```java name=LC215_KthLargestElement.java
import java.util.*;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // min-heap
        for (int x : nums) {
            pq.offer(x);
            if (pq.size() > k) pq.poll();
        }
        return pq.peek();
    }
}
```

## 253 – Meeting Rooms II
```java name=LC253_MeetingRoomsII.java
import java.util.*;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        if (intervals.length == 0) return 0;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> ends = new PriorityQueue<>();
        ends.offer(intervals[0][1]);

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= ends.peek()) ends.poll();
            ends.offer(intervals[i][1]);
        }
        return ends.size();
    }
}
```

## 42 – Trapping Rain Water
```java name=LC42_TrappingRainWater.java
class Solution {
    public int trap(int[] h) {
        int l = 0, r = h.length - 1;
        int leftMax = 0, rightMax = 0, ans = 0;

        while (l < r) {
            if (h[l] <= h[r]) {
                if (h[l] >= leftMax) leftMax = h[l];
                else ans += leftMax - h[l];
                l++;
            } else {
                if (h[r] >= rightMax) rightMax = h[r];
                else ans += rightMax - h[r];
                r--;
            }
        }
        return ans;
    }
}
```

## 273 – Integer to English Words
```java name=LC273_IntegerToEnglishWords.java
class Solution {
    private static final String[] BELOW_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private static final String[] TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).trim();
    }

    private String helper(int n) {
        if (n == 0) return "";
        if (n < 20) return BELOW_20[n] + " ";
        if (n < 100) return TENS[n / 10] + " " + helper(n % 10);
        if (n < 1000) return BELOW_20[n / 100] + " Hundred " + helper(n % 100);
        if (n < 1_000_000) return helper(n / 1000) + "Thousand " + helper(n % 1000);
        if (n < 1_000_000_000) return helper(n / 1_000_000) + "Million " + helper(n % 1_000_000);
        return helper(n / 1_000_000_000) + "Billion " + helper(n % 1_000_000_000);
    }
}
```

## 295 – Find Median from Data Stream
```java name=LC295_FindMedianFromDataStream.java
import java.util.*;

class MedianFinder {
    private final PriorityQueue<Integer> low = new PriorityQueue<>(Collections.reverseOrder()); // max-heap
    private final PriorityQueue<Integer> high = new PriorityQueue<>(); // min-heap

    public void addNum(int num) {
        if (low.isEmpty() || num <= low.peek()) low.offer(num);
        else high.offer(num);

        if (low.size() > high.size() + 1) high.offer(low.poll());
        if (high.size() > low.size()) low.offer(high.poll());
    }

    public double findMedian() {
        if (low.size() == high.size()) return (low.peek() + high.peek()) / 2.0;
        return low.peek();
    }
}
```

## 200 – Number of Islands
```java name=LC200_NumberOfIslands.java
class Solution {
    public int numIslands(char[][] g) {
        int m = g.length, n = g[0].length, count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == '1') {
                    count++;
                    dfs(g, i, j);
                }
            }
        }
        return count;
    }

    private void dfs(char[][] g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.length || j >= g[0].length || g[i][j] != '1') return;
        g[i][j] = '0';
        dfs(g, i + 1, j);
        dfs(g, i - 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
}
```

## 994 – Rotting Oranges
```java name=LC994_RottingOranges.java
import java.util.*;

class Solution {
    public int orangesRotting(int[][] g) {
        int m = g.length, n = g[0].length;
        ArrayDeque<int[]> q = new ArrayDeque<>();
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 2) q.offer(new int[]{i, j});
                else if (g[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.isEmpty() && fresh > 0) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                int[] cur = q.poll();
                for (int[] d : dirs) {
                    int ni = cur[0] + d[0], nj = cur[1] + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || g[ni][nj] != 1) continue;
                    g[ni][nj] = 2;
                    fresh--;
                    q.offer(new int[]{ni, nj});
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
}
```

## 139 – Word Break
```java name=LC139_WordBreak.java
import java.util.*;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> set = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
```

## 207 – Course Schedule
```java name=LC207_CourseSchedule.java
import java.util.*;

class Solution {
    public boolean canFinish(int n, int[][] pre) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) g.add(new ArrayList<>());
        int[] indeg = new int[n];

        for (int[] p : pre) {
            int a = p[0], b = p[1];
            g.get(b).add(a);
            indeg[a]++;
        }

        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.offer(i);

        int done = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            done++;
            for (int v : g.get(u)) {
                if (--indeg[v] == 0) q.offer(v);
            }
        }
        return done == n;
    }
}
```

## 236 – Lowest Common Ancestor of a Binary Tree
```java name=LC236_LCAofBinaryTree.java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) return root;
        return left != null ? left : right;
    }
}

// LeetCode-provided:
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
```

## 297 – Serialize and Deserialize Binary Tree
```java name=LC297_SerializeDeserializeBinaryTree.java
import java.util.*;

class Codec {
    // serialize: level-order with "null"
    public String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder sb = new StringBuilder();
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur == null) {
                sb.append("null,");
                continue;
            }
            sb.append(cur.val).append(",");
            q.offer(cur.left);
            q.offer(cur.right);
        }
        return sb.toString();
    }

    public TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        String[] a = data.split(",");
        int idx = 0;

        TreeNode root = new TreeNode(Integer.parseInt(a[idx++]));
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while (!q.isEmpty() && idx < a.length) {
            TreeNode cur = q.poll();
            if (cur == null) continue;

            String left = a[idx++];
            if (!left.equals("null")) {
                cur.left = new TreeNode(Integer.parseInt(left));
                q.offer(cur.left);
            } else q.offer(null);

            if (idx >= a.length) break;
            String right = a[idx++];
            if (!right.equals("null")) {
                cur.right = new TreeNode(Integer.parseInt(right));
                q.offer(cur.right);
            } else q.offer(null);
        }
        return root;
    }
}

// LeetCode-provided:
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
```

---

If you answer these 2 quick questions, I can tailor the output exactly:
1) Do you want **only the `Solution` / required classes**, or also a `main()` to run locally?
2) For #297, do you prefer **preorder DFS** (often shorter) instead of BFS?
