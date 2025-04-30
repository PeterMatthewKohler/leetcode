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
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> set;
        ListNode* curr = head;
        while(curr)
        {
            std::cout << curr << std::endl;
            if(set.find(curr) == set.end())
            {
                set.insert(curr);
            }
            else
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};
