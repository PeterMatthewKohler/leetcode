class Solution {
public:

    void dfs(std::vector<std::vector<char>>& board, int row, int col) {
        int rows = board.size(), cols = board[0].size();
        // Out of bounds
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        // Already revealed or not an unrevealed empty cell
        if (board[row][col] != 'E') {
            return;
        }
        int mines = numAdjacent(board, row, col);
        // If adjacent mines exist, reveal number and stop
        if (mines > 0) {
            board[row][col] = '0' + mines;
            return;
        }
        // Otherwise reveal blank immediately before recursing
        board[row][col] = 'B';

        // Run through all adjacent squares
        if(row-1 >= 0 && col-1 >= 0 && (board[row-1][col-1] == 'E')){dfs(board, row-1, col-1);}    // NW
        if(row-1 >= 0 && (board[row-1][col] == 'E')){dfs(board, row-1, col);} // N
        if(row-1 >= 0 && col+1 < cols && (board[row-1][col+1] == 'E')){dfs(board, row-1, col+1);}  // NE
        if(col+1 < cols && (board[row][col+1] == 'E')){dfs(board, row, col+1);}    // E
        if(row+1 < rows && col+1 < cols && (board[row+1][col+1] == 'E')){dfs(board, row+1, col+1);}    // SE
        if(row+1 < rows && (board[row+1][col] == 'E')){dfs(board, row+1, col);}    // S
        if(row+1 < rows && col-1 >= 0 && (board[row+1][col-1] == 'E')){dfs(board, row+1, col-1);}    // SW
        if(col-1 >= 0 && (board[row][col-1] == 'E')){dfs(board, row, col-1);}   // W

        return;
    }

    int numAdjacent(std::vector<std::vector<char>>& board, int row, int col) {
        // Check how many adjacent squares have mines
        int rows = board.size(), cols = board[0].size();
        int res = 0;
        if(row-1 >= 0 && col-1 >= 0 && (board[row-1][col-1] == 'M' || board[row-1][col-1] == 'X')){res++;}    // NW
        if(row-1 >= 0 && (board[row-1][col] == 'M' || board[row-1][col] == 'X')){res++;} // N
        if(row-1 >= 0 && col+1 < cols && (board[row-1][col+1] == 'M' || board[row-1][col+1] == 'X')){res++;}  // NE
        if(col+1 < cols && (board[row][col+1] == 'M' || board[row][col+1] == 'X')){res++;}    // E
        if(row+1 < rows && col+1 < cols && (board[row+1][col+1] == 'M' || board[row+1][col+1] == 'X')){res++;}    // SE
        if(row+1 < rows && (board[row+1][col] == 'M' || board[row+1][col] == 'X')){res++;}    // S
        if(row+1 < rows && col-1 >= 0 && (board[row+1][col-1] == 'M' || board[row+1][col-1] == 'X')){res++;}    // SW
        if(col-1 >= 0 && (board[row][col-1] == 'M' || board[row][col-1] == 'X')){res++;}   // W
        return res;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }

        dfs(board, row, col);
        return board;
    }
};
