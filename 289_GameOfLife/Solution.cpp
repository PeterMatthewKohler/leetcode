class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Copy board so we can get the update
        auto applyRules = [board](int row, int col) {
            int neighbors = 0;
            if(row-1 >= 0 && col-1 >= 0){neighbors += board[row-1][col-1];} // NW
            if(row-1 >= 0){neighbors += board[row-1][col];} // N
            if(row-1 >= 0 && col+1 < board[0].size()){neighbors += board[row-1][col+1];} // NE
            if(col+1 < board[0].size()){neighbors += board[row][col+1];} // E
            if(row+1 < board.size() && col+1 < board[0].size()){neighbors += board[row+1][col+1];} // SE
            if(row+1 < board.size()){neighbors += board[row+1][col];} // S
            if(row+1 < board.size() && col-1 >= 0){neighbors += board[row+1][col-1];} // SW
            if(col-1 >= 0){neighbors += board[row][col-1];} // W
            
            // Live cell
            int res = 0;
            if(board[row][col]) {
                if(neighbors < 2){res = 0;}    // Rule 1
                else if(neighbors == 2 || neighbors == 3){res = 1;}    // Rule 2
                else if(neighbors > 3){res = 0;}   // Rule 3
            }
            else {  // Dead cell
                if(neighbors == 3){res = 1;}   // Rule 4
                else{res = 0;} // Stays dead
            }
            return res;
        };
        // Apply the rules to the grid
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] = applyRules(i, j);
            }
        }
    }
};
