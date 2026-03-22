# 1) Separate “difficult” into 3 types
Most “difficult” problems are hard for one of these reasons:

1. **Pattern not recognized** (you don’t know what tool to use)
2. **Pattern known but modeling unclear** (can’t map problem → state/invariant/graph)
3. **Implementation heavy** (you know the approach but code is tricky)
  
Your strategy depends on which one it is.

# 2) A forced-progress workflow (what to do when stuck)
Use this exact loop:

## Step A: Bruteforce + constraints (10 minutes)
* Write the brute force approach in words.
* Estimate its complexity.
* Use constraints to rule it out and infer target:
  * n ≤ 2000 → maybe O(n^2)
  * n ≤ 1e5 → O(n log n) or O(n)
   * grid m*n ≤ 1e5 → BFS/DFS
Even if you can’t solve, this tells you what category of solution is possible.

## Step B: Ask 5 “pattern triggers” (5 minutes)
1. **Need subarray/substring with condition?** → sliding window / prefix sums
2. **Need “best/least” with monotonic property?** → binary search on answer
3. **Decisions over positions / choose or skip?** → DP
4. **Dependencies like “A before B” / connectedness?** → graph
5. **Nearest greater/smaller / ranges?** → monotonic stack
Pick one to try. Don’t try 10 approaches.

## Step C: Reduce the problem
If full problem is hard, solve a smaller version:

* smaller constraints
* remove one condition
* compute only value not reconstruction
* fixed window size before variable size
This often reveals the invariant/state.

## Step D: If still stuck: take a hint, not the whole solution
Good “minimal hints” to seek:

* “What’s the right data structure?”
* “Is this DP? what’s the state?”
* “Is there a monotonic property?” Then attempt again.
# 3) How to learn from hard problems (so the next one is easier)
Reading solutions is fine, but only if you convert it into a reusable pattern.

After you read an editorial, write 4 lines:

* **Pattern:** (e.g., “binary search on answer + greedy check”)
* **Invariant/state:** (what must always be true)
* **Core implementation template:** (2–5 key lines)
* **Edge cases:** (2 items)
Then re-solve tomorrow. This is non-negotiable if you want improvement.

# 4) The 6 “meta-patterns” behind many difficult problems
If you master these, many “difficult” problems stop being mysterious:

## 1) Binary search on answer
Used when you can check feasibility for a candidate answer.

Typical wording: “minimize the maximum”, “maximize the minimum”
Structure: bs(low, high) + can(mid) greedy
## 2) DP with state compression / optimized transitions
Hardness is often: defining state and transition.

Ask: what are the independent variables?
Try: dp[i] or dp[i][k] meaning “best up to i with condition k”
## 3) Monotonic stack / next greater element
Used for “nearest greater/smaller” and range contributions.

## 4) Prefix sums + hashmap (counting subarrays)
Used for “number of subarrays with sum/condition”.

## 5) Graph shortest paths / BFS layering
Hardness is often modeling: decide what a node is.

## 6) Greedy + proof (exchange argument)
Hardness is justifying why local choice works.

# 5) Interview-specific advice: don’t grind “hard” too early
For interviews, “difficult” often feels hard because foundations aren’t automatic. If Easy/Medium patterns aren’t fluent, Hard will be slow and discouraging.

A good ladder:

* 2 weeks: Easy + core templates until implementation is fast
* next: Medium pattern-focused
* then: selected Hards per company/topic
# 6) What to do right now (action plan)
If you want faster progress starting today:

1. Pick one topic (arrays + hashing, sliding window, trees, etc.)
2. Do 5 problems of the same pattern back-to-back (not random)
3. For each: outline → code → test → 4-line summary
4. Re-solve the failed ones tomorrow
This “batch by pattern” is the quickest way to make hard problems feel repetitive.

# The universal 3-step method
## A) Detect the pattern (fast classifier)
Ask these questions in order (takes ~60 seconds):

1. **Is it about subarray/substring + condition like longest/shortest/count?**
→ Sliding window or prefix sums

2. **Is it “count number of subarrays with sum/equals K” or “0/1 constraints”?**
→ Prefix sum + hashmap

3. **Is it “next greater/smaller”, “span”, “contribution of each element”?**
→ Monotonic stack

4. **Is it “minimize maximum / maximize minimum / capacity / days”?**
→ Binary search on answer + feasibility check

5. **Is it “choices over time/position”, “best score”, “min cost”?**
→ DP (state = index + extra dimension like remaining/prev/holding)

6. **Is it shortest steps on grid/graph with equal edges?**
→ BFS

Once one matches, commit and proceed. Don’t keep switching.

## B) Derive the invariant/state (the “why it works”)
Each pattern has a standard thing you must define:

* **Sliding window:** what property must be true for window [l..r] to be “valid” (the invariant)?
* **Prefix sum + hashmap:** what does freq[prefix] represent? why does prefix[j]-prefix[i]=k help?
* **Binary search on answer:** what is can(mid) and why is it monotonic?
* **DP:** define dp[state] in one sentence, then write transition.
* **BFS:** what is a node? what is an edge? what is visited/dist?
If you can’t say the invariant/state in one sentence, implementation will be messy.

C) Translate into clean C++ structure
For interviews, keep it consistent:

* Write a helper bool valid(...) / bool can(mid) for checks.
* Keep one loop controlling window/scan.
* Name variables by role: l, r, sum, cnt, freq, ans.
* Handle edge cases early.
* Use long long for sums by default in array sum problems.
