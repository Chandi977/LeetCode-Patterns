#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (AtMost Trick)
    --------------------------------------------------
    Problem:
        Count number of subarrays that contain EXACTLY K distinct integers.

    Key Technique:
        Use the formula:
            EXACT(K) = atMost(K) - atMost(K - 1)

    Why?
        atMost(K) counts all subarrays with ≤ K distinct integers.
        atMost(K-1) counts all subarrays with ≤ K-1 distinct integers.
        Their difference gives exactly K distinct.

    Time Complexity:  O(n)
    Space Complexity: O(n) due to frequency map
*/

class Solution {
public:
    // Count subarrays with AT MOST k distinct numbers
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // If new number entering window → reduce k
            if (freq[nums[right]] == 0)
                k--;

            freq[nums[right]]++;

            // Shrink window until it has at most k distinct numbers
            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;   // a distinct element removed
                left++;
            }

            // Add all valid subarrays ending at 'right'
            count += right - left + 1;
        }

        return count;
    }

    // EXACTLY k distinct = atMost(k) - atMost(k-1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,2,1,2,3},    // K = 2 → output 7
        {1,2},          // K = 1 → output 2
        {1,2,1,3,4},    // K = 3 → output 3
        {2,1,1,1,3,4},  // K = 2 → output 8
        {1,1,1,1}       // K = 1 → output 10
    };

    vector<int> K = {2, 1, 3, 2, 1};

    cout << "Subarrays With K Distinct Integers - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nK = " << K[i];

        int result = sol.subarraysWithKDistinct(tests[i], K[i]);

        cout << "\nResult: " << result;
        cout << "\n-------------------------------------\n";
    }

    return 0;
}
