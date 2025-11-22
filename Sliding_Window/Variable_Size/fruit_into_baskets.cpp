#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: SLIDING WINDOW (At Most K Distinct)
    --------------------------------------------------------
    Problem:
        You can pick fruits in a row, but only TWO distinct types
        can be collected at a time (two baskets).

    Goal:
        Find the longest subarray containing at most 2 distinct integers.

    Approach:
        Sliding Window + HashMap
        - Expand right pointer, count fruits.
        - If more than 2 types, shrink window from left.
        - Always update max window length.

    Time:  O(n)
    Space: O(1) (max 2 distinct types stored)
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> count;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            // Shrink window if we have more than 2 fruit types
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0)
                    count.erase(fruits[left]);
                left++;
            }

            // Window now has at most 2 types
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1,2,1},               // → 3
        {0,1,2,2},             // → 3
        {1,2,3,2,2},           // → 4
        {3,3,3,1,2,1,1,2,3,3,4}, // → 5
        {1},                   // → 1
        {1,2,1,3,4,3,5,1,2}    // → 3
    };

    cout << "Fruit Into Baskets - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {

        cout << "Test Case " << i + 1 << ":\nFruits: ";
        printVector(tests[i]);

        int ans = sol.totalFruit(tests[i]);

        cout << "Maximum Fruits = " << ans << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
