#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: PREFIX + SUFFIX PRODUCT
    --------------------------------------------
    Problem:
        For each index i, return product of all nums[] except nums[i].

    Constraints:
        - Cannot use division.
        - Must run in O(n).
        - Output array does NOT count as extra space.

    Approach:
        ans[i] = (product of all left numbers) × (product of all right numbers)

        Step 1: Build prefix products
            ans[i] = prefix product till i-1

        Step 2: Build suffix products and multiply into ans[i]
            ans[i] *= suffix product till i+1

    Example:
        nums = [1,2,3,4]
        prefix pass → [1,1,2,6]
        suffix pass → [24,12,8,6]

    Time:  O(n)
    Space: O(1) extra (ans[] ignored)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,2,3,4},       // → [24,12,8,6]
        {-1,1,0,-3,3},   // → [0,0,9,0,0]
        {2,3,4,5},       // → [60,40,30,24]
        {5},             // → [1]
        {1,0,1,0}        // → [0,0,0,0]
    };

    cout << "Product Except Self - Test Results\n\n";

    for (auto &nums : tests) {
        cout << "Input: ";
        printVector(nums);

        vector<int> result = sol.productExceptSelf(nums);

        cout << "Output: ";
        printVector(result);

        cout << "--------------------------------------\n";
    }

    return 0;
}
