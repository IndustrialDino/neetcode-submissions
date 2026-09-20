class Solution {
public:
    std::string getCharSortedStringAsHash(std::string input){
        std::string output = input;

        std::sort(output.begin(), output.end()); // O(nlogn)

        // string to lower converion - still needs iteration
        // in this example all chars are lower so we can skip this

        return output;
    }

    std::string getNumericHash(std::string input){
        std::array<int, 26> code; // stack initialized - array of fixed size
        for (const auto& c : input){
            int val = c - 'a';

            code[val]++;
        }

        std::stringstream ss;
        // ss << "#";
        for (const auto& entry: code){
            ss << "#"; // this ensure counted value are separable and #1#0#10 is different from #10#1#0
            ss << entry;
        }
        return ss.str();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::string, std::vector<std::string>> string_map;
        for (const auto& str: strs){
            // std::cout << getNumericHash(str) << std::endl;
            string_map[getNumericHash(str)].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& [key, val] : string_map){
            result.push_back(val);
        }

        return result;
    }
};
