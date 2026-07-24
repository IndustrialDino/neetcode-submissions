#include <algorithm>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // for each string - get the sorted vector representation
        // maintain a hashtable of the representations and vector input strings
        
        // iterate through hashtable and create vector of vector

        // test cases:
        // case 1: abc {abc, bca, cab, cba, bac, acb}

        std::unordered_map<std::string, std::vector<std::string>> anagram_map;

        for (const auto str: strs){
            // common representation
            const std::string str_key = this->getSortedVectorRep(str);

            auto itr = anagram_map.find(str_key);

            if (itr == anagram_map.end()){
                // create the new key-val entry
                anagram_map.insert({str_key, std::vector<string>{str}});   
            } else {
                // update val
                itr->second.push_back(str);
            }
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& [key, val]: anagram_map){
            result.push_back(val);
        }

        return result;
    }

    std::string getSortedVectorRep(const std::string& str){
        std::vector<char> sorted_str(str.begin(), str.end());
        
        sort(sorted_str.begin(), sorted_str.end());

        return string(sorted_str.begin(), sorted_str.end());
    }
};
