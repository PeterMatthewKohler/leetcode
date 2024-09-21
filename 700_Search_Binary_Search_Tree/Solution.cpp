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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(nullptr == root)
        {
            return false;
        }

        // If search value is greater than node val, we search right sub-tree
        if(val > root->val)
        {
            return searchBST(root->right, val);
        }
        else if(val < root->val) // We search left sub-tree
        {
            return searchBST(root->left, val);
        }
        else // We've found the value
        {
            return root;
        }
    }
};
