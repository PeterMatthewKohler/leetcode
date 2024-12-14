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
    int sum = 0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // DFS to traverse the tree and employ backtracking to check if our sum has reached the target sum
        if(!root) {return false;}
        sum += root->val;
        if(sum == targetSum)
        {
            return true;
        }
        if(hasPathSum(root->left, targetSum))
        {
            return true;
        }
        if(hasPathSum(root->right, targetSum))
        {
            return true;
        }
        // This node is not a part of the valid path, so we remove it
        sum -= root->val;
        return false;
    }
};
