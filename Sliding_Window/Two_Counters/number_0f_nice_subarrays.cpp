#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (At Most K Condition)
    ---------------------------------------------------------
    Problem:
        Count number of subarrays that contain exactly K odd numbers.

    Key Insight:
        EXACT(K) = AtMost(K) - AtMost(K - 1)

    AtMost(K):
        Sliding window that allows at most K odd numbers.
        - Expand right pointer
        - Track odd count
        - If odd > K, shrink window from left
        - Add window size to result

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    // Count subarrays with at most K odd numbers
    int atMost(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int odd = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Count odd numbers
            if (nums[right] % 2 != 0)
                odd++;

            // Shrink window if too many odds
            while (odd > k) {
                if (nums[left] % 2 != 0)
                    odd--;
                left++;
            }

            // Add valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
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
        {1,1,2,1,1},        // k=3 → 2
        {2,4,6},            // k=1 → 0
        {2,2,2,1,2},        // k=1 → 4
        {1,2,3,4,5},        // k=2 → 4
        {1,3,5},            // k=1 → 3
    };

    vector<int> K = {3, 1, 1, 2, 1};

    cout << "Number of Nice Subarrays - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printVector(tests[i]);
        cout << "k = " << K[i] << "\n";

        int result = sol.numberOfSubarrays(tests[i], K[i]);
        cout << "Result = " << result << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
