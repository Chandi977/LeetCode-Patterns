#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Dynamic Window)
    ---------------------------------------------------
    Problem:
        Find the length of the longest substring without repeating characters.

    Key Idea:
        Maintain a sliding window [left ... right].
        - lastSeen[ch] stores last index of character 'ch'.
        - If character repeats inside window, move left pointer.
        - Window always remains valid (no duplicates).

    Time:  O(n)
    Space: O(1)  (256 ASCII array)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);   // stores last seen position of each char
        int left = 0;                    // left pointer of sliding window
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            // If char was seen inside the current window, move left
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }

            // Update last seen position
            lastSeen[ch] = right;

            // Update max window length
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
        "abcabcbb",       // → 3
        "bbbbb",          // → 1
        "pwwkew",         // → 3
        "",               // → 0
        "au",             // → 2
        "dvdf",           // → 3
        "abba"            // → 2
    };

    cout << "Longest Substring Without Repeating Characters - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i+1 << ":\nString: \"" << tests[i] << "\"\n";

        int res = sol.lengthOfLongestSubstring(tests[i]);

        cout << "Longest Length = " << res << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
