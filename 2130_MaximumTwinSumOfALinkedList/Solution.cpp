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
    int pairSum(ListNode* head) {
        // Edge case, there are two nodes
        if(!head->next->next){return head->val + head->next->val;}
        // Find the mid-point of the LL
        ListNode* fast = head;
        ListNode* slow = head;
        int n = 0;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            n++;
        }
        // Reverse right half of LL
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr)
        {
            ListNode* next = curr->next; // Keep track of next node
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* end = prev;
        ListNode* start = head;
        int maxSum = 0;
        for(int i = 0; i < n; i++) // Traverse n times
        {
            maxSum = max(maxSum, start->val + end->val);
            start = start->next;
            end = end->next;
        }
        return maxSum;
    }
};
