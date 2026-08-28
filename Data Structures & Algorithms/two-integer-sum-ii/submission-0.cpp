class Solution {
public:
    vector<int> twoSumMap(vector<int>& numbers, int target) {
        unordered_map<int, int>val2Idx;

        for (int i = 0; i < numbers.size(); i++) {
            int diff = target - numbers[i];
            if (val2Idx.find(diff) != val2Idx.end()) {
                int index1 = min(i, val2Idx[diff]);
                int index2 = max(i, val2Idx[diff]);

                return {index1 + 1, index2 + 1};
            }
            val2Idx.insert({numbers[i], i});
        }

        return {0, 0};
    }


    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; 
        int j = numbers.size() -1;

        while (i < j){
            int curr_sum = numbers[i] + numbers[j];
            if (curr_sum == target) return {i+1, j+1};

            if (curr_sum < target) i++;

            if (curr_sum > target) j--;
        }

        return {0, 0};
    }
};
