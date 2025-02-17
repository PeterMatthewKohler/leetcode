/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    // One pass
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        // Shift the right over n times (create a window of size n between left and right)
        while(n > 0)
        {
            right = right->next;
            n--;
        }
        // Shift both over until right hits the end of the list
        while(right)
        {
            right = right->next;
            left = left->next;
        }
        // Nth node from the end is left->next
        left->next = left->next->next;
        return dummy->next;
    }
};
