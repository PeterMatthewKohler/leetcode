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

    TreeNode* findMinNode(TreeNode* root)
    {
        TreeNode* curr = root;
        // Traverse tree to find the minimum left-most node
        while(curr && curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Recursion base case
        if(root == nullptr)
        {
            return nullptr;
        }

        // Traverse to find the node with the value of key
        if(key > root->val) // If key is greater than value, traverse to the right
        {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) // If key is less than value, traverse to the left
        {
            root->left = deleteNode(root->left, key);
        }
        else // If we've found the node we want to delete
        {
            // 2 possible cases
            // 1. Node has 0 or 1 child
            // 0 children is covered in the recursion base case
            if(root->left == nullptr) // 1 child on the right
            {
                return root->right;
            }
            else if(root->right == nullptr) // 1 child on the left
            {
                return root->left;
            }
            else // Node has 2 children, we need to find the min node in the right sub-tree
            {
                TreeNode* minNode = findMinNode(root->right);  // Find the in-order successor(min node in right subtree)
                root->val = minNode->val;   //'Delete' the desired node and replace
                root->right = deleteNode(root->right, root->val); // Delete the old node that has been shifted up.
            }
        }
        return root;
    }
};
