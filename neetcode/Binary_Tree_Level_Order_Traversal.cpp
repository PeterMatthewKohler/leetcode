/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         deque<TreeNode*> deque; // Storage
         vector<vector<int>> retVect; // Return object
         // Get the root as our starting point
         if(root)
         {
            deque.push_back(root);
         }
         int level = 0;
         while(deque.size() > 0)
         {
            int length = deque.size();
            vector<int> levelVect;  // Storage for this level
            for(int i = 0; i < length; i++)
            {
                // Add the new entries for this level to the deque
                TreeNode* curr = deque.front();
                deque.pop_front();
                levelVect.push_back(curr->val);
                // If there are child nodes
                if(curr->left)
                {
                    deque.push_back(curr->left);
                }
                if(curr->right)
                {
                    deque.push_back(curr->right);
                }
            }
            retVect.push_back(levelVect);
            // Proceed to the next level
            level++;
         }
         return retVect;
    }
};
