#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (Swap with End)
    --------------------------------------------------
    Problem:
        Remove all occurrences of `val` from the array IN-PLACE.
        Order of remaining elements does NOT matter.
        Return the number of elements remaining.

    Key Idea:
        - Use two pointers:
              left  → scans normally
              right → moves backward to find a non-val element
        - When nums[left] == val:
              swap(nums[left], nums[right])   // push val to end
              right--
        - Else: left++

        - When left > right → all valid elements are in [0 ... left-1]

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            // When nums[left] equals val, move it to the end
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;              // shrink valid region
            }  
            else {
                left++;               // keep valid element
            }
        }

        return left;                  // count of valid elements
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printArray(const vector<int>& arr, int k) {
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {3,2,2,3},      // val=3 → output length=2
        {0,1,2,2,3,0,4,2},  // val=2 → length=5
        {1,1,1,1},      // val=1 → length=0
        {4,5},          // val=5 → length=1
        {}              // val=0 → length=0
    };

    vector<int> values = {3, 2, 1, 5, 0};

    cout << "Remove Element - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nval = " << values[i] << "\n";

        int k = sol.removeElement(tests[i], values[i]);

        cout << "After Removal (" << k << " elements): ";
        printArray(tests[i], k);

        cout << "-------------------------------------\n";
    }

    return 0;
}
