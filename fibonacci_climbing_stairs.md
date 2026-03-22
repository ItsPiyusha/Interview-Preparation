```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 5;

    // Edge case: if n is 0, print only 0
    if (n == 0) {
        cout << 0;
    }
    // Special case: if n is 1, print first two Fibonacci numbers
    else if (n == 1) {
        cout << 0 << " " << 1 << "\n";
    }
    // General case: generate and print Fibonacci series up to nth term
    else {
        int fib[n + 1];    // Array to store Fibonacci numbers up to index n
        fib[0] = 0;
        fib[1] = 1;

        // Fill the Fibonacci series using bottom-up dynamic programming
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        for (int i = 0; i <= n; i++) {
            cout << fib[i] << " ";
        }
    }

    return 0;
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    // If n is 0, only the first Fibonacci number is printed
    if (n == 0) {
        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << 0;
    }
    else {
        int secondLast = 0; // (i-2)th term
        int last = 1;       // (i-1)th term

        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << secondLast << " " << last << " ";

        int cur; // ith term
        for (int i = 2; i <= n; i++) {
            cur = last + secondLast;   // ith Fibonacci number
            secondLast = last;         // move window forward
            last = cur;
            cout << cur << " ";
        }
    }

    return 0;
}
```


```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute the Nth Fibonacci number
int fibonacci(int N) {
    // Base case: if N is 0 or 1, return N itself
    if (N <= 1) {
        return N;
    }

    // Recursive case: sum of (N-1)th and (N-2)th Fibonacci numbers
    int last = fibonacci(N - 1);   // (N-1)th Fibonacci
    int slast = fibonacci(N - 2);  // (N-2)th Fibonacci

    return last + slast;
}

int main() {
    int N = 4;
    cout << fibonacci(N) << endl; // Output: 3 (0 1 1 2 3)
    return 0;
}
```

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate Fibonacci using memoization
    int fib(int n, vector<int>& dp) {
        // If base case return n
        if (n <= 1) return n;

        // If already computed, return stored value
        if (dp[n] != -1) return dp[n];

        // Otherwise compute and store
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }
};

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.fib(n, dp);
    return 0;
}

```

```cpp


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate Fibonacci using tabulation
    int fib(int n) {
        // If n is 0 or 1, return n
        if (n <= 1) return n;

        // Create dp array
        vector<int> dp(n + 1, 0);

        // Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Fill dp array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return final answer
        return dp[n];
    }
};

int main() {
    int n = 10;
    Solution sol;
    cout << sol.fib(n);
    return 0;
}


```

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // If n is 0 return 0
        if(n == 0) return 0;
        // If n is 1 return 1
        if(n == 1) return 1;

        // prev2 stores fib(n-2)
        int prev2 = 0;
        // prev stores fib(n-1)
        int prev = 1;
        // curr stores current fib
        int curr;

        // Loop from 2 to n
        for(int i = 2; i <= n; i++) {
            // Calculate current fib
            curr = prev + prev2;
            // Update prev2
            prev2 = prev;
            // Update prev
            prev = curr;
        }
        // Return final answer
        return prev;
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.fib(n);
    return 0;
}

```
