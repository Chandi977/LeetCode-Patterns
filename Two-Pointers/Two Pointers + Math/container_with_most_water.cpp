#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (Opposite Ends)
    --------------------------------------------------
    Problem:
        Given an array where height[i] is the height of a vertical line,
        find the maximum water a container can store between any two lines.

    Intuition:
        - Area is limited by the *shorter* of the two chosen heights.
        - Using two pointers:
            left  -> start
            right -> end
        - Compute area for each pair.
        - Always move the pointer pointing to the *shorter* height.
          (Moving the taller one never increases height → area won't improve.)

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {

            int width = right - left;

            int h = min(height[left], height[right]);

            maxWater = max(maxWater, width * h);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,8,6,2,5,4,8,3,7},   // → 49
        {1,1},                 // → 1
        {4,3,2,1,4},           // → 16
        {1,2,1},               // → 2
        {2,3,10,5,7,8,9}       // → 36
    };

    cout << "Container With Most Water - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nHeights: ";
        printVector(tests[i]);

        int result = sol.maxArea(tests[i]);

        cout << "Max Water: " << result << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
