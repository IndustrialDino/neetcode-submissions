class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        // unordered_map<pair<int, int>, unordered_set<char>> grid; // unordered requires a hash function implicitly, pair does not provide this. It does provide logical "<" operator and this works for map 
        // type which is a tree type data structure 
        map<pair<int, int>, unordered_set<char>> grid; // O(logn)

        for (int r = 0; r < 9 ; r++){
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.') continue;

                char val = board[r][c];

                bool was_seen_in_row = rows[r].contains(val);
                bool was_seen_in_col = cols[c].contains(val);
                std::pair<int, int> grid_key = {r/3, c/3};
                bool was_seen_in_grid = grid[grid_key].contains(val);
                if(was_seen_in_row || was_seen_in_col || was_seen_in_grid) return false;

                rows[r].insert(val);
                cols[c].insert(val);
                grid[grid_key].insert(val);
            }
        }

        return true;
    }
};
