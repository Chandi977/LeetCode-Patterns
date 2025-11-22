#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH ON ANSWER
    --------------------------------------------
    Problem:
        Given an array "weights" (packages) and integer "days",
        find the minimum ship capacity needed to deliver all
        packages in exactly "days" days.

    Key Observations:
        - Minimum possible capacity = max(weights)
        - Maximum possible capacity = sum(weights)

        Binary Search on capacity (K):
            If canShip(K) == true → try smaller capacity
            Else                  → increase capacity

    canShip(cap):
        Greedily accumulate weights day by day.
        If days required > given days → invalid.

    Time:  O(n log sum(weights))
    Space: O(1)
*/

class Solution {
public:

    // Check whether we can ship all packages with "cap" in "days"
    bool canShip(vector<int>& weights, int cap, int days) {
        int dayCount = 1;
        int curr = 0;

        for (int weight : weights) {

            // If adding this weight exceeds cap → use next day
            if (curr + weight > cap) {
                dayCount++;
                curr = 0;
            }

            curr += weight;

            // If we exceed assigned days → capacity is too small
            if (dayCount > days)
                return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end()); // min capacity
        int r = accumulate(weights.begin(), weights.end(), 0); // max capacity

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canShip(weights, mid, days)) {
                ans = mid;     // valid capacity → try smaller
                r = mid - 1;
            } 
            else {
                l = mid + 1;   // too small → increase capacity
            }
        }

        return ans;
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
        {1,2,3,4,5,6,7,8,9,10},   // days = 5 → 15
        {3,2,2,4,1,4},            // days = 3 → 6
        {1,2,3,1,1},              // days = 4 → 3
        {5,5,5,5,5},              // days = 5 → 5
        {10,50,100,100,50,100}    // days = 3 → 200
    };

    vector<int> D = {5, 3, 4, 5, 3};

    cout << "Ship Packages Within D Days - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nWeights: ";
        printVector(tests[i]);
        cout << "Days = " << D[i] << "\n";

        int ans = sol.shipWithinDays(tests[i], D[i]);

        cout << "Minimum Required Capacity = " << ans << "\n";
        cout << "----------------------------------------------\n";
    }

    return 0;
}
