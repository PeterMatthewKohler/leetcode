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
        // Edge case: if lists is empty
        if(lists.size() == 0){return nullptr;}
        // Create a min heap with a custom comparator
        auto cmpLambda = [](std::pair<ListNode*, int> p1, std::pair<ListNode*, int> p2) {return p1.first->val > p2.first->val;};
        std::priority_queue<std::pair<ListNode*, int>, std::vector<std::pair<ListNode*, int>>, decltype(cmpLambda)> minHeap(cmpLambda);
        // Fill our min heap with the first entries
        int k = lists.size(); // Number of lists
        for(int i = 0; i < k; i++)
        {
            if(lists[i])
            {
                // Create a pair with the node and the index we can access the LL with
                std::pair<ListNode*, int> p = {lists[i], i};
                minHeap.push(p);
            }
        }
        // Create a dummy head we can access the merged list with
        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead; // Ptr we can use to build the list
        // Now iterate through all the lists
        while(!minHeap.empty())
        {
            auto p = minHeap.top();
            minHeap.pop();
            curr->next = p.first;
            // Add the next node in the list if it exists
            if(lists[p.second]->next)
            {
                std::pair<ListNode*, int> pNext = {lists[p.second]->next, p.second};
                minHeap.push(pNext);
                lists[p.second] = lists[p.second]->next;
            }
            curr = curr->next; // Advance the list
        }
        return dummyHead->next;
    }
};
