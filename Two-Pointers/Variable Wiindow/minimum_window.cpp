#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Hard Version)
    --------------------------------------------------
    Problem:
        Find the smallest substring in 's' that contains
        ALL characters of 't' (including duplicates).

    Key ideas:
    - Maintain a frequency map "need[]" for all chars in t.
    - required = number of chars still needed to match t.
    - Expand right pointer to include characters.
    - Shrink left pointer to make the window minimum.
    - When required == 0 → window is VALID.

    Time Complexity:  O(|s|)
    Space Complexity: O(1)    (128 freq array)
*/

class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);

        // Count characters needed from t
        for (char c : t)
            need[c]++;

        int required = t.size();   // total characters required
        int left = 0;
        int minLen = INT_MAX;      // minimum window found so far
        int start = 0;             // starting index of best window

        // Expand window with right pointer
        for (int right = 0; right < s.size(); right++) {

            char r = s[right];

            // If r is needed, reduce required count
            if (need[r] > 0)
                required--;

            // Reduce need count — may go negative for extra chars
            need[r]--;

            // When window contains all chars of t
            while (required == 0) {

                // Update the minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char l = s[left];

                // Before removing l, increase need count
                need[l]++;

                // If l becomes required again → window no longer valid
                if (need[l] > 0)
                    required++;

                left++; // shrink window
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<pair<string,string>> tests = {
        {"ADOBECODEBANC", "ABC"},   // "BANC"
        {"a", "a"},                 // "a"
        {"a", "aa"},                // ""
        {"aa", "aa"},               // "aa"
        {"ab", "b"},                // "b"
        {"bdab", "ab"},             // "ab"
        {"bbaa", "aba"}             // "baa"
    };

    cout << "Minimum Window Substring - Test Results:\n\n";

    for (auto &p : tests) {
        string s = p.first;
        string t = p.second;

        cout << "S = \"" << s << "\"\n";
        cout << "T = \"" << t << "\"\n";
        cout << "Min Window = \"" << sol.minWindow(s, t) << "\"\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
