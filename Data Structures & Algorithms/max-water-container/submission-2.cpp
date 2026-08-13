class Solution {
public:

    int maxArea(vector<int>& heights) {

        int max_area = 0;
        int l = 0;
        int r = heights.size() -1;
        /*
        
        loop until l < r
            l++;
            r--;
        */

        while (l < r){
            int col_l = heights[l];
            int col_r = heights[r];

            int area =  min(col_r, col_l) * (r - l);
            max_area = max(max_area, area);
            
            // given that we need max area
            // which a a function of min column heights
            // We want to keep the existing column either l/r
            // that is taller and explore columns from the other
            // side so that we may find a taller column in the
            // next iteraion
            if (col_r < col_l){
                // col_l is taller
                r--; // update r
            } else {
                // col_r is taller
                l++; // update l

                // also takes cares of col_r == col_l
                // at which point we would update either l/r
                // here we choose left
            }
        }

        return max_area;

    }


    int maxAreaBruteForce(vector<int>& heights) {
        /*
        Area = [delta-width-cols * min-column-ht] 
        intermediate columns can be neglected

        for every column, 
        get the other column which maximizes the area
        */

        int area = 0;

        for (int l = 0; l < heights.size() - 2; l++) 
        {
            // skip last column
            int col_l = heights[l];

            for (int r = heights.size() -1; r > 0; r--){
                int col_r = heights[r];

                // first get the area
                int width = r - l; // we would repeating several 
                int height = std::min(col_l, col_r);
                if (width > 0){ // ensures we are not repesting
                    int cont_area = width * height;

                    area = max(area, cont_area);
                }
            }
        }

        return area;
    }
};
