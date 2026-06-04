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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base case: have the trees ended at the same place?
        if(root1 == nullptr && root2 == nullptr) {return true;}
        // Base case: structural mismatch
        if(root1 == nullptr || root2 == nullptr) {return false;}
        // Base case: value mismtach
        if(root1->val != root2->val) {return false;}
        // Recursively check the children
        bool normal = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool flipped = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return normal || flipped;
    }
};
