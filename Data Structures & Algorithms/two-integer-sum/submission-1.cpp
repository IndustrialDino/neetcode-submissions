class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // identify the address of integers such that the integers sum to a target
        // sort array
        // early exit cases: sum < smallest of integers
        // organize a grid
        // each cell has an (i, j) associated with the integer nums

        // since i == j is not a valid solution - skip the principal diagonal
        // and since additions are commutative, it's sufficient to choose 
        // either lower or upper triangle of the matrix


/*
    0     1     2   3   4
0 
1 (1,0)
2 (2,0) (2, 1) 
3 (3,0) (3, 1) (3,2) 
4 (4,0) (4, 1) (4,2) (4,3)

If we choose lower triaangle then we are need to examine all pairs (i, j)
such that i > j
*/ 
        // we need to loop through all the element atleast once
        // brute force - n x n
        // an optimized solution would be avoid checking repeat pairs
        // owing to commutative nature of addition operation

        /*
        Algo:
        - for every j in nums.size()
        - for every i (> j) in nuns.size()
        - if (nums[i] + nums[j] == target) return [i, j] // return smallest value first

        // re-writing the looping conditionals for ease of underastanding
        - for every i in [0, nums.size()]
        - for evvery i in [0, i) // note i is not included
        // same conditional as before
        */

        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if(nums[i] + nums[j] == target)
                    return std::vector<int>{j, i}; // j is samller than i as per the second loop - so that works well
            }
        }
        
        // what's the default case?
        return std::vector<int>{-1, -1}; // using negative as a easy check - since indices cannot be -ve
        
    }
};
