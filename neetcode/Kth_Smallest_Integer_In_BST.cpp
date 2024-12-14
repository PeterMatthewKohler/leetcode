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
    vector<int> sortedArr;
    void inorderTraversal(TreeNode* root)
    {
        if(!root){return;};  // Recursion base case
        inorderTraversal(root->left);
        sortedArr.push_back(root->val);
        inorderTraversal(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        // Get a sorted array of the tree's values
        inorderTraversal(root);
        // Return the desired value
        return sortedArr[k-1];
    }
};
