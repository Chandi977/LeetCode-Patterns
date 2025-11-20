#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: TWO POINTERS + STRING CLEANUP
    ---------------------------------------------------
    Goal:
        Check if a string is a palindrome by ignoring:
        - Non-alphanumeric characters
        - Case differences

    Key Ideas:
    - Use two pointers (left, right)
    - Skip characters that are NOT letters/digits using isalnum()
    - Compare lowercase versions of characters
    - Move pointers inward until they meet

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Skip all non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left]))
                left++;

            // Skip all non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right]))
                right--;

            // Convert to lowercase for case-insensitive comparison
            char L = tolower(s[left]);
            char R = tolower(s[right]);

            // If mismatch → not a palindrome
            if (L != R)
                return false;

            left++;
            right--;
        }

        return true;
    }
};


// -------------------------------------------------
//                       MAIN
// -------------------------------------------------

int main() {
    Solution sol;

    vector<string> tests = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " ",
        "0P",
        "No lemon, no melon",
        "Was it a car or a cat I saw?"
    };

    cout << "Valid Palindrome - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\nInput: \"" << tests[i] << "\"\n";
        cout << "Is Palindrome? -> "
             << (sol.isPalindrome(tests[i]) ? "TRUE" : "FALSE")
             << "\n--------------------------------------\n";
    }

    /*
        Expected:
        Test 1 → TRUE
        Test 2 → FALSE
        Test 3 → TRUE (empty string considered palindrome)
        Test 4 → FALSE
        Test 5 → TRUE
        Test 6 → TRUE
    */

    return 0;
}
