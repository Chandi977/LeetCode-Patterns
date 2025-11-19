#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (In-place Partition)
    ------------------------------------------------------
    Goal:
        Move all zeros to the END of the array while
        keeping the order of NON-zero elements.

    Technique:
        - Use two pointers:
            i → position where next non-zero should go
            j → scans through the entire array

        - When nums[j] != 0:
              swap(nums[i], nums[j])
              i++

        - At the end:
              all non-zero elements are at the front (in order)
              all 0s are pushed to the back

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // pointer for placing non-zero values

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
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
        {0, 1, 0, 3, 12},       // → 1 3 12 0 0
        {0},                   // → 0
        {1, 2, 3},             // → 1 2 3
        {0, 0, 0, 1},          // → 1 0 0 0
        {4, 2, 4, 0, 0, 3, 0, 5, 1, 0}
    };

    cout << "Move Zeroes - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printArray(tests[i]);

        sol.moveZeroes(tests[i]);

        cout << "After Move Zeroes: ";
        printArray(tests[i]);
        cout << "-------------------------------------\n";
    }

    return 0;
}
