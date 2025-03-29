class Solution {
public:
    std::vector<std::vector<bool>> path;
    bool dfs(std::vector<std::vector<char>>& board, string word, int r, int c, int idx)
    {
        // Recursion base case: we've traversed the whole word
        if(idx == word.size()){return true;}
        // Recursion base case: we're out of bounds
        if(r >= board.size() || r < 0 ||
           c >= board[0].size() || c < 0)
        {
            return false;
        }
        // Recursion base case: the char isn't correct, or we've already been here
        if(path[r][c] || (board[r][c] != word[idx])){return false;}
        // Mark we've been here
        path[r][c] = true;
        // Traversal in every direction
        bool res = (dfs(board, word, r-1, c, idx+1) || // Up
                    dfs(board, word, r, c+1, idx+1) || // Right
                    dfs(board, word, r+1, c, idx+1) || // Down
                    dfs(board, word, r, c-1, idx+1));
        // Remove this node from the path
        path[r][c] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Initialize
        std::vector<bool> row(board[0].size(), false);
        for(int i = 0; i < board.size(); i++)
        {
            path.push_back(row);
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board, word, i, j, 0)){return true;}
            }
        }
        return false;
    }
};
