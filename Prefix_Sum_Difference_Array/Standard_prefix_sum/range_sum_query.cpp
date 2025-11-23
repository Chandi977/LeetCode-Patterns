#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: PREFIX SUM (Immutable Array)
    --------------------------------------------------
    Goal:
        sumRange(L, R) = nums[L] + ... + nums[R]
    
    Trick:
        Build prefix array where:
            prefix[i] = sum of first i elements   (0-index excluded)
        
        Then:
            sumRange(L, R) = prefix[R+1] - prefix[L]

    Time:
        Constructor:  O(n)
        Query:        O(1)

    Space:
        O(n)
*/

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);

        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
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
    vector<int> nums = {-2, 0, 3, -5, 2, 1};
    cout << "Input array: ";
    printVector(nums);

    NumArray obj(nums);

    vector<pair<int,int>> queries = {
        {0,2},   // → 1
        {2,5},   // → 1
        {0,5},   // → -1
        {3,3},   // → -5
        {1,4}    // → 0
    };

    cout << "\nRange Sum Query - Test Results:\n\n";

    for (auto &q : queries) {
        cout << "sumRange(" << q.first << ", " << q.second << ") = "
             << obj.sumRange(q.first, q.second) << "\n";
    }

    return 0;
}
