class TreeMap {

struct TreeNode {
    int key_;
    int val_;
    TreeNode* left_;
    TreeNode* right_;
    // Constructor
    TreeNode(int key, int val) : key_(key), val_(val), 
                                 left_(nullptr), right_(nullptr) {};
};

TreeNode* root_;

public:
    TreeMap() {
        root_ = nullptr;
    }

    void insertRecursion(TreeNode*& root, int& key, int& val) {
        // Make a new node
        if(!root){root = new TreeNode(key, val); return;}
        // If we find the key, overwrite the value
        if(root->key_ == key){root->val_ = val; return;}
        // Otherwise, recurse further into the tree
        if(root->key_ < key) {insertRecursion(root->right_, key, val);} // Right
        else{insertRecursion(root->left_, key, val);} // Left
        return;
    }

    void insert(int key, int val) {
        insertRecursion(root_, key, val);
        return;
    }

    int get(int key) {
        TreeNode* curr = root_;
        while(curr) {
            // Traverse the tree
            if(curr->key_ == key){return curr->val_;}
            else if(curr->key_ < key){curr = curr->right_;}
            else{curr = curr->left_;}
        }
        return -1;
    }

    int getMin() {
        if(!root_){return -1;}
        // Should be left most value
        TreeNode* curr = root_;
        while(curr->left_){curr = curr->left_;}
        return curr->val_;
    }

    int getMax() {
        if(!root_){return -1;}
        // Should be right most value
        TreeNode* curr = root_;
        while(curr->right_){curr = curr->right_;}
        return curr->val_;
    }

    TreeNode*& findMinRef (TreeNode*& node) {
        if(!node->left_){return node;}
        return findMinRef(node->left_);
    };

    void removeRecursion(TreeNode*& root, int key) {
        if (!root) {return;}

        if (key < root->key_) {removeRecursion(root->left_, key);}
        else if (key > root->key_) {removeRecursion(root->right_, key);}
        else {
            // Found node.
            // Case: zero or one child
            if (!root->left_ || !root->right_) {
                TreeNode* old = root;
                root = root->left_ ? root->left_ : root->right_;
                delete old;
                return;
            }

            // Case: two children
            // Find minimum value in right sub-tree
            TreeNode*& successor = findMinRef(root->right_);

            root->key_ = successor->key_;
            root->val_ = successor->val_;

            TreeNode* old = successor;
            successor = successor->right_;
            delete old;
        }
    }

    void remove(int key) {
        removeRecursion(root_, key);
        return;
    }

    void dfsGetKeys(TreeNode* root, std::vector<int>& res) {
        // Base case, root is nullptr
        if(!root){return;}
        // Traverse left
        dfsGetKeys(root->left_, res);
        // Push to vector
        res.push_back(root->key_);
        // Traverse right
        dfsGetKeys(root->right_, res);
        return;
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> res;
        dfsGetKeys(root_, res);
        return res;
    }
};

