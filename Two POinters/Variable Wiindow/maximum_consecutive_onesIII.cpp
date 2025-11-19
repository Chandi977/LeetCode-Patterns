#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (At Most K Zeroes)
    ------------------------------------------------------
    Problem:
        Given a binary array, return the length of the longest subarray
        that contains at most K zeroes.
        (We can flip at most K zeroes into ones.)

    Approach:
        - Maintain a sliding window [left ... right].
        - zeroCount tracks number of 0s in the window.
        - Expand window by moving right.
        - If zeroCount > k, shrink from the left until valid again.
        - Track max window length.

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {

            // If a zero appears, count it
            if (nums[right] == 0)
                zeroCount++;

            // If window becomes invalid (more than k zeroes), shrink it
            while (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            // Update maximum valid window
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

    vector<vector<int>> tests = {
        {1,1,1,0,0,0,1,1,1,1,0},   // k=2 → 6
        {0,0,1,1,1,0,0},           // k=0 → 3
        {1,1,1,1},                 // k=2 → 4
        {0,0,0,0},                 // k=3 → 3
        {1,0,1,0,1,0,1}            // k=1 → 3
    };

    vector<int> K = {2, 0, 2, 3, 1};

    cout << "Max Consecutive Ones III - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nK = " << K[i];

        int result = sol.longestOnes(tests[i], K[i]);

        cout << "\nResult: " << result 
             << "\n-------------------------------------\n";
    }

    return 0;
}
