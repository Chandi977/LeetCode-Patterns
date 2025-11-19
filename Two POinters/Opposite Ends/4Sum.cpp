#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SORTING + DOUBLE NESTED LOOPS + TWO POINTERS
    ------------------------------------------------------------------
    Why this works:
    - Fix nums[i] and nums[j] as first two numbers of quadruplet.
    - Then use two pointers (left, right) to find remaining two numbers.
    - Sorting helps us:
        ✓ avoid duplicates easily
        ✓ use the two-pointer technique efficiently
        ✓ maintain non-decreasing order quadruplets

    Time Complexity:  O(n^3)
    Space Complexity: O(1) excluding output
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end()); // required for 2-pointer + duplicate skipping
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Skip duplicates for the 1st index
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {

                // Skip duplicates for the 2nd index
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long remaining = (long long)target - nums[i] - nums[j];

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];

                    if (sum == remaining) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        int lastLeft = nums[left];
                        int lastRight = nums[right];

                        // Skip duplicate 3rd value
                        while (left < right && nums[left] == lastLeft) left++;

                        // Skip duplicate 4th value
                        while (left < right && nums[right] == lastRight) right--;
                    }
                    else if (sum < remaining) {
                        left++;    // need larger sum
                    }
                    else {
                        right--;   // need smaller sum
                    }
                }
            }
        }

        return result;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> testArrays = {
        {1, 0, -1, 0, -2, 2},
        {2, 2, 2, 2, 2},
        {-3, -1, 0, 2, 4, 5},
        {1000000000, 1000000000, -1000000000, -1000000000}, // overflow test
    };

    vector<int> targets = {
        0,
        8,
        2,
        0
    };

    for (int t = 0; t < testArrays.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nInput: ";
        for (int x : testArrays[t]) cout << x << " ";
        cout << "\nTarget = " << targets[t] << "\nOutput:\n";

        vector<vector<int>> ans = sol.fourSum(testArrays[t], targets[t]);

        for (auto &quad : ans) {
            cout << "[ ";
            for (int x : quad) cout << x << " ";
            cout << "]\n";
        }

        cout << "-----------------------------\n";
    }

    return 0;
}
