#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
// Check all substrings and verify if they have all unique characters
int lengthOfLongestSubstringBrute(string s) {
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        unordered_set<char> seen;// to track unique characters
        for (int j = i; j < s.size(); j++) {
            if (seen.count(s[j])) break;// stop if character repeats
            seen.insert(s[j]); // Add current character to set
            maxLen = max(maxLen, j - i + 1);// update max length
        }
    }
    return maxLen;
}
//Optimized version using sliding window technique
int lengthOfLongestSubstringBetter(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.length()) {
        // While there is a duplicate character
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }

        // Now the character at right is not in set → add it
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}


// Optimized version using a hash map to track last seen indices
#include<unordered_map> 
int lengthOfLongestSubstringBest(string s) {
    unordered_map<char, int> lastSeen;// Stores last index where character was seen
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        char ch = s[right];
        // If the character was seen and is within the current window
        if (lastSeen.count(ch) && lastSeen[ch] >= left) {
            // Duplicate found, move left beyond last occurrence
            left = lastSeen[ch] + 1;
            // Move left pointer right after the last occurrence
        }

        lastSeen[ch] = right;// Update last seen index of current character
        maxLen = max(maxLen, right - left + 1);// Update max length
    }

    return maxLen;
}


int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = lengthOfLongestSubstringBrute(s);
    int result = lengthOfLongestSubstringBetter(s);
    int result = lengthOfLongestSubstringBest(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}