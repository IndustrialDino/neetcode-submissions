class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // create an n/2xn/2 matrix that maintains the combination
        // of numbers

        uint size_nums = nums.size();

        uint partition = size_nums/2;

        // This assumes that the values are on each side of the half way point
        // achieve the matrix through for loop
        // for (int i=0; i < partition; i++) {
        //     for (int j = partition; j < nums.size(); j++){
        //         if (nums[i] + nums[j] == target)
        //             return std::vector<int>{i, j};
        //     }
        // }
  

        // option 2
        // arr_1 + reverse(arr_1) == target 
        // but that would be same as the half way solution

        // option 3
        // the original idea - create a combination matrix
        // std::vector<int, int> addr_mtx;

        // (0,0) (0,1) (0,2)
        // (1,0) (1,1) (1,2)
        // (2,0) (2,1) (2,2)

        // seems like we only need to look at combinations
        // in the lower triangle
        // current number [remaning in the arr]

        // naive solution 
        // do I and J have to be unique ?
        // may be the values have to present in the arr
        // and each value cannot be re-used
        // for (int i = 0; i < nums.size(); i++){
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (i == j)
        //             continue;
        //         if (nums[i] + nums[j] == target)
        //             return std::vector<int>{i, j};
        //     }
        // }

        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target)
                    return std::vector<int>{i, j};
            }
        }

        // default values for debugging
        return std::vector<int>{-1, -1};
    }
};
