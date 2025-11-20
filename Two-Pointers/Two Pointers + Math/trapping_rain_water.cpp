#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (LeftMax / RightMax)
    -----------------------------------------------------

    Goal:
        Compute how much rainwater is trapped between bars.

    Key Observations:
        - Water above a bar = min(leftMax, rightMax) - height[i]
        - Use two pointers:
              left  → from start
              right → from end
        - The smaller boundary determines the trapped water side.

    Why this works:
        If height[left] < height[right]:
            -> right side is definitely taller
            -> water trapped depends only on leftMax
        Else:
            -> left side is definitely taller
            -> water trapped depends only on rightMax

    Time:  O(n)
    Space: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {

            // Left boundary smaller → handle left side
            if (height[left] < height[right]) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            }

            // Right boundary smaller → handle right side
            else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
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
        {0,1,0,2,1,0,1,3,2,1,2,1},   // → 6
        {4,2,0,3,2,5},               // → 9
        {1,0,2,1,0,1,3},             // → 5
        {2,0,2},                     // → 2
        {3,3,3},                     // → 0
        {5,4,1,2}                    // → 1
    };

    cout << "Trapping Rain Water - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nHeights: ";
        printArray(tests[i]);

        int result = sol.trap(tests[i]);

        cout << "Trapped Water = " << result << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
