#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: BINARY SEARCH ON ANSWER
    --------------------------------------------
    Problem:
        Koko must finish all banana piles within H hours.
        She eats at speed K per hour:
            - From a pile of size p, hours required = ceil(p / K).

        Goal:
            Find the minimum K (speed) such that she can finish in H hours.

    Strategy: Binary Search on K (Eating Speed)
        - Minimum speed = 1
        - Maximum speed = max(piles)

        For a given speed K:
            Simulate hours needed → if <= H → K is valid
            Otherwise → increase K

    Time:  O(n log maxPile)
    Space: O(1)
*/

class Solution {
public:

    // Check if Koko can eat all bananas at speed k within h hours
    bool canEat(vector<int>& piles, int k, int h) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;  // ceiling division
            if (hours > h) return false;  // early exit
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // max possible speed
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2; // candidate speed

            if (canEat(piles, mid, h)) {
                ans = mid;   // mid is valid, try slower speed
                r = mid - 1;
            }
            else {
                l = mid + 1; // mid too slow → increase speed
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
        {3,6,7,11},      // h = 8 → 4
        {30,11,23,4,20}, // h = 5 → 30
        {30,11,23,4,20}, // h = 6 → 23
        {312884470},     // h = 968709470 → 1
        {1,1,1,999999999} // h = 10 → 999999999
    };

    vector<int> H = {8, 5, 6, 968709470, 10};

    cout << "Koko Eating Bananas - Test Results\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nPiles: ";
        printVector(tests[i]);
        cout << "Hours H = " << H[i] << "\n";

        int ans = sol.minEatingSpeed(tests[i], H[i]);

        cout << "Minimum Eating Speed K = " << ans << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
