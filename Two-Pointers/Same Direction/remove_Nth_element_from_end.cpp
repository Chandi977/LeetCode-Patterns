#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: FAST & SLOW POINTERS
    -----------------------------------------
    Problem:
        Remove the N-th node from the END of a linked list.

    Trick:
        Use a dummy node + fast pointer trick.

    Steps:
        1. Create dummy node pointing to head.
        2. Move 'fast' pointer n steps ahead.
        3. Move BOTH slow & fast until fast reaches last node.
        4. Now slow->next is the node to delete.
        5. Remove it and return dummy->next.

    Why dummy?
        Handles edge case: removing the HEAD node.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

// Linked list node
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0, head);

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 1: Move fast pointer 'n' steps ahead
        for (int i = 0; i < n; i++)
            fast = fast->next;

        // Step 2: Move both pointers until fast reaches the last node
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Now slow->next is the target node
        slow->next = slow->next->next;

        return dummy->next;
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
        {1, 2, 3, 4, 5},   // remove 2nd from end → remove 4
        {1},               // remove 1st → becomes []
        {1, 2},            // remove 1st → [1]
        {1, 2}             // remove 2nd → [2]
    };

    vector<int> removeN = {2, 1, 1, 2};

    cout << "Remove N-th Node from End - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        ListNode* head = createList(tests[i]);

        cout << "Test Case " << i + 1 << ":\nOriginal: ";
        printList(head);

        ListNode* updated = sol.removeNthFromEnd(head, removeN[i]);

        cout << "After Removing " << removeN[i] << "th from end: ";
        printList(updated);
        cout << "-------------------------------------\n";
    }

    return 0;
}
