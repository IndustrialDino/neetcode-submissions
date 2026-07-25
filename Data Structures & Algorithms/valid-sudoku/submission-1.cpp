#include <unordered_set>
#include <algorithm>
class Solution {
public:
    struct Coord{
        int x;
        int y;
    };

    // Coord blockDim{3, 3};
    // Coord gridDim{3, 3};

    std::unordered_set<char> filler_vals{'.'};


    bool isBlockValid(Coord blockDim, Coord blockIdx, vector<vector<char>>& board) {
        // get all values in a block
        std::vector<char> block_vals;
        for (int i = 0; i < blockDim.x; i++){
            for (int j = 0; j < blockDim.y; j++){
                // i -> x -> column
                // j -> y -> row
                // data access has to be 
                // board[row][col]
                Coord gc_cell{
                    blockIdx.x * blockDim.x  + i,
                    blockIdx.y * blockDim.y  + j
                };
                char val = board[gc_cell.y][gc_cell.x];
                if (filler_vals.find(val) == filler_vals.end()){
                    // not a filler val
                    if(std::find(block_vals.begin(), block_vals.end(), val) == block_vals.end()){
                        // not seen before
                        block_vals.push_back(val);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // bool isListValid(vector<char>& char_list){
    //     // need to account for filler vals
    //     std::unordered_set<char> char_set(char_list.begin(), char_list.end());

    //     return char_set.size(()) == char_list.size();
    // }

    bool isGridValid(Coord gridDim, Coord blockDim, vector<vector<char>>& board){
        for (int i = 0; i < gridDim.x; i++) {
            for (int j =0; j < gridDim.y; j++) {
                if (!isBlockValid(blockDim, Coord{i, j}, board))
                    return false;
            } 
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // row should have unique numbers
        // cols should have unqiue numbers
        // treat row and cols differently

        // row and col are straight forward 
        // need to think about the Block - with (3x3)
        // as a cuda compute model 

        // N threads 

        // fixed size 


        // iterate over different grid layouts
        // config 1: 3x3 grid 3x3 block
        bool is_config1_valid = isGridValid(Coord{3, 3}, Coord{3, 3}, board);

        // config 2: 9x1 grid, 1x9 block
        bool is_config2_valid = isGridValid(Coord{9, 1}, Coord{1, 9}, board);

        // config 3: 1x9 gird, 9x1 block
        bool is_confif_3_valid = isGridValid(Coord{1, 9}, Coord{9, 1}, board);

        return is_config1_valid && is_config2_valid && is_confif_3_valid;
    }
};
