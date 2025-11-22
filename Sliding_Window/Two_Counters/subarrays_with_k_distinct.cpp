#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (At Most K Distinct)
    --------------------------------------------------------
    Problem:
        Count subarrays that contain *exactly* K distinct integers.

    Key Insight:
        EXACT(K) = AtMost(K) - AtMost(K - 1)

    AtMost(K):
        Classic sliding window with a frequency map.
        - Expand right pointer
        - If new element causes >K distinct, shrink left
        - Count all valid windows ending at right

    Time:  O(n)
    Space: O(k)
*/

class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    // Count subarrays with at most K distinct numbers
    int atMost(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // If first time seeing this number -> reduces available slots of distinct
            if (freq[nums[right]] == 0)
                k--;

            freq[nums[right]]++;

            // Too many distinct -> shrink from left
            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;
                left++;
            }

            // Number of valid subarrays ending at `right`
            count += right - left + 1;
        }

        return count;
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
        {1,2,1,2,3},         // k=2 → 7
        {1,2,1,3,4},         // k=3 → 3
        {1,1,1,1},           // k=1 → 10
        {2,2,1,2,2},         // k=2 → 8
        {1,2},               // k=1 → 2
    };

    vector<int> K = {2,3,1,2,1};

    cout << "Subarrays With K Distinct Integers - Test Results\n\n";

    for (int t = 0; t < tests.size(); t++) {
        cout << "Test Case " << t + 1 << "\nArray: ";
        printVector(tests[t]);

        cout << "k = " << K[t] << "\n";

        int ans = sol.subarraysWithKDistinct(tests[t], K[t]);

        cout << "Result = " << ans << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
