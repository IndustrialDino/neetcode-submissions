class Solution {
public:

    int robLine(vector<int>& nums, int start, int end){
        int n = end - start + 1; // end and start are addrs
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        std::vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start+ 1]);
        for (int i = 2; i < n; i++){ 
            dp[i] = max(nums[start + i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        /*
        simple cases
        n = 0, retrn 0
        n = 1, return nums[0]

        n = 2, return max(nums[0], nums[1])
        n = 3, return nums[1]

        last element is connected to the first element

        dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        */

        // we cannot have 0 and n-1 in the solution hence skip (n-1)th house while checking the first house
        // but what if the value of n-1 is higher than that of 0 in which case we would not have an optimal solution 

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(robLine(nums, 0, n-2), robLine(nums, 1, n-1));
        
    }
};