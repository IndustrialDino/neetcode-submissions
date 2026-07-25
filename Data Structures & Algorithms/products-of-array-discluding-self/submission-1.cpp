class Solution {
public:
    int getArrayProduct(vector<int>& nums){
        int product_nums = 1; 

        for (const auto& val: nums){
            product_nums = product_nums * val;
        }

        return product_nums;
    }

    vector<int> productExceptSelf(vector<int>& nums) {

        std::vector<int> output;
        output.reserve(nums.size());
        // get product of all nums

        // replace nums[i] with Prod(nums)/nums[i]

        // this does not handle the case where values could be 0
        // especially values at the current idx

        // if nums[i] = 0
        //  if other elements are non-zero: product is non zero
        //  if one other element is zero: product is zero

        // account for big numbers

        // atttempt 2 - use idea of swappin values;
        // given [i]
        // a = nums[i]
        // nums[i] = 1

        // we would need an intermediary array
        // operate on the interim array - where interim gets refreshed 
        std::vector<int> interim{nums.begin(), nums.end()};

        for (int i = 0; i < nums.size(); i++) {
            // get og value 
            auto og_val = nums[i];

            // update interm[i] to 1
            interim[i] = 1;

            // get product of interim
            // this is the value of output[i]
            output.push_back(this->getArrayProduct(interim));

            // refresh the interim 
            interim[i] = og_val;
        }

        return output;

    }

    vector<int> productExceptSelfCumulative(vector<int>& nums){
        std::vector<int> results(nums.size(), 1);

        // prefix - as cumulative operation
        // left to right [1, n]
        for (int i = 1; i < nums.size(); i++) {
            int cum_val_so_far = results[i-1];
            results[i] = results[i-1] * nums[i-1];
        }

        // suffix - as cumulative operation
        // right to left [0, n-2]
        int suffix = 1;
        for (int i = nums.size() -2; i >= 0; i--){
            results[i] = results[i] * suffix;

            // next suffix
            suffix *= nums[i]; 
        }

        // how would this work for 0s and 

        return results;
    }
};
