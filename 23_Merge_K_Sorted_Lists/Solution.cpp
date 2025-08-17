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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmpLambda = [](ListNode* a, ListNode* b){return a->val > b->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmpLambda)> minHeap(cmpLambda);
        // Seed our min heap
        for(auto list : lists)
        {
            if(list){minHeap.push(list);}
        }
        // Pointer to track the head
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        // Do the sorting
        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node; // Push sorted node
            curr = curr->next;
            if(node->next){minHeap.push(node->next);}
        }
        return dummy->next;
    }
};
