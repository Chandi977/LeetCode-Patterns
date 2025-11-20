#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: QUICKSELECT (Divide & Conquer)
    ---------------------------------------------------
    Problem:
        Find the K-th largest element in an unsorted array.

    Key Trick:
        K-th largest ↔ (N - K)-th smallest

    QuickSelect:
        - Similar to QuickSort but only partitions the side 
          which contains the desired element.
        - Average time: O(n)
        - Worst case: O(n^2) (rare)

    Partition Logic (Lomuto):
        - Choose pivot = nums[right]
        - Move all elements <= pivot to the left region
        - Return pivot’s correct sorted index
*/

class Solution {
public:

    // Partition returns the correct index of pivot
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    // QuickSelect to find k-th smallest element
    int quickSelect(vector<int>& nums, int left, int right, int ksmall) {
        if (left == right)
            return nums[left];

        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == ksmall)
            return nums[pivotIndex];
        else if (pivotIndex > ksmall)
            return quickSelect(nums, left, pivotIndex - 1, ksmall);
        else
            return quickSelect(nums, pivotIndex + 1, right, ksmall);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int kSmallest = n - k;  // convert largest to smallest index
        return quickSelect(nums, 0, n - 1, kSmallest);
    }
};


// ----------------------------------------------------
//                        MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {3,2,1,5,6,4},        // k=2 → 5
        {3,2,3,1,2,4,5,5,6},  // k=4 → 4
        {1},                 // k=1 → 1
        {7,10,4,3,20,15},    // k=3 → 10
        {9,8,7,6,5}          // k=1 → 9
    };

    vector<int> K = {2, 4, 1, 3, 1};

    cout << "K-th Largest Element (QuickSelect) - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        for (int x : tests[i]) cout << x << " ";

        cout << "\nk = " << K[i];

        vector<int> arr = tests[i]; // avoid modifying original for display
        int result = sol.findKthLargest(arr, K[i]);

        cout << "\nK-th Largest = " << result
             << "\n-------------------------------------\n";
    }

    return 0;
}
