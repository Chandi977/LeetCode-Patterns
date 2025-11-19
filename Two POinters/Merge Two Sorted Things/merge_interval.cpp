#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: INTERVAL MERGING (Sorting + Greedy)
    ---------------------------------------------------------
    Steps:
        1. Sort intervals by start time.
        2. Traverse and compare with the last added interval:
             - If no overlap → add new interval.
             - If overlap → merge by extending the end boundary.
    
    Why sorting?
        Ensures all overlapping intervals appear consecutively.

    Time Complexity:  O(n log n)
    Space Complexity: O(n) for result list
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());  
        // Sorting by first element automatically

        vector<vector<int>> result;

        for (auto &interval : intervals) {

            // Case 1: result empty OR no overlap → add interval
            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            }

            // Case 2: overlap → merge
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printIntervals(vector<vector<int>>& v) {
    cout << "[ ";
    for (auto &x : v) {
        cout << "[" << x[0] << "," << x[1] << "] ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<vector<int>>> tests = {
        {{1,3},{2,6},{8,10},{15,18}},      // → [[1,6],[8,10],[15,18]]
        {{1,4},{4,5}},                     // → [[1,5]]
        {{1,4},{0,2},{3,5}},               // → [[0,5]]
        {{5,7},{1,3}},                     // → [[1,3],[5,7]]
        {{1,10},{2,3},{4,6},{7,9}},        // → [[1,10]]
        {{1,4}},                           // → [[1,4]]
        {{}}                               // → [[]]
    };

    cout << "Merge Intervals - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printIntervals(tests[i]);

        // Edge case: empty interval like {{}} 
        vector<vector<int>> arr = tests[i];
        vector<vector<int>> result;

        if (arr.size() == 1 && arr[0].size() == 0) {
            cout << "Merged: []\n";
        } else {
            result = sol.merge(arr);
            cout << "Merged:  ";
            printIntervals(result);
        }

        cout << "-------------------------------------\n";
    }

    return 0;
}
