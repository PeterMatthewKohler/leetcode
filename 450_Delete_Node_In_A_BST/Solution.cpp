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
        // Traverse the BST to find the bottom (smallest) node
        while(curr && curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(nullptr == root)
        {
            return nullptr;
        }

        // Traverse until we find the node
        if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        // If we find it, deletion procedure depends on how many (if any) child nodes node has
        else
        {
            // Only one child we just shift the remaining node upwards
            // If there is no left node
            if(nullptr == root->left)
            {
                return root->right;
            }
            else if(nullptr == root->right) // If no right node
            {
                return root->left;
            }
            // If there are two children, we need to pick left mode node in right subtree
            else
            {
                TreeNode* minNode = findMinNode(root->right);
                root->val = minNode->val;   // Replace deleted node with min node in right subtree
                root->right = deleteNode(root->right, root->val);   // Delete the min node now that we've shifted it to this root node
            }
        }
        return root;
    }
};
