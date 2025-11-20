#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (Opposite Ends)
    --------------------------------------------------
    Problem:
        Given a sorted array (may contain negatives),
        return a new array of squares, also sorted.

    Idea:
        The largest square will come from either:
            - leftmost negative number, OR
            - rightmost positive number.

        So we use:
            left  pointer at start
            right pointer at end
            k     pointer filling result from the back

    Time Complexity:  O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0, right = n - 1;
        int k = n - 1;  // fill result from end

        while (left <= right) {

            int leftSq  = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                result[k] = leftSq;
                left++;
            } else {
                result[k] = rightSq;
                right--;
            }
            k--;
        }

        return result;
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
        {-4,-1,0,3,10},      // → [0,1,9,16,100]
        {-7,-3,2,3,11},      // → [4,9,9,49,121]
        {0},                 // → [0]
        {-5,-4,-3,-2,-1},    // → [1,4,9,16,25]
        {1,2,3,4,5}          // → [1,4,9,16,25]
    };

    cout << "Sorted Squares - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printArray(tests[i]);

        vector<int> result = sol.sortedSquares(tests[i]);

        cout << "Squared Sorted: ";
        printArray(result);

        cout << "-------------------------------------\n";
    }

    return 0;
}
