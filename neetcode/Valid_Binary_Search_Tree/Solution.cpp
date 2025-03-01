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

    bool valid(TreeNode* root, int min, int max)
    {
        // Recursion base case:
        if(!root){return true;}
        if(!(min < root->val && max > root->val)){return false;} // Invalid BST
        // Traverse using DFS, keep track of current min and max possible values
        return valid(root->left, min, root->val) && // New max possible value
               valid(root->right, root->val, max);  // New min possible value
    }

    // Proper BST: root is larger than all left children and smaller than all right children
    bool isValidBST(TreeNode* root) {
        return valid(root, -1000, 1000);
    }
};
