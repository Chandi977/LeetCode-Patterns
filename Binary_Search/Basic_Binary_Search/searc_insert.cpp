#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH
    ----------------------------------
    Problem:
        Given a sorted array and a target,
        return the index if the target is found.
        Otherwise, return the index where it would be inserted.

    Intuition:
        Standard binary search:
        - If nums[mid] == target → return mid
        - If nums[mid] < target  → search right
        - If nums[mid] > target  → search left

        If loop ends:
            `l` is exactly where target should be inserted.

    Time:  O(log n)
    Space: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;   // insertion position
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
        {1,3,5,6},     // target=5 → 2
        {1,3,5,6},     // target=2 → 1
        {1,3,5,6},     // target=7 → 4
        {1,3,5,6},     // target=0 → 0
        {2,4,6,8},     // target=6 → 2
    };

    vector<int> targets = {5, 2, 7, 0, 6};

    cout << "Search Insert Position - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printVector(tests[i]);
        cout << "Target = " << targets[i] << "\n";

        int result = sol.searchInsert(tests[i], targets[i]);
        cout << "Output Index = " << result << "\n";

        cout << "-------------------------------------\n";
    }

    return 0;
}
