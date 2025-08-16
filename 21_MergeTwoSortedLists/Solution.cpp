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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Edge cases:
        if(!list1){return list2;}
        if(!list2){return list1;}
        if(!list1 && !list2){return nullptr;}
        ListNode* dummyHead = new ListNode();
        ListNode* curr;
        curr = dummyHead; // moveable ptr
        while(list1 && list2) // Keep going until we finish one of the lists
        {
            // Sorting
            if(list1->val <= list2->val)
            {
                ListNode* temp = list1;
                list1 = list1->next;
                curr->next = temp; // Build the chain
                curr = curr->next; // Advance
            }
            else
            {
                ListNode* temp = list2;
                list2 = list2->next;
                curr->next = temp; // Build the chain
                curr = curr->next; // Advance
            }
        }
        // Have either list1 or list2 left to add
        curr->next = (list1 ? list1 : list2);
        return dummyHead->next;
    }
};
