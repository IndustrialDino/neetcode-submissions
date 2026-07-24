#include <unordered_map>
#include <vector>
class Solution {
private: 
    std::unordered_map<int, uint> organized_data;
    std::vector<int> sorted_keys;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return a vector of keys sorted by their freq using max heap
        return this->PriorityQueuestopKFrequent(nums, k);

        // returned a vector keys sorted by their freq using sort operation
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

    vector<int> PriorityQueuestopKFrequent(vector<int>& nums, int k){
        // organize the data into a hash map
        // further order each entry in the hashmap using priority queue
        // get the ordered data from the priority queue


        if (k > nums.size())
            return vector<int>();

        for (const auto& val: nums) {
            auto itr = this->organized_data.find(val);

            if(itr == this->organized_data.end())
                this->organized_data.insert({val, 1});
            else 
                itr->second += 1;
        }

        if (k > this->organized_data.size())
            return vector<int>();

        struct Entry {
            int key;
            uint freq;
        };

        

        // min heap implies - on pop the min entry 
        // (of the current values) gets ejected and returned

        // max heap - on pop the current max entry 
        // of the current set gets returned

        // we will use max heap for our simple toy test

        // max_operator
        auto cmp = [&](const Entry& a, const Entry& b){
            return a.freq < b.freq; // verified by adding a test
        };

        // decltype is a language keyword to get the type
        // decltype(is_max) returns the return type of is_max 
        // which is bool
        // now we would need to pass in the object of the type 
        // that has been declared when instantiating the priority queue
        std::priority_queue<
        Entry, 
        std::vector<Entry>, 
        decltype(cmp)> max_heap(cmp);

        // good programmers debug
        // better programmers add a test to understand operation - ChatGPT

        // add test to capture how the current p_queue is working
        // max_heap.push({1, 5});
        // max_heap.push({2, 2});
        // max_heap.push({3, 8});

        // std::cout << max_heap.top().freq << '\n';
        // seems like the top element is the minium 
        // so we will invert the sign in cmp from > to <

        for (const auto& [key, val] : this->organized_data){
            max_heap.push(Entry{key, val});
        }

        std::vector<int> result;
        for (int i =0; i < k; i++){
            const auto& entry = max_heap.top();
            result.push_back(entry.key);
            max_heap.pop();
        }

        return result;
    }
};
