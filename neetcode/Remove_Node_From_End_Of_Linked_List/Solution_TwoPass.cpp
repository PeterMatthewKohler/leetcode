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
    // Two pass approach
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: head is null
        if(!head){return nullptr;}
        // First pass: get the length of the list
        ListNode* curr = head;
        int length = 0;
        while(curr)
        {
            curr = curr->next;
            length++;
        }
        // Second pass, remove the nth node from the end
        curr = head;
        int idx = 0;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;
        std::cout << length;
        // Edge case: we are removing the very first node
        if(length - n == 0)
        {
            return next;
        }
        while(idx < length - n)
        {
            idx++;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        // Remove current and link prev and next
        prev->next = next;
        return head;
    }
};
