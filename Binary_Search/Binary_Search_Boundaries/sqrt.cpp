#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH
    ----------------------------------
    Problem:
        Return ⌊sqrt(x)⌋ (floor of the square root).

    Key Detail:
        We avoid overflow by using:
            long long mid
            mid * mid can exceed int range safely

    Classic Binary Search Logic:
        Search for the FIRST number whose square is > x.
        Answer is that index - 1.

        l = 0
        r = x + 1    (one step beyond possible sqrt)

        While (l < r):
            if mid^2 > x → shrink right to mid
            else          → move left to mid+1

        Return l - 1 (largest value whose square <= x)

    Time:  O(log x)
    Space: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = (long long)x + 1;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (mid * mid > x)
                r = mid;        // mid too large
            else
                l = mid + 1;    // mid valid, try bigger
        }

        return l - 1;            // floor(sqrt(x))
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<int> tests = {
        0,     // 0 → 0
        1,     // 1 → 1
        4,     // 4 → 2
        8,     // 8 → 2
        15,    // 15 → 3
        16,    // 16 → 4
        2147395599 // near INT max → 46339
    };

    cout << "Integer Square Root - Test Results\n\n";

    for (int x : tests) {
        cout << "x = " << x 
             << "  →  sqrt = " << sol.mySqrt(x) << "\n";
    }

    return 0;
}
