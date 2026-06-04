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

    void preOrder(TreeNode* root, std::vector<int>& vals) {
        // Base case
        if(!root){return;}
        // Push the val into the array
        vals.push_back(root->val);
        // Recursive call left then right
        preOrder(root->left, vals);
        preOrder(root->right, vals);
    }

    void flatten(TreeNode* root) {
        // Brute force, just get the values through pre-order traversal then rebuild the tree
        std::vector<int> vals;
        preOrder(root, vals);
        // Now rebuild tree using the values we collected
        TreeNode* curr = new TreeNode;
        curr->right = root;
        for(const auto& val : vals) {
            if(!curr->right) {
                curr->right = new TreeNode(val);
            }
            else {
                curr->right->val = val;
            }
            curr->left = nullptr;
            curr = curr->right;
        }
    }
};
