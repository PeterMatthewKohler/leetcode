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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Recursion base case:
        if(!root || !p || !q){return nullptr;}
        // Traversal determined by values of p,q in relation to root
        // If root is larger than p & q, we traverse to the left
        if(max(p->val, q->val) < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        // root is smaller than p & q, traverse to the right
        else if(min(p->val, q->val) > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // Only other option is LCA is root
        else
        {
            return root;
        }
    }
};
