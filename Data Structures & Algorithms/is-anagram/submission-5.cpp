class Solution {
public:

    char normalizeCharToLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return 'a' + (c - 'A');
        
        return c;
    }
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> countT;
        for (int i =0; i < s.length(); i++){
            countT[normalizeCharToLower(s[i])]++;
            countT[normalizeCharToLower(t[i])]--;            
        }

        for (const auto& [key, val] : countT) {
            if(val != 0) return false;
        }

        return true;
    }
};
