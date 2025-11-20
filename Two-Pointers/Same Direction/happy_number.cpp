#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: FAST & SLOW POINTERS (Cycle Detection in Numbers)
    ----------------------------------------------------------------------
    Problem:
        A number is "happy" if repeatedly summing the squares of its digits
        eventually reaches 1.

    Key Insight:
        - Any unhappy number eventually falls into a cycle (like 4 → 16 → 37 → 58 → ...)
        - A happy number ALWAYS reaches 1.
        - We can detect the cycle using Floyd's (fast & slow) method.

    Sequence example for n=19:
        19 → 82 → 68 → 100 → 1  ✅ happy number

    Time Complexity: O(log n) per iteration
    Space Complexity: O(1)
*/


class Solution {
public:

    // Utility function: returns sum of squares of digits
    int getSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;               // moves 1 step (1 square transformation)
        int fast = getSquare(n);    // moves 2 steps (two transformations)

        // Loop until:
        // 1) fast hits 1 → number is happy
        // 2) slow == fast → cycle detected → unhappy number
        while (fast != 1 && slow != fast) {
            slow = getSquare(slow);                       // move slow by 1 transformation
            fast = getSquare(getSquare(fast));            // move fast by 2 transformations
        }

        return fast == 1;
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<int> tests = {19, 2, 7, 20, 1, 1111111};

    cout << "Happy Number - Test Results:\n\n";

    for (int x : tests) {
        cout << "Number: " << x << " → "
             << (sol.isHappy(x) ? "HAPPY" : "UNHAPPY")
             << "\n";
    }

    cout << "\n-------------------------------------\n";

    return 0;
}
