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
        // Edge case: tree is empty
        if(!root){return {};}
        std::vector<std::vector<int>> retVect;
        std::queue<TreeNode*> queue;
        std::vector<TreeNode*> level;
        // Start with the root
        queue.push(root);
        while(!queue.empty())
        {
            int levelLength = queue.size();
            std::vector<int> tempVect;
            for(int i = 0; i < levelLength; i++)
            {
                TreeNode* tempNode = queue.front();
                queue.pop();
                tempVect.push_back(tempNode->val);
                if(tempNode->left){queue.push(tempNode->left);}
                if(tempNode->right){queue.push(tempNode->right);}
            }
            retVect.push_back(tempVect);
        }
        return retVect;
    }
};
