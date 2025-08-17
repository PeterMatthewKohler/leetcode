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
        // Edge case: empty tree
        if(!root){return {};}
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> res;
        // Start with the root
        if(root){q.push(root);}
        res.push_back({root->val});
        while(!q.empty())
        {
            // Go through the current level
            int levelLength = q.size();
            std::vector<int> level;
            for(int i = 0; i < levelLength; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                // Add it's children
                if(curr->left)
                {
                    level.push_back(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    level.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }
            if(!level.empty()){res.push_back(level);} // Add level to output vector
        }
        return res;
    }
};
