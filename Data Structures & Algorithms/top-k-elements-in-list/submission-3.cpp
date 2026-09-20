

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, tin>>
        >;

        // count[val] : feq

        //vector<pair<freq, val>>

        // sort(vector in descending order) - automatically takes the freq as the sorting criteria
        // how to do this in the context of a struct ?
        
        // sort uses "<" operator by default
        // implment operator<(struct& other) function in the Struct and call sort of the vect of structs

        // use vector.rbegin() and vector.rend() for arranging in descending order
        // or std::sort followed by std::reverse

        // result(top K items in sorted vector)

        // priority queue<Element, vector<Element>, greater/lesser<Element>> heap
        /*
        Top K greatest/ largest/ Most Frequent - requires us to remove least frequency from current heap
        // min heap keep min freqequent at top - so we can pop it out
        // min heap uses Greater operator

        Tp K Smallest/ Closest - requires us to remove highest metriced Element from current heap
        // max heap keep max frquent/ greatest at top - so we can pop it out
        // max heap uses Lesser operator
    
        */
    }
};
