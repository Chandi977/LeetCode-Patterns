#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: MERGE TWO SORTED ARRAYS (In-place)
    -------------------------------------------------------
    Idea:
        nums1 has size m + n. First m elements valid.
        nums2 has n elements.

        We merge FROM THE END to avoid overwriting nums1 values.

    Pointers:
        i = m-1 → last valid element in nums1
        j = n-1 → last element in nums2
        k = m+n-1 → last index in nums1

    Steps:
        - Compare nums1[i] and nums2[j], place the larger at nums1[k].
        - Move pointers backward.
        - If nums2 still has elements left, copy them.

    Time Complexity: O(m+n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge from end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If nums2 has leftover elements, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};


// ----------------------------------------------------
//                        MAIN
// ----------------------------------------------------

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    vector<vector<int>> tests_nums1 = {
        {1,2,3,0,0,0},
        {1},
        {0},
        {4,5,6,0,0,0},
        {2,0}
    };

    vector<vector<int>> tests_nums2 = {
        {2,5,6},
        {},
        {1},
        {1,2,3},
        {1}
    };

    vector<int> m = {3, 1, 0, 3, 1};
    vector<int> n = {3, 0, 1, 3, 1};

    cout << "Merge Sorted Array - Test Results:\n\n";

    for (int t = 0; t < tests_nums1.size(); t++) {
        cout << "Test Case " << t + 1 << ":\nnums1: ";
        printArray(tests_nums1[t]);
        cout << "nums2: ";
        printArray(tests_nums2[t]);

        sol.merge(tests_nums1[t], m[t], tests_nums2[t], n[t]);

        cout << "Merged: ";
        printArray(tests_nums1[t]);
        cout << "-------------------------------------\n";
    }

    return 0;
}
