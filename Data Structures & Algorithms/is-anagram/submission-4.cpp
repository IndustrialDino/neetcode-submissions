#include<set>
#include<unordered_map>
#include<algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Key idea is to bring the strings to a neutal format or representation
        // and compare them directly or using the attr of the representation

        // case 1: strings are replicas 
        // then can check if string is exact match
        
        // case 2: one string is a combination of characters
        // in the other

        // create a hash table of the character count 
        // check the characters (keys) are equal
        // and the count per charater should also be equal

        // Organize each string as a set 
        // are the sets equal
        // and is the size of strings equal
        // this did not catch the case s = ccbc and t = bbcc

        // sort the string themselves
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        if(s.size() != t.size())
            return false;

        // // use the ascii value 
        // const std::set<int> s_set(s.begin(), s.end());
        // const std::set<int> t_set(t.begin(), t.end());
        
        std::unordered_map<char, uint> s_set;
        std::unordered_map<char, uint> t_set;

        getHashTable(s, s_set);
        getHashTable(t, t_set);

        if(s_set.size() != t_set.size())
            return false;

        // since they were sorted the order of characters
        // in the set should be same
        for (const auto& [key, val] : s_set){
            const auto t_itr = t_set.find(key);
            
            // key in s_set should be present in t_set
            if (t_itr == t_set.end())
                return false;

            // num of occurences of key in t_set
            // should be same as in t_set
            if (val != t_itr->second)
                return false;
        }

        // apparently this is a thing for set
        // s_set == t_set - compare them directly


        return true;
    }

    bool getHashTable(const std::string str, std::unordered_map<char, uint>& result){
        for (auto val: str){
            auto itr = result.find(val);
            if (itr == result.end())
                result.insert({val, 1});
            else 
                itr->second += 1;
            // if (result.find(val) == result.end()){
            //     // there should a nice way to add a new element 
            //     // insert?
            //     result[val] = 1;
            // } else {
            //     // increment the count
            //     result[val] += 1;
            // }
        }
        return true;
    }
};
