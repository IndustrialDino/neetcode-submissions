class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // can I parse the future prices on any given day?
        // day i - where the price of coin is least
        // day j - where price of the coin is highest

        // and on every other day - do nothing - go to park!

        // Max Profit - Sell 1 coin at the highest price 
        // and Purchase 1 coin at the least price

        // Can I purchase N coins on 1 day? - No

        // min max problem

        /*
        Algorithm:
        - parse prices 
        - min and max
        - std::min(prices)
        - std::max(prices)

        // test case [2, 7, 1]

        min - [1]
        max - [7]

        return 7-1 = 6 profit

        // so we need to we aware of "time"

        // Cond1: sell date should NOT be before the buy date

        // min and max is still valid
        // min should satisy cond1

        0th element - buy date
        1st element - 

        getBuyDate
        {
            parse the array
            [2, 7, 1]
            highest_val = 7
            ideal buy date value is least value less than 7 and before the position of high value
            [2, 6, 7, 1]
            
            max in the array and index (i) of max value -> Sell Value and Date


            buy date - least in [0, i] - Buy Value and Date
        }

        getSellDate
        */

        // sell date
        // int sell_value = std::max(prices.begin(), prices.end());
        // std::cout << "sell value: " << sell_value << std::endl;
        // int maxth_element = std::max_element(prices.begin(), prices.end());

        // // buy date
        // int buy_value = std::min(prices.begin(), prices.begin() + maxth_element);

        /*
        [1, 2]
        [2, 1, 10]
        [2, 1, 10, 1]
        [2, 10, 3, 1, 100]
        [100, 1, 10, 2] 
        max = -1 (default)
        max_idx = -1 // ?

        sell_date (> 1)
        buy_date (< sell_date and sell date exists)

        buy date (> 0) - least value in the
        sell_date (> buy date [&& value is greater as well] ) 
        */

        // int sell_date = 1;
        // int buy_date = 0;
        // for (int i = 0; i < prices.size(); i++) {
        //     // update sell date
        //     if((i > sell_date) && (prices[i] > prices[sell_date]))
        //         sell_date = i;
        //     else {
        //         // update buy date
        //         if ((i > buy_date) && (prices[i] < prices[buy_date]))
        //             buy_date = i; // 
        //     }
        // }

        //---

        // int sell_date = 0;
        // int buy_date = 0;
        // for (int i = 1; i < prices.size(); i++) {
        //     int day_price = prices[i];

        //     if ( day_price < prices[buy_date]){
        //         buy_date = i;
        //         sell_date = i;
        //     } 

        //     if(day_price > prices[sell_date]){
        //         sell_date = i;
        //     }
        // }

        // return prices[sell_date] - prices[buy_date];

        // ---

        // find max in [1, N]
        int max_profit = 0;
        for (int j=0; j < prices.size() -1; j++){
            
            // max date
            int max_date = j+1;
            for (int i = j+1; i < prices.size(); i++){
                if(prices[i] > prices[max_date])
                    max_date = i;
            } 

            int profit = prices[max_date] - prices[j];

            if (profit > max_profit)
                max_profit = profit;
        }

        return max_profit;
    }
};
