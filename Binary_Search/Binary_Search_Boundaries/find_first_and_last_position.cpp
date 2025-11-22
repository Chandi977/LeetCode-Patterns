#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH (Lower/Upper Bound)
    -------------------------------------------------------
    We manually implement:
        - lowerBound(nums, target)
        - upperBound(nums, target)

    lowerBound:
        First index where nums[i] >= target

    upperBound:
        First index where nums[i] > target

    If lowerBound == n or nums[lowerBound] != target → target missing.
    Otherwise:
        first = lowerBound
        last = upperBound - 1
*/

class Solution {
public:

    // First index i such that nums[i] >= target
    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    // First index i such that nums[i] > target
    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);

        // If target doesn't exist
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upperBound(nums, target) - 1;

        return {first, last};
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
        {5,7,7,8,8,10},   // target=8 → [3,4]
        {5,7,7,8,8,10},   // target=6 → [-1,-1]
        {1},              // target=1 → [0,0]
        {},               // target=2 → [-1,-1]
        {2,2,2,2,2},      // target=2 → [0,4]
        {1,2,3,4,5,6}     // target=4 → [3,3]
    };

    vector<int> targets = {8, 6, 1, 2, 2, 4};

    cout << "Search Range Using Custom Bounds - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i+1 << ":\nArray: ";
        printVector(tests[i]);
        cout << "Target = " << targets[i] << "\n";

        vector<int> res = sol.searchRange(tests[i], targets[i]);

        cout << "Result = [" << res[0] << ", " << res[1] << "]\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
