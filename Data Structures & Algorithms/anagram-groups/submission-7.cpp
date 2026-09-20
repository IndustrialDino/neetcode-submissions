class Solution {
public:
    std::string getCharSortedStringAsHash(std::string input){
        std::string output = input;

        std::sort(output.begin(), output.end()); // O(nlogn)

        // string to lower converion - still needs iteration
        // in this example all chars are lower so we can skip this

        return output;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::string, std::vector<std::string>> string_map;
        for (const auto& str: strs){
            string_map[getCharSortedStringAsHash(str)].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& [key, val] : string_map){
            result.push_back(val);
        }

        return result;
    }
};
