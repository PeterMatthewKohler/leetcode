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
long long int prevVal = LLONG_MIN;  // Initial value we are comparing against, will always be lower than any possible int node value value
    bool isValidBST(TreeNode* root) {
        // Recursion base case
        if(!root)
        {
            return true;
        }

        // Perform in-order traversal
        if(isValidBST(root->left) && (root->val > prevVal)) // Traverse left sub-tree and compare with previous value to determine if BST is valid
        {
            prevVal = root->val;    // Performed comparison above in conditional, now assign new previous value
            return isValidBST(root->right); // Now do right sub-tree
        }
        return false;   // This will never be reached?
    }
};
