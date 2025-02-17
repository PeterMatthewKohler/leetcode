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
        // Edge case
        if(lists.empty()){return nullptr;}

        // Comparison lambda
        auto compare = [](ListNode* a, ListNode* b){return a->val > b->val;};
        // implement a min heap with custom comparator
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Push all elements onto the minHeap
        for(ListNode* list : lists)
        {
            minHeap.push(list);
        }
        // Each first element in all k lists are now sorted with min being top of heap
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* curr = dummy;
        // Grab each sorted node and add to new linked list
        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node; // Add to sorted list
            curr = curr->next;
            // 'Remove' node from linked list and re-add to minHeap
            node = node->next;
            if(node)
            {
                minHeap.push(node);
            }
        }
        // Return sorted array
        return dummy->next;
    }
};
