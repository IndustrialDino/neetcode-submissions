class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // xyz
        // xxyz 
        // xyxz - retain the order of the characters else we woud have xxyz 

        // i.e cannot rearrange charc - I guess that would mess with the string too

        // we need to create substrings 
        // the chosen defintion: sequence from the current string with no duplicates

        // the biggest cost would be lookup/ go through the substring for every new character

        // let me re-iterate that (feels unclear)

        // substr: a seuqnce from current str with no repetitions
        // a substr gets created when the current char was already observed in the current substr


        // Key operations: create str, lookup if a char is in str, update str
        
        /*
        Algorithm:
        - iterate through every element of the string
        - keep appending to the current string unless the new char is already present in the string
        - push the substr to a vector
        - clear current local str and set curr char as new string
        
        // how to handle the case where the last char is a new substring in itself 
        // specifically, we should not miss adding the string corresponding to the last char to the vector 


        v2:
        - define a vector of strings, init with an empty string
        - iterate through every element of the string
        - keep appending to the last string in vector unless the curr char is already present in the string
        - else create a new string in the vector with current char


        // handles termination cases easily 
        // create ste and update str are handles within the vector of strings data store

        // iterate through the vector for substring with highest length

        // can optimize the data store further to avoid re-iteration and making the lookup easier (Tuple (substr, set of chars, size).update(<char>))
        // ON Update we could also track the longest substr
        */

        std::vector<string> substr_store{""};
        for (const char val: s) { // bbb
            string& last_substr_ref = substr_store[substr_store.size() - 1]; // "b"
            if (last_substr_ref.find(val) == std::string::npos) // b not in ""
                last_substr_ref += val; // "" + b = "b" (?)
            else 
                // issue seems to be with creating a new string 
                // to_string does not provide a char to string converion 
                // simpler way
                substr_store.push_back(std::string{val}); // ["b", "b"]
        }

        int max = 0;
        for (const auto& substr: substr_store){
            if (substr.size() > max)
                max = substr.size();
        }

        return max;
    }
};
