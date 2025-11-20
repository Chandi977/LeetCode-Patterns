#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS (Opposite Ends)
    --------------------------------------------------
    Why this works?
    - The area = width * min(height[left], height[right]).
    - Width always decreases as we move pointers inward.
    - To maximize area, we must try to improve the height.
    - Therefore:
        → Move the pointer pointing to the SHORTER height.
        → This gives a chance to find a taller line.
    - Moving the taller line is useless because width shrinks
      and height does NOT improve.

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right) {

            // Width of container
            int width = right - left;

            // Height of container is limited by the smaller wall
            int h = min(height[left], height[right]);

            // Area for current left & right
            int currArea = width * h;

            // Update maximum
            maxWater = max(maxWater, currArea);

            // ⭐ Move the pointer with smaller height
            if (height[left] < height[right]) {
                left++;     // try a taller left boundary
            } else {
                right--;    // try a taller right boundary
            }
        }

        return maxWater;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,8,6,2,5,4,8,3,7},
        {1,1},
        {4,3,2,1,4},
        {1,2,1},
        {2,3,4,5,18,17,6}
    };

    cout << "Container With Most Water - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nMaximum Water = " << sol.maxArea(tests[i]) << "\n";
        cout << "-------------------------------------\n";
    }

    /*
        Expected outputs:
        Test 1: 49
        Test 2: 1
        Test 3: 16
        Test 4: 2
        Test 5: 17 * 5 = 85  (indexes 4 and 1 → heights 18 & 3 but better is 18 & 6 width=4)
    */

    return 0;
}
