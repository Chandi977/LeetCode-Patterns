#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS + BOUNDARY TRACKING
    ------------------------------------------------------
    Intuition:
    - Water trapped at index i depends on:
            min(maxLeft[i], maxRight[i]) - height[i]

    - Instead of computing maxLeft[] and maxRight[] arrays,
      we use two pointers + running boundaries:

        leftMax  = highest bar seen from left
        rightMax = highest bar seen from right

    - Always move the pointer which has the smaller boundary.
      Because that boundary decides the trapped water.
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int trapped = 0;

        while (left < right) {

            // If left boundary is smaller → left side controls the water
            if (height[left] < height[right]) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];         // update boundary
                } else {
                    trapped += leftMax - height[left];  // collect water
                }

                left++;     // move inward
            }

            // Right boundary smaller → right controls the water
            else {

                if (height[right] >= rightMax) {
                    rightMax = height[right];        // update boundary
                } else {
                    trapped += rightMax - height[right];  // collect water
                }

                right--;    // move inward
            }
        }

        return trapped;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {0,1,0,2,1,0,1,3,2,1,2,1},       // classic test → 6
        {4,2,0,3,2,5},                   // → 9
        {2,0,2},                         // → 2
        {3, 0, 1, 3, 0, 5},              // → 8
        {5,4,1,2},                       // → 1
        {1,2,3,4,5},                     // no trapping → 0
        {5,4,3,2,1},                     // no trapping → 0
    };

    cout << "Trapping Rain Water - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nTrapped Water = " << sol.trap(tests[i]) << "\n";
        cout << "-------------------------------------\n";
    }

    /*
        Expected outputs:
        Test 1: 6
        Test 2: 9
        Test 3: 2
        Test 4: 8
        Test 5: 1
        Test 6: 0
        Test 7: 0
    */

    return 0;
}
