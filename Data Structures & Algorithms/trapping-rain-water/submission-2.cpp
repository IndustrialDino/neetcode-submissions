class Solution {
public:

    int getLeftMax(vector<int>& height, int curr_index){
        // what is the current index is 0 
        // fixed by skipping first element in the main loop
        int max_val = 0;
        for (int i=0; i < curr_index; i++){
            if (height[i] > max_val)
                max_val = height[i];
        }
        return max_val;
    }

    int getRightMax(vector<int>& height, int curr_index){
        // what if the current index is end value
        // fixed by skipping last element in the main loop
        int max_val = 0;
        for (int i = curr_index +1; i < height.size(); i++){
            if (height[i] > max_val)
                max_val = height[i];
        }
        return max_val;
    }

    int trap(vector<int>& height) {
        /*
        Identify gaps 
            - each gap would be defined by column to the left and right 
            - and it's own height
            (2, 0, 3)
            (LC, G, RC)
        - what is a gap?
            LC and RC > G 
            LC and RC > 0

            given a val
            check left_ht
            if left_ht > val
            [2, 0] // iterate till 0 and terminate if next (-1) value is less than current val[0th element of the gap]
            if right > val
            [2, 0, 3] // iterate till N and terminate if next (+1) value is less than current val
        

        getFillIn(gap)
            retun least of LC, RC

        For every index
        get left max 
        get right max
        
        calcualte: min(left_max, right_max) - curr_ht
        if (val > 0)
        area += value;
        */

        // int left_max = 0
        // int area = 0;
        // for (int i = 0; i < height.size()-1; i++){
        //     int curr_ht = height[i];

        //     int right_max = getRightMax(height, i);

        //     int value = std::min(left_max, right_max) - curr_ht;

        //     left_max = std::max(left_max, curr_ht);

        //     if (value > 0)
        //         area += value;
        // }

        /*
        [0, 2, 0, 3]

        window [-3, -2, -1, 0, +1, +2, +3]
        */

        // ----
        struct GapType{
            int left_col;
            int curr_val;
            int right_col;

            void print() const {
                std::stringstream ss;
                ss << "left | curr | right: " 
                << left_col << " | " <<  curr_val << " | " << right_col;
                std::cout << ss.str() << std::endl;
            }
        };

        vector<GapType> gaps;
        int left_max = height[0];
        int right_max = height[height.size()-1];
        // second element
        for (int i = 1; i < height.size(); i++){
            int curr_ht = height[i];

            left_max = std::max(left_max, curr_ht);

            auto gap = GapType{
                .left_col = left_max, 
                .curr_val = curr_ht, 
                .right_col = right_max
            };
            gaps.push_back(gap);
        }

        // second to last element
        for (int i = height.size() -1 -1; i > 0; i--){
            int curr_ht = height[i];
            right_max = std::max(right_max, curr_ht);
            gaps[i].right_col = right_max;
        }

        int area = 0;

        for (const auto& gap : gaps){
            // gap.print();

            int value = std::min(gap.left_col, gap.right_col) - gap.curr_val;

            if (value > 0)
                area += value;
        }


        return area;


        // 
    }
};
