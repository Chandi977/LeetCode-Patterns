#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Expand + Shrink)
    -----------------------------------------------------
    Problem:
        Given an array of positive integers, find the length of the
        smallest subarray whose sum ≥ target.

    Key Observations:
        - Since all numbers are POSITIVE, once sum >= target,
          we can shrink the window safely from the left.
        - Use two pointers:
              right → expand window
              left  → shrink window until sum < target
        - Track minimum window length.

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            // Shrink window while valid
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2,3,1,2,4,3},     // target=7 → ans=2 ([4,3])
        {1,4,4},           // target=4 → ans=1
        {1,1,1,1,1},       // target=11 → ans=0
        {5,1,3,5,10,7,4,9,2,8},  // target=15 → ans=2 ([7,8] or [8,2,5?])

    };

    vector<int> targets = {7, 4, 11, 15};

    cout << "Minimum Size Subarray Sum - Test Results\n\n";

    for (int t = 0; t < tests.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nArray:  ";
        printVector(tests[t]);
        cout << "Target = " << targets[t] << "\n";

        int res = sol.minSubArrayLen(targets[t], tests[t]);
        cout << "Minimum Length = " << res << "\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}
