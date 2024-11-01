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
    void traverseFunc(TreeNode* root, std::vector<int>& inputVect)
    {
        // Recursion base case
        if(!root)
        {
            return;
        }

        // Recursion case, we traverse left sub-tree first
        traverseFunc(root->left, inputVect);
        inputVect.push_back(root->val);
        traverseFunc(root->right, inputVect);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> traverseVect;
        traverseFunc(root, traverseVect);
        return traverseVect;
    }
};
