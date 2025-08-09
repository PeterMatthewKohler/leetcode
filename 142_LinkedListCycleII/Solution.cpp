/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Detect cycle
        ListNode* fast = head;
        ListNode* slow = head;
        bool cycleDetected = false;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                cycleDetected = true;
                break;
            }
        }
        if(cycleDetected)
        {
            ListNode* slow2 = head;
            while(slow != slow2)
            {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
        else
        {
            return nullptr;
        }
    }
};
