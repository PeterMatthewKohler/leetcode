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
        // Edge cases
        // List1 is empty
        if(!list1){return list2;}
        // List2 is empty
        if(!list2){return list1;}
        // Both are empty
        if(!list1 && list2){return nullptr;}
        // Create beginning of new merged list
        ListNode* head; // Keep it empty and just have next point to actual start
        if(list1->val > list2->val)
        {
            head->next = list2;
            list2 = list2->next;
        }
        else
        {
            head->next = list1;
            list1 = list1->next;
        }
        ListNode* curr = head->next;
        // Go through lists until one of them is empty
        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        // Add remaining sorted values
        if(list1){curr->next = list1;}
        else{curr->next = list2;}
        return head->next;
    }
};
