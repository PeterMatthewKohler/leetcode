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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;    // Keep track of next node
            curr->next = prev;  // Reverse direction of current node
            // Traverse to next node
            prev = curr;
            curr = next;
        }
        // Return the new head
        return prev;
    }
};
