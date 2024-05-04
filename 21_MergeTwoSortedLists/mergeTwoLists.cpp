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
        // Edge cases with empty lists
        if(!list1){return list2;}
        else if(!list2){return list1;}
        ListNode* merged = nullptr;
        ListNode* start = new ListNode;
        if(list1->val < list2->val)
        {
            merged = list1;
            list1 = list1->next;
        }
        else
        {
            merged = list2;
            list2 = list2->next;
        }
        start->next = merged;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                merged->next = list1;
                list1 = list1->next;
                merged = merged->next;
            }
            else
            {
                merged->next = list2;
                list2 = list2->next;
                merged = merged->next;
            }
        }
        // If there are any remaining nodes in list
        if(list1)
        {
            merged->next = list1;
        }
        else
        {
            merged->next = list2;
        }

        return start->next;
    }
};
