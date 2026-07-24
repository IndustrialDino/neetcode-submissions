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

        // how woud I do this with sort 
    }
};