class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children_;
    bool word_ = false;
    ~TrieNode() {
        for (auto& pair : children_) {
            delete pair.second;
        }
    }
};

class WordDictionary {
public:
    TrieNode root;

    WordDictionary() {
    }

    ~WordDictionary() {
        // Destructor automatically cleans up root's children
    }

    void addWord(string word) {
        TrieNode* curr = &root;
        for (char c : word) {
            if (curr->children_.count(c) == 0) {
                curr->children_[c] = new TrieNode();
            }
            curr = curr->children_[c];
        }
        curr->word_ = true;
    }

    bool search(string word) {
        return recursiveSearch(word, 0, &root);
    }

private:
    bool recursiveSearch(const string& word, int idx, TrieNode* curr) {
        // Base case: reached end of word
        if(idx == word.size()){return curr->word_;}

        // If current character is '.', try all children
        if(word[idx] == '.')
        {
            for(const auto pair : curr->children_)
            {
                if(recursiveSearch(word, idx+1, pair.second)){return true;}
            }
            return false;
        }

        // If current character is a letter, check if it exists
        if(curr->children_.count(word[idx]) == 0){return false;}

        // Continue with the next character
        return recursiveSearch(word, idx+1, curr->children_[word[idx]]);

    }
};
