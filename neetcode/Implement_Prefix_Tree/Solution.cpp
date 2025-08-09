class TrieNode {
    public:
        std::unordered_map<char, TrieNode*> children_;
        bool word_ = false;
};

class PrefixTree {
public:
    TrieNode root_;
    
    void insert(string word) {
        TrieNode* ptr = &root_;
        for(int i = 0; i < word.size(); i++)
        {
            // If node for char doesn't exist yet, we make one
            if(ptr->children_.find(word[i]) == ptr->children_.end())
            {
                ptr->children_.insert({word[i], new TrieNode()});
            }
            // Traverse to the next node
            ptr = ptr->children_[word[i]];
        }
        ptr->word_ = true;
    }
    
    bool search(string word) {
        // Iterate through string if we find a char not in tree, return false
        TrieNode* ptr = &root_;
        for(char letter : word)
        {
            if(ptr->children_.find(letter) == ptr->children_.end()){return false;}
            else{ptr = ptr->children_[letter];}
        }
        if(ptr->word_){return true;}
        else{return false;}
    }
    
    bool startsWith(string prefix) {
        // Iterate through string if we find a char not in tree, return false
        TrieNode* ptr = &root_;
        for(char letter : prefix)
        {
            if(ptr->children_.find(letter) == ptr->children_.end()){return false;}
            else{ptr = ptr->children_[letter];}
        }
        return true;
    }
};

