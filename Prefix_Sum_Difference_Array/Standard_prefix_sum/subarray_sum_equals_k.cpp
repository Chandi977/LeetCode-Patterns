#include <bits/stdc++.h>
using namespace std;

/*
    🔥 PREFIX SUM (O(n²) approach)
    ------------------------------
    Idea:
        Build prefix sum array:
            prefix[i] = sum of first i elements

        Subarray sum from i to j:
            sum = prefix[j+1] - prefix[i]

    Time:  O(n²)
    Space: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix[i+1] = sum(nums[0..i])
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int count = 0;

        // Check all subarrays using prefix difference
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (prefix[j] - prefix[i] == k)
                    count++;
            }
        }

        return count;
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
        {1,1,1},       // k = 2 → 2
        {1,2,3},       // k = 3 → 2  (1+2, 3)
        {-1,-1,1},     // k = 0 → 1
        {3,4,7,2,-3,1,4,2}, // k = 7 → 4
        {0,0,0,0},     // k = 0 → 10
    };

    vector<int> K = {2, 3, 0, 7, 0};

    cout << "Subarray Sum Equals K (Prefix Sum O(n²)) - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nNums: ";
        printVector(tests[i]);
        cout << "k = " << K[i] << "\n";

        int ans = sol.subarraySum(tests[i], K[i]);

        cout << "Result = " << ans << "\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}
