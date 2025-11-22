#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: PREFIX SUM + CENTERED WINDOW
    -------------------------------------------------
    Problem:
        For each index i, compute the average of the subarray
        centered at i with radius k:

                i-k ... i ... i+k     (total length = 2k + 1)

        If the window goes out of bounds → answer = -1.

    Key Idea:
        Use prefix sums for O(1) window sum calculation:

            sum(l..r) = prefix[r+1] - prefix[l]

    Time:  O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        long long windowSize = 2LL * k + 1;

        // If window is larger than array, return all -1
        if (windowSize > n) return ans;

        // Build prefix sum array
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Compute averages for valid centers
        for (int i = k; i + k < n; i++) {
            long long total = prefix[i + k + 1] - prefix[i - k];
            ans[i] = total / windowSize;
        }

        return ans;
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
        {7,4,3,9,1,8,5,2,6},   // k=3
        {100000},             // k=0
        {8,3,4},              // k=1
        {1,2,3,4,5},          // k=10 (too large)
        {5,5,5,5,5},          // k=1
    };

    vector<int> K = {3, 0, 1, 10, 1};

    cout << "K-Radius Subarray Averages - Test Results\n\n";

    for (int t = 0; t < tests.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nArray: ";
        printArray(tests[t]);
        cout << "k = " << K[t] << "\n";

        vector<int> result = sol.getAverages(tests[t], K[t]);

        cout << "Averages: ";
        printArray(result);

        cout << "-------------------------------------\n";
    }

    return 0;
}
