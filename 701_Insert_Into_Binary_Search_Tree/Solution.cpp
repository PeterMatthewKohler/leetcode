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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(nullptr == root)
        {
            return new TreeNode(val); // Create a new node at the proper location after recursion reaches the bottom
        }

        // If insertion value is greater than root val, we traverse to the right
        if(val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else if(val < root->val) // We traverse to the left
        {
            root->left = insertIntoBST(root->left, val);
        }
        // Return the root node after the recursion finishes
        return root;
    }
};
