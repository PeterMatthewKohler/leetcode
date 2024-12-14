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
    // Solution is to do level order traversal and only add the entry at the end of
    // the data structure used to store the level
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<int> retVect;
        if(root)
        {
            queue.push(root);
        }
        int level = 0;
        while(queue.size() > 0)
        {
            int length = queue.size();
            vector<int> levelVect;
            for(int i = 0; i < length; i++)
            {
                TreeNode* curr = queue.front();
                queue.pop();
                levelVect.push_back(curr->val);
                if(curr->left)
                {
                    queue.push(curr->left);
                }
                if(curr->right)
                {
                    queue.push(curr->right);
                }
            }
            retVect.push_back(levelVect.back());
        }
        return retVect;
    }
};
