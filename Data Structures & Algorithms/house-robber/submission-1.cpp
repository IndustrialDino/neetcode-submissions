class Solution {
public:
    unordered_set<int> explored;

    // bool hasBeenExplored(int i) {
    //     bool has_been_robbed = explored.contains(i);
    //     has_been_explored = explored.containrs(i-1);
    //     has_been_explored = explored.contains(i+1);

    //     return has_been_explored;
    // }
    // int dfs (int i, const vector<int>& nums, int& sum_robbed){
    //     if (i < 0) return 0;

    //     int val = nums[i];
    //     if (hasBeenExplored(i)) return 0;
    //     // check_ajacent_values
    //     // dfs(i-1, nums) //why to check i-1 ? - would be already explored
    //     // dfs(i+1, nums) // this would be the immediate ajacencu

    //     return max (val, dfs(i+1, nums)); 
    // }

    int rob_v0(vector<int>& nums) {
        /*
        maximum of two houses [i-2], [i-1], [i]

        // if I is chosen, then i+1 is in accessible 
        // if so, do we skip i+1, if we do then we would leave
        // information unexplored

        // establish adjacencies for every house
        // start iterating from 0
        // if visited (;)

        10, 20, 30

                10
            yes          no
        20      30    20    30
        skip(no) yes yes    yes

        For every node, we can check if we want to rob that house or not
        i.e 1 decision - node has an adjacency

        how do we gather the maximum ?         
        */
        unordered_map<int, int> max_robbed_per_house;
        int max_robbed = 0;

        for (int i =0; i < nums.size(); i++){
            int val = nums[i];
            int last_2nd_val = (max_robbed_per_house.contains(i-2) ? max_robbed_per_house[i-2] : 0);
            int last_1st_val = max_robbed_per_house.contains(i-1) ? max_robbed_per_house[i-1] : 0;

            if (val + last_2nd_val > last_1st_val) {
                max_robbed_per_house[i] = val + last_2nd_val;
            } else {
                max_robbed_per_house[i] = last_1st_val;
            }
        }

        return max_robbed_per_house[nums.size()-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        unordered_map<int, int> dp; // or std::vector<int> dp(n); allocating the memory chunk is imporant if we don't use push_back else we would be operating on unallocated/ garbage memory
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};
