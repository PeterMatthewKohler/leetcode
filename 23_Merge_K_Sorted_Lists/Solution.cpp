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
        // Custom comparator to compare node values
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        // Min-heap
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap;
        // Seed the min-heap
        for(const auto& list : lists) {
            if(list != nullptr){minHeap.push(list);}
        }
        // Convenience ptrs
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        // Go until entire set of lists is sorted
        while(!minHeap.empty()) {
            // Grab sorted value
            ListNode* tmp = minHeap.top();
            minHeap.pop();
            // Insert next value in list into heap
            if(tmp->next != nullptr){minHeap.push(tmp->next);}
            // Append sorted value into our final LL
            curr->next = tmp;
            curr = curr->next;  // Progress LL
        }
        return dummy->next;
    }
};
