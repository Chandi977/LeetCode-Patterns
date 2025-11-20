#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: INTERVAL INSERTION + MERGING
    --------------------------------------------------
    Problem:
        Insert a new interval into a sorted, non-overlapping interval list,
        then merge if necessary.

    Steps:
        1. Add all intervals that END BEFORE the new interval begins.
        2. Merge all intervals that OVERLAP with the new interval.
        3. Add the remaining intervals.

    Time Complexity:  O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // 1️⃣ Add all intervals that come BEFORE newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2️⃣ Merge all overlapping intervals into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add merged interval
        result.push_back(newInterval);

        // 3️⃣ Add all intervals AFTER newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};


// ----------------------------------------------------
//                        MAIN
// ----------------------------------------------------

void printIntervals(const vector<vector<int>>& v) {
    cout << "[ ";
    for (auto &p : v)
        cout << "[" << p[0] << "," << p[1] << "] ";
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<vector<int>>> tests = {
        {{1,3},{6,9}},
        {{1,2},{3,5},{6,7},{8,10},{12,16}},
        {},
        {{1,5}},
        {{1,5}}
    };

    vector<vector<int>> newIntervals = {
        {2,5},
        {4,8},
        {5,7},
        {2,3},
        {0,0}
    };

    cout << "Insert Interval - Test Results:\n\n";

    for (int t = 0; t < tests.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nOriginal: ";
        printIntervals(tests[t]);

        cout << "Insert: [" << newIntervals[t][0] << "," << newIntervals[t][1] << "]\n";

        vector<vector<int>> result = sol.insert(tests[t], newIntervals[t]);

        cout << "Result:  ";
        printIntervals(result);
        cout << "-------------------------------------\n";
    }

    return 0;
}
