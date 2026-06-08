class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int target = board.size() * board.size();
        // Converting Boustrophedon style board into matrix row/column format
        auto bStyleToRC = [](int square, int size) {
            int rem = (square - 1) % size;
            int row = (size - 1) - ((square - 1) / size);
            // Direction of a row is based on how far it is from the bottom
            int rowFromBottom = size - 1 - row;

            int col;
            if (rowFromBottom % 2 == 0) {
                col = rem;
            } else {
                col = (size - 1) - rem;
            }
            return std::pair<int, int>{row, col};
        };
        // Every dice throw has same "cost" of 1
        // Use BFS to explore all squares reachable in <1, 2, 3...> rolls
        std::queue<int> q;
        std::unordered_set<int> visited;    // Cycle detection
        int moves = 0;
        // Start on square 1, no moves done yet
        q.push(1);
        visited.insert(1);
        // BFS
        while(!q.empty()) {
            // Process all nodes currently in queue
            int len = q.size();
            for(int i = 0; i < len; i++) {
                // Get new board locations for each square we get
                int square = q.front();
                if(square == target){return moves;}
                q.pop();
                // Add all squares reachable from this square to be processed
                for(int n = 1; n < 7; n++) {
                    // Bounds check to make sure we don't leave board
                    int next = square + n;
                    if(next > target){break;}
                    // Add next square to queue to be processed
                    auto p = bStyleToRC(next, board.size());
                    if(board[p.first][p.second] != -1){next = board[p.first][p.second];} // Snake/Ladder
                    // Ensure we haven't already been here
                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
