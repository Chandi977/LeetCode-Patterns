#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (Fixed Size)
    ------------------------------------------------
    Problem:
        Find the contiguous subarray of length k that has the maximum average.

    Key Idea (Fixed Window):
        - Compute sum of first k elements.
        - Slide the window:
              windowSum += nums[i] - nums[i-k]
        - Track the maximum window sum.
        - Average = maxSum / k

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        long long windowSum = 0;

        // Initial window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        // Slide window across array
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
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
        {1,12,-5,-6,50,3},      // k=4 → 12.75
        {5},                    // k=1 → 5
        {0,4,0,3,2},            // k=1 → 4
        {-1,-12,-5,-6},         // k=2 → -3
        {7,7,7,7,7}             // k=3 → 7
    };

    vector<int> K = {4,1,1,2,3};

    cout << "Maximum Average Subarray I - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printArray(tests[i]);
        cout << "k = " << K[i] << "\n";

        double ans = sol.findMaxAverage(tests[i], K[i]);

        cout << fixed << setprecision(5);
        cout << "Maximum Average = " << ans << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
