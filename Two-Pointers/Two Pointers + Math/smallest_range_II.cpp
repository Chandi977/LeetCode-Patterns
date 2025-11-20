#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: GREEDY + SORTING
    -------------------------------------
    Problem:
        You may add or subtract k from EACH element exactly once.
        Minimize the final maximum - minimum.

    Key Insight:
        After sorting:
            nums = a0 <= a1 <= ... <= an-1

        We try a “cut” between i and i+1:
            Left part  (0...i)   → we INCREASE by k
            Right part (i+1...n-1) → we DECREASE by k

        New potential:
            maxVal = max(nums[n-1] - k, nums[i] + k)
            minVal = min(nums[0] + k, nums[i+1] - k)

        Evaluate for every i from 0 to n-2.

    Time:  O(n log n) for sort
    Space: O(1)
*/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Initial range without any changes
        int result = nums[n - 1] - nums[0];

        for (int i = 0; i < n - 1; i++) {

            // Increase left part, decrease right part
            int maxVal = max(nums[n - 1] - k, nums[i] + k);
            int minVal = min(nums[0] + k, nums[i + 1] - k);

            result = min(result, maxVal - minVal);
        }

        return result;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1},               // k=0 → answer=0
        {1,3,6},           // k=3
        {7,8,8},           // k=5
        {1,4,6,8,10},      // k=2
        {1,5,8,10}         // k=2
    };

    vector<int> k = {0, 3, 5, 2, 2};

    cout << "Smallest Range II - Test Results\n\n";

    for (int t = 0; t < tests.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nArray: ";
        printArray(tests[t]);

        cout << "k = " << k[t] << "\n";

        int ans = sol.smallestRangeII(tests[t], k[t]);

        cout << "Minimum Range: " << ans << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
