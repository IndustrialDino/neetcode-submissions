#include <sstream>
class Solution {
public:
    char getLowerChar(const char& c) const {
        if (c >= 'A' && c <= 'A') return 'a' + c - 'A';

        return c;
    }
    std::string getHash(const std::string& str) const{
        std::array<int, 26> countT{};
        for (const auto& c: str) {
            int val  = getLowerChar(c) - 'a';
            // std::cout << "char: " << c << " - lowerchar: " << getLowerChar(c) << " - val: " << val << " - curr countT[val]: " << countT[val] << std::endl;
            countT[val]++;
        }

        std::stringstream ss;
        for (const auto& val : countT){
            ss << "#" << val;
        }

        return ss.str();
    } 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hash_map;
        
        for (const auto& str: strs){
            // std::cout << "str: " << str << std::endl;
            // std::cout << "str: " << str << " - hash: " << getHash(str) << std::endl;
            hash_map[getHash(str)].push_back(str);
        }


        std::vector<std::vector<std::string>> result;
        for (const auto& [key, val] : hash_map){
            result.push_back(val);
        }

        return result;
    }
};
