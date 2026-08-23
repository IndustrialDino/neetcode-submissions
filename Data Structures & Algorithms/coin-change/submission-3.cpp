class Solution {
public:
    unordered_map<int, int> memory;
    int dynamicProgrammingDFS(int val, const int amount, const vector<int>& coins){
        if (val == amount) return 1;
        if (val > amount) return INT_MAX/2;

        set<int> coin_outcomes;
        for (const auto& coin: coins){
            int outcome;
            if (! memory.contains(val+ coin)) {
                outcome =  dynamicProgrammingDFS(val + coin, amount, coins);
                memory[val+ coin] = outcome;
            } else {
                outcome = memory[val+ coin];
            }

            coin_outcomes.insert(outcome);
        }

        return *coin_outcomes.begin(); // minimum or a sorted set
    }
    int coinChange_1(vector<int>& coins, int amount) {
        /*
        For K conins 
        At every step we have k choices
        that could lead to some amount 
        we will keep track of the outcome of each choice - so that we can reuse 
        and choose the min value  
        */
        return dynamicProgrammingDFS(0, amount, coins);
    }

    void pureDFS(const int val, const int steps_so_far, int& min_step, const int& amount, const vector<int>& coins){
        if (val > amount) return;

        if (val == amount) {
            min_step = min(min_step, steps_so_far);
            return;
        } 


        for (const auto& coin: coins){
            if (coin > (amount-val)) continue;
            pureDFS(val + coin, steps_so_far +1, min_step, amount, coins);
        }
    }

    int coinChange(vector<int>& coins, int amount) {

        int val = 0;
        int steps_so_far = 0;
        int min_step = INT_MAX/2;
        pureDFS(val , steps_so_far, min_step, amount, coins);

        if (min_step == INT_MAX/2) return -1;
        return min_step;

    }
};
