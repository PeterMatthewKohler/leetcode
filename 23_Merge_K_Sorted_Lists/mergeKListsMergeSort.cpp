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
    void merge(vector<int>& arr, int left, int m, int right)
    {
        // Copy sorted left and right arrays into temp arrays
        vector<int> L = {arr.begin() + left, arr.begin() + m + 1};
        vector<int> R = {arr.begin() + m + 1, arr.begin() + right + 1};

        int i = 0; // index for L
        int j = 0; // index for R
        int k = left; // index for arr

        while(i < L.size() && j < R.size())
        {
            if(L[i] <= R[j]){arr[k] = L[i++];}
            else{arr[k] = R[j++];}
            k++;
        }
        // One of the halves will have elements remaining
        while(i < L.size()){arr[k++] = L[i++];}
        while(j < R.size()){arr[k++] = R[j++];}
    }

    vector<int> mergeSort(vector<int>& arr, int l, int r)
    {
        // Base case of recursion, just return the single value array
        if(l == r) {return arr;}
        // Middle index of the array
        int m = (l + r) / 2;
        // Sort left half
        mergeSort(arr, l, m);
        // Sort right half
        mergeSort(arr, m + 1, r);
        // Merge sorted halves after recursion is done
        merge(arr, l, m, r);

        return arr;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a single vector of all the list values
        std::vector<int> list = {};
        if(lists.size() > 0)
        {
            for(auto i : lists)
            {
                if(i)
                {
                    list.push_back(i->val);
                    while(i->next)
                    {
                        i = i->next;
                        list.push_back(i->val);
                    }
                }
            }
        }

        ListNode* listHead = nullptr;
        ListNode* listTail = nullptr;
        if(list.size() > 0)
        {
            listHead = new ListNode();
            // Sort the vector
            std::vector<int> retVect = mergeSort(list, 0, list.size() - 1);
            // Turn the sorted vector into a linked list
            int vectIdx = 0;
            listHead->val = retVect[vectIdx++];
            ListNode* node = new ListNode();
            listHead->next = node;
            while(vectIdx < retVect.size())
            {
                node->val = retVect[vectIdx++];
                if(vectIdx < retVect.size())
                {
                    node->next = new ListNode();
                    node = node->next;
                }
                else
                {
                    node->next = listTail;
                }
            }
            node = nullptr;
        }
        return listHead;
    }
};
