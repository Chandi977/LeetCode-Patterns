#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: FAST & SLOW POINTERS (CYCLE DETECTION)
    ------------------------------------------------------------
    Why this works:
    - Slow pointer moves 1 step at a time.
    - Fast pointer moves 2 steps at a time.
    - If there is a cycle:
            fast will eventually meet slow inside the loop.
    - If there is NO cycle:
            fast will reach NULL.

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/

// Singly linked list node definition
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if (!head || !head->next)
            return false;     // no chance of cycle

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;             // move slow by 1
            fast = fast->next->next;       // move fast by 2

            if (slow == fast)              // pointers meet => cycle exists
                return true;
        }

        return false;  // fast reached NULL => no cycle
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

int main() {
    Solution sol;

    // ---------------------------
    // Test Case 1: Cycle Exists
    // ---------------------------
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;   // creates a cycle at node b

    cout << "Test Case 1 (Cycle Present): "
         << (sol.hasCycle(a) ? "TRUE" : "FALSE") << "\n";


    // ---------------------------
    // Test Case 2: No Cycle
    // ---------------------------
    ListNode* p = new ListNode(1);
    ListNode* q = new ListNode(2);
    p->next = q;

    cout << "Test Case 2 (No Cycle): "
         << (sol.hasCycle(p) ? "TRUE" : "FALSE") << "\n";


    // ---------------------------
    // Test Case 3: Single Node No Cycle
    // ---------------------------
    ListNode* single = new ListNode(10);

    cout << "Test Case 3 (Single Node): "
         << (sol.hasCycle(single) ? "TRUE" : "FALSE") << "\n";


    cout << "-------------------------------------\n";

    return 0;
}
