#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (Partitioning)
    -------------------------------------------------
    Problem:
        Move all even numbers to the LEFT and all odd numbers to the RIGHT.

    Key Idea:
        - left pointer moves forward until it finds an ODD number.
        - right pointer moves backward until it finds an EVEN number.
        - Then swap them.

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // Move left forward if element is even
            while (left < right && nums[left] % 2 == 0)
                left++;

            // Move right backward if element is odd
            while (left < right && nums[right] % 2 == 1)
                right--;

            // Swap odd (left) with even (right)
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        return nums;
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
        {3,1,2,4},           // → [2,4,3,1]
        {0},                 // → [0]
        {1,3,5,7},           // → all odd
        {2,4,6,8},           // → all even
        {9,7,5,4,2,6,1,3}    // → evens left, odds right
    };

    cout << "Sort Array By Parity - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printArray(tests[i]);

        sol.sortArrayByParity(tests[i]);

        cout << "Sorted:   ";
        printArray(tests[i]);
        cout << "-------------------------------------\n";
    }

    return 0;
}
