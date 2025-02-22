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
    bool isTreeIdentical(TreeNode* root, TreeNode* subRoot)
    {
        // Recursion base case
        if(!root && !subRoot)
        {
            return true;
        }
        // Pre-order traversal, if root and children match, we continue on
        // If subroot is null, we've gotten to the end of that branch
        if((root && subRoot) && (root->val == subRoot->val))
        {
            return isTreeIdentical(root->left, subRoot->left) && isTreeIdentical(root->right, subRoot->right);
        }
        else
        {
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Traverse tree and check if root val == subRoot val to start isTreeIdentical function
        if(!root)
        {
            return false;
        }
        // DFS
        bool res = false;
        if(root && root->val == subRoot->val)
        {
            res |= isTreeIdentical(root, subRoot);
        }
        res |= isSubtree(root->left, subRoot);
        res |= isSubtree(root->right, subRoot);
        return res;
    }
};
