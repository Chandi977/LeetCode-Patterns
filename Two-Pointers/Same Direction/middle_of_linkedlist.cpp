#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: FAST & SLOW POINTERS
    -----------------------------------------
    Goal:
        Return the middle node of a linked list.
        If even length → return the SECOND middle.

    Why it works:
        - slow moves 1 step at a time
        - fast moves 2 steps at a time
        - when fast reaches end (NULL),
          slow is at the middle.

    This works for both odd & even lengths automatically.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/


// Linked list node structure
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps
        }

        return slow;    // slow now at middle
    }
};


// ----------------------------------------------------
//                 Helper Functions
// ----------------------------------------------------

ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5},          // middle = 3
        {1, 2, 3, 4, 5, 6},       // even → middle = 4
        {10},                    // middle = 10
        {1, 100}                 // middle = 100
    };

    cout << "Middle of Linked List - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        ListNode* head = createList(tests[i]);

        cout << "Test Case " << i + 1 << ": ";
        printList(head);

        ListNode* mid = sol.middleNode(head);

        cout << "Middle Node Value = " << mid->val << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
