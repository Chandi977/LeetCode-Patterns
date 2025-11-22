#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Fixed Size)
    ------------------------------------------------
    Problem:
        Find the maximum number of vowels in ANY substring of length k.

    Idea:
        - Count vowels in the first k characters.
        - Slide the window:
              Add new char (right)
              Remove old char (left)
        - Track maximum count.

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:

    // Check if character is a vowel
    bool isVowel(char c) {
        c = tolower(c);  // ensure lowercase consistency
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // Count vowels in initial window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }

        int maxCount = count;

        // Slide window
        for (int i = k; i < s.size(); i++) {

            if (isVowel(s[i])) count++;       // add right char
            if (isVowel(s[i - k])) count--;   // remove left char

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<pair<string,int>> tests = {
        {"abciiidef", 3},     // → 3 ("iii")
        {"aeiou", 2},          // → 2
        {"leetcode", 3},       // → 2 ("lee")
        {"rhythms", 4},        // → 0
        {"tryhard", 4}         // → 1
    };

    cout << "Max Vowels in Substring of Length K - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {

        string s = tests[i].first;
        int k     = tests[i].second;

        cout << "Test Case " << i + 1 << ":\n";
        cout << "String: \"" << s << "\"\n";
        cout << "k = " << k << "\n";

        int ans = sol.maxVowels(s, k);

        cout << "Max Vowels = " << ans << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
