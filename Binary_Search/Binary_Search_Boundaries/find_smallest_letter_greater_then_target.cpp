#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH
    ----------------------------------
    Problem:
        Given a sorted list of characters, find the smallest letter
        strictly greater than target. The list wraps around.

    Approach:
        Use std::upper_bound:
            - Finds first character > target
            - If iterator reaches end → wrap to first character

    Time:  O(log n)
    Space: O(1)
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        // upper_bound returns first element > target
        auto it = upper_bound(letters.begin(), letters.end(), target);

        // If no such element → wrap around
        if (it == letters.end())
            return letters[0];

        return *it;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<char>& v) {
    for (char c : v) cout << c << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<char>> tests = {
        {'c','f','j'},          // target='a' → 'c'
        {'c','f','j'},          // target='c' → 'f'
        {'c','f','j'},          // target='d' → 'f'
        {'c','f','j'},          // target='j' → 'c' (wrap)
        {'x','x','y','y'},      // target='z' → 'x' (wrap)
        {'a','b','c'},          // target='c' → 'a' (wrap)
    };

    vector<char> targets = {'a','c','d','j','z','c'};

    cout << "Next Greatest Letter - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nLetters: ";
        printVector(tests[i]);
        cout << "Target = '" << targets[i] << "'\n";

        char ans = sol.nextGreatestLetter(tests[i], targets[i]);

        cout << "Output = '" << ans << "'\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
