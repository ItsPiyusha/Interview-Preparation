# Problems Asked
You're given a list of meeting time intervals, and your goal is to find the minimum number of meeting rooms required so that no meetings overlap.
'intervals = [(0,30), (5,10), (15,20)]'

**✅ Intuition:**
Each time a meeting starts, we need a room. If a meeting ends before or exactly when another starts, we can reuse the room.

# 🧠 Problem Understanding
You're given a list of intervals, where each interval represents a meeting with a start and end time. Your task is to return the minimum number of meeting rooms required so that no meetings overlap.

Example input:
```cpp
intervals = {{0, 30}, {5, 10}, {15, 20}}
Output = 2
```

# ✅ Brute Force Approach
## 🔹 Idea:
Check for overlap between every pair of meetings and maintain how many overlapping intervals exist at any time.
```
#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    int maxRooms = 0;

    for (int i = 0; i < n; ++i) {
        int rooms = 1; // Current meeting
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (!(intervals[i].second <= intervals[j].first || intervals[i].first >= intervals[j].second)) {
                rooms++;
            }
        }
        maxRooms = max(maxRooms, rooms);
    }
    return maxRooms;
}
```
# 🔸 Time Complexity: 
`O(n^2)`
# ✅ Better Approach – Using Sorting and Priority Queue (Min Heap)
## 🔹 Idea:
* Sort intervals by start time.

* Use a min heap to keep track of end times.

* Remove meetings from heap which have ended before the current meeting starts.

```
#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    // Min heap to track earliest ending meeting
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto interval : intervals) {
        // Free up rooms
        if (!minHeap.empty() && minHeap.top() <= interval.first) {
            minHeap.pop();
        }
        minHeap.push(interval.second);
    }

    return minHeap.size();
}
```
# 🔸 Time Complexity: 
`O(n log n)`

# ✅ Optimal Approach – Timeline Sweep (Chronological Ordering)

# 🔹 Idea:
* Separate start and end times.

* Sort both arrays.

* Sweep over time: increment room count for a start, decrement for an end.

```
#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    vector<int> startTimes, endTimes;

    for (auto i : intervals) {
        startTimes.push_back(i.first);
        endTimes.push_back(i.second);
    }

    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int rooms = 0, endPtr = 0;

    for (int i = 0; i < n; ++i) {
        if (startTimes[i] < endTimes[endPtr]) {
            rooms++;
        } else {
            endPtr++;
        }
    }

    return rooms;
}
```
# 🔸 Time Complexity: 
`O(n log n)`
