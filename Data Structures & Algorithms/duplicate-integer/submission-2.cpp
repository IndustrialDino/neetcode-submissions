#include <algorithm>
#include <set>
#include <iostream>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create a set of the numbers
        // if the size of the set is less than array
        // then the array has duplicates

        const uint size_arr = nums.size();

        // create set
        std::set<int> unique_set(nums.begin(), nums.end());

        bool arr_has_only_unique_value = \
            unique_set.size() == nums.size();

        // has_duplicates = !arr_has_only_unique_value 
        return !arr_has_only_unique_value;

        // time complexity
        // inserting an element into a set (red-black tree internals)
        // takes O(log n) for each element 
        // hence the overall time complexity is O(n logn)
        // As for space, we would need O(n) size, at max, to hold
        // the sorted information

        // // how woud I do this with sort 
        // // sort and check if pairs are equal
        // // starting with first element 
        // std::vector<int> sorted_nums(nums); // creates a copy

        // sorted_nums.sort();

        // for (int i =0; i < sorted_nums.size() -1; i++) {
        //     if (sorted_nums[i] == sorted_nums[i+1]){
        //         return true;
        //     }
        // }

        // // time complexity 
        // // - sort the array say O(n log n) ? - would expect to be equal to the creating a set
        // // - go through each elment of the sorted array O(n)

        // // space complexity of O(n)
    }
};