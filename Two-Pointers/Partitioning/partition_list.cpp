#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: LINKED LIST PARTITIONING (Two List Method)
    ---------------------------------------------------------------
    Problem:
        Rearrange linked list so that:
            - All nodes < x come first
            - All nodes >= x come after
        Preserve relative order of nodes (stable partition).

    Approach:
        Use TWO dummy lists:
            smallList: nodes with value < x
            bigList:   nodes with value >= x

        Then connect:
            smallList → bigList

    Time Complexity: O(n)
    Space Complexity: O(1) extra
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallHead = new ListNode(0); // dummy for < x
        ListNode* bigHead   = new ListNode(0); // dummy for >= x

        ListNode* small = smallHead;
        ListNode* big   = bigHead;

        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        // Important: terminate big list to avoid cycles
        big->next = nullptr;

        // Connect small list with big list
        small->next = bigHead->next;

        return smallHead->next;
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
        {1,4,3,2,5,2},      // x = 3
        {2,1},             // x = 2
        {},                // empty list
        {1,2,3},           // x = 5
        {5,4,3,2,1}        // x = 3
    };

    vector<int> X = {3, 2, 3, 5, 3};

    cout << "Partition List - Test Results:\n\n";

    for (int i = 0; i < tests.size(); i++) {
        ListNode* head = createList(tests[i]);

        cout << "Test Case " << i + 1 << ":\nOriginal:  ";
        printList(head);

        ListNode* result = sol.partition(head, X[i]);

        cout << "x = " << X[i] << "\nPartitioned: ";
        printList(result);
        cout << "-------------------------------------\n";
    }

    return 0;
}
