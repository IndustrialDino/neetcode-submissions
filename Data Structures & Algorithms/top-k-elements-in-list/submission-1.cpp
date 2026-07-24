#include <unordered_map>
#include <vector>
class Solution {
private: 
    std::unordered_map<int, uint> organized_data;
    std::vector<int> sorted_keys;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k > nums.size())
            return vector<int>();
        /**
        * Organize Data by key and number of repetions - HAshTable
        * Run one pass through the Organized hash Table and sort keys by their frequency - highest to lowest
        * Run through the sorted array or return the first k elements of the sorted array
        */

        // would be good to learn how to sort an array in reverse

        /**
        * test Case 1: [1, 2, 2, 3, 3, 3] 
            k=1, O/P = 3
            K=2, O/P = [2. 3] or [3, 2] -> order invariant
        * 
          how about case where k is greater than the number of unique values in the array
          how about k = -1
        */

        // if I did not understand the problem, ask "can you please give me an example"
        // so that I can better understand the problem statement

        for (const auto& val: nums) {
            auto itr = this->organized_data.find(val);

            if(itr == this->organized_data.end())
                this->organized_data.insert({val, 1});
            else 
                itr->second += 1;
        } // we should have all the data organized by key and frequency

        if (k > this->organized_data.size())
            return vector<int>();

        // this would say lhs is the higher value 
        // hence sorts form high to low
        // & is for local vars
        // this is for member vars
        auto comparator = [&](const int& lhs, const int& rhs) {
            return organized_data.at(lhs) > organized_data.at(rhs);
        };

        // sort the hash map by the frequency
        for (const auto& [key, frq] : this->organized_data) {
            // for now just put the key in a "random" order
            this->sorted_keys.push_back(key);
        }

        sort(this->sorted_keys.begin(), this->sorted_keys.end(), comparator);

        return std::vector<int>(this->sorted_keys.begin(), k + this->sorted_keys.begin());
    }
    // should I add a destructor for the member variables?


};
