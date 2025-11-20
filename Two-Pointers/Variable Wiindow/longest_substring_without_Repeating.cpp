#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW + HASH MAP
    ----------------------------------------------
    Goal:
        Find the length of the longest substring without repeating chars.

    Intuition:
        - Maintain a sliding window [left … right].
        - Use lastSeen[ch] to remember the last index where 'ch' appeared.
        - If we see a repeat inside the current window:
              move 'left' to lastSeen[ch] + 1
        - Update window size: right - left + 1

    Key Idea:
        The window ALWAYS stays valid (no duplicates inside it).

    Time Complexity:  O(n)
    Space Complexity: O(1)  (only 256 size array)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1); // stores last index of each ASCII char

        int left = 0;        // left side of sliding window
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            // If character seen before AND is inside current window -> update left
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            // Update last seen position of current char
            lastSeen[c] = right;

            // Update maximum window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<string> tests = {
        "abcabcbb",     // output: 3 ("abc")
        "bbbbb",        // output: 1 ("b")
        "pwwkew",       // output: 3 ("wke")
        "",             // output: 0
        "au",           // output: 2
        "dvdf",         // output: 3 ("vdf")
        "abba"          // output: 2 ("ab" or "ba")
    };

    cout << "Longest Substring Without Repeating Characters - Test Results:\n\n";

    for (string &s : tests) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Longest Length = " << sol.lengthOfLongestSubstring(s);
        cout << "\n-------------------------------------\n";
    }

    return 0;
}
