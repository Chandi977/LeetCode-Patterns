#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH (Classic)
    --------------------------------------------
    Problem:
        Return the index of target in a sorted array,
        or -1 if target is not found.

    Key Points:
        - Use two pointers: l (left) and r (right)
        - mid = l + (r - l) / 2   → prevents overflow
        - If nums[mid] == target → return mid
        - If nums[mid] > target  → search left half
        - If nums[mid] < target  → search right half

    Time:  O(log n)
    Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] > target)
                r = mid - 1;

            else
                l = mid + 1;
        }
        return -1;
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
        {-1,0,3,5,9,12},  // target=9 → index 4
        {-1,0,3,5,9,12},  // target=2 → -1
        {5},              // target=5 → 0
        {5},              // target=0 → -1
        {2,4,6,8,10,12}   // target=8 → 3
    };

    vector<int> targets = {9, 2, 5, 0, 8};

    cout << "Binary Search - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printVector(tests[i]);
        cout << "Target = " << targets[i] << "\n";

        int result = sol.search(tests[i], targets[i]);

        cout << "Index = " << result << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
