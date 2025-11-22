#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Shrink When Valid)
    -------------------------------------------------------
    Problem:
        Count the number of substrings that contain at least
        one 'a', one 'b', and one 'c'.

    Core Logic:
        As we expand the window with `right`,
        whenever the window has all 3 chars:
            freq['a'] > 0, freq['b'] > 0, freq['c'] > 0

        ANY substring starting at `left` and ending
        anywhere from `right` to `n-1` is valid.

        Therefore:
            ans += (n - right)

        After counting, shrink window by moving `left`.

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0);   // for 'a', 'b', 'c'
        int left = 0, ans = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            // When the window contains all three chars
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // For this window, all substrings [left..right], [left..right+1], ... are valid
                ans += n - right;

                // Shrink the window
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<string> tests = {
        "abcabc",     // → 10
        "aaacb",      // → 3
        "abc",        // → 1
        "aaa",        // → 0
        "abccba"      // → 9
    };

    cout << "Substrings Containing All 3 Characters - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nString: \"" << tests[i] << "\"\n";

        int result = sol.numberOfSubstrings(tests[i]);

        cout << "Result = " << result << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
