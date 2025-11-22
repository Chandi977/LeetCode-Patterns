#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH
    ----------------------------------
    Problem:
        Given a strictly increasing sorted array arr[] of positive integers,
        find the K-th missing positive number.

    Observation:
        For arr[mid], expected value at index mid is (mid + 1).
        Missing numbers until index mid:
                missing = arr[mid] - (mid + 1)

        If missing < k:
            kth missing number is to the RIGHT → l = mid + 1
        Else:
            search LEFT → r = mid - 1

    After binary search:
        The position where l stops gives:
            answer = l + k

    Why?
        Because l numbers exist before position l,
        so k missing numbers fit after adjusting.

    Time:  O(log n)
    Space: O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l + k;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printVector(const vector<int>& arr) {
    for (int v : arr) cout << v << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2,3,4,7,11},     // k = 5 → 9
        {1,2,3,4},        // k = 2 → 6
        {5,6,7,8,9},      // k = 1 → 1
        {1,10,21,22},     // k = 5 → 6
        {1},              // k = 10 → 11
    };

    vector<int> K = {5, 2, 1, 5, 10};

    cout << "Kth Missing Positive Number - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nArray: ";
        printVector(tests[i]);

        cout << "k = " << K[i] << "\n";

        int ans = sol.findKthPositive(tests[i], K[i]);

        cout << "Kth Missing = " << ans << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
