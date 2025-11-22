#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH (Lower/Upper Bound)
    ------------------------------------------------------
    Problem:
        Given a sorted array, find the FIRST and LAST position
        of a target value.

    Idea:
        Use two modified binary searches:
            - findFirst() : move right pointer (r = mid - 1) on match
            - findLast()  : move left pointer  (l = mid + 1) on match

        If first position is -1 → target not found.

    Time:  O(log n)
    Space: O(1)
*/

class Solution {
public:

    // Find first (leftmost) position of target
    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans = mid;
                r = mid - 1;   // keep searching left
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }

    // Find last (rightmost) position of target
    int findLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;   // keep searching right
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) 
            return {-1, -1};   // target not found

        int last = findLast(nums, target);
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
        {5,7,7,8,8,10},    // target=8 → [3,4]
        {5,7,7,8,8,10},    // target=6 → [-1,-1]
        {1},               // target=1 → [0,0]
        {1,2,3,4,4,4,5},   // target=4 → [3,5]
        {},                // target=0 → [-1,-1]
    };

    vector<int> targets = {8, 6, 1, 4, 0};

    cout << "First & Last Position of Target - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printVector(tests[i]);
        cout << "Target = " << targets[i] << "\n";

        vector<int> res = sol.searchRange(tests[i], targets[i]);
        cout << "Output = [" << res[0] << ", " << res[1] << "]\n";
        cout << "--------------------------------------------\n";
    }

    return 0;
}
