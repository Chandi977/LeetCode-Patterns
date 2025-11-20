#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS
    ---------------------------------
    Why Two Pointers?
    - The array is already sorted.
    - We can use 2 pointers to shrink the search space:
        → If current sum is too big → move RIGHT pointer left
        → If current sum is too small → move LEFT pointer right
    - This gives O(n) time complexity instead of O(n²)

    Why 1-indexed return?
    - LeetCode requires returning positions starting from 1.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            long long sum = numbers[start] + numbers[end];

            if (sum == target) {
                // Answer must be 1-indexed
                return {start + 1, end + 1};
            }
            else if (sum > target) {
                end--; // Reduce sum
            }
            else {
                start++; // Increase sum
            }
        }

        return {}; // Problem guarantees a solution
    }
};

// ---------------------------
//      TESTING MAIN
// ---------------------------

int main() {
    Solution sol;

    vector<vector<int>> testArrays = {
        {2, 7, 11, 15},
        {1, 2, 3, 4, 4},
        {-5, -3, 0, 2, 8, 13}
    };

    vector<int> targets = {9, 8, 10};

    for (int i = 0; i < testArrays.size(); i++) {
        cout << "Test Case " << (i + 1) << ": ";

        vector<int> result = sol.twoSum(testArrays[i], targets[i]);
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    /*
        Expected Output:
        Test Case 1: 1 2
        Test Case 2: 4 5
        Test Case 3: 3 6
    */

    return 0;
}
