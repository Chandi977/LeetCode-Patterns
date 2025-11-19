#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: DUTCH NATIONAL FLAG ALGORITHM
    ---------------------------------------------------
    Problem:
        Sort an array of 0s, 1s, and 2s IN-PLACE without extra memory.

    Three pointers:
        low  -> boundary of 0 region
        mid  -> current pointer
        high -> boundary of 2 region

    Rules:
        nums[mid] == 0 → swap with low, expand low & mid
        nums[mid] == 1 → move mid
        nums[mid] == 2 → swap with high, shrink high

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2,0,2,1,1,0},    // → 0 0 1 1 2 2
        {2,0,1},          // → 0 1 2
        {0},              // → 0
        {1,2,0,1,2,0,1},  // → 0 0 1 1 1 2 2
        {2,2,2,1,1,0}     // → 0 1 1 2 2 2
    };

    cout << "Sort Colors (Dutch National Flag) - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printArray(tests[i]);

        sol.sortColors(tests[i]);

        cout << "Sorted:   ";
        printArray(tests[i]);
        cout << "-------------------------------------\n";
    }

    return 0;
}
