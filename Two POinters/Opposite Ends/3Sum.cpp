#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SORTING + TWO POINTERS
    --------------------------------------------
    Why this works:
    1. After sorting, nums[i] becomes the fixed first number.
    2. For each nums[i], we use two pointers (left, right) to find
       pairs such that:
            nums[i] + nums[left] + nums[right] == 0
    3. Sorting allows:
       - Skipping duplicates easily
       - Using two-pointer shrink technique

    Time Complexity:  O(n^2)
    Space Complexity: O(1) (ignoring output)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;   // stores all unique valid triplets
        
        sort(nums.begin(), nums.end());  // critical step

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Avoid duplicate triplets by skipping identical nums[i]
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // 🎯 FOUND a valid triplet
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Store current values
                    int lastLeft = nums[left];
                    int lastRight = nums[right];

                    // Skip all duplicates for left pointer
                    while (left < right && nums[left] == lastLeft)
                        left++;

                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == lastRight)
                        right--;
                }

                else if (sum > 0) {
                    // sum too large → decrease it
                    right--;
                }

                else {
                    // sum too small → increase it
                    left++;
                }
            }
        }

        return result;
    }
};


// ---------------------------------------------
//                    MAIN
// ---------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0, 0},
        {3, -2, 1, 0},
        {-2, 0, 1, 1, 2}
    };

    for (int t = 0; t < tests.size(); t++) {

        cout << "Test Case " << t + 1 << ":\nInput: ";
        for (int x : tests[t]) cout << x << " ";
        cout << "\nOutput:\n";

        vector<vector<int>> ans = sol.threeSum(tests[t]);

        for (auto &triplet : ans) {
            cout << "[ ";
            for (int x : triplet) cout << x << " ";
            cout << "]\n";
        }

        cout << "-------------------------\n";
    }

    return 0;
}
