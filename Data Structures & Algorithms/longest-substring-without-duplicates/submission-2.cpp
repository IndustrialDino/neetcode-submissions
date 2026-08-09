class Solution {
public:
    std::set<char> substr_chars;

    int left_index = 0;
    int right_index = 0;

    int max_len = 0;

    std::string printSet() {
        std::stringstream ss;
        for (const auto val : substr_chars) {
            ss << val;
        }
        return ss.str();
    }

    void getCurrentSubtr(const string& s) {
        for (int i = left_index; i <= right_index; i++) {
            substr_chars.insert(s[i]);
        }
    }
    
    bool canExpandwithNextChar(const string& s){
        char val = s[right_index +1];
        bool can_expand = !substr_chars.contains(val); // if val is not contained
        return can_expand;
    }

    int getCurrentSubStrLen() {
        return substr_chars.size(); 
    }

    void removeLeftMostChar(const string& s) {
        substr_chars.erase(s[left_index]);
        left_index += 1;
    }

    void udpateMax() {
        max_len = std::max(max_len, getCurrentSubStrLen());
    }

    void iteration(const string& s) {
        getCurrentSubtr(s);
        if (canExpandwithNextChar(s)){
            right_index += 1;
        } else {
            udpateMax();
            removeLeftMostChar(s);
        }
    }

    int lengthOfLongestSubstring(string s) {

        /*

        max = 0

        abcbabbb
        ^ ^
        L R

        can expand with "b" - no

        char set{a, b, c} of substring 

        sub str len  = 3, max = (max, len)

        remove left most char 

        abcbabbb
         ^^
         LR

        char set {b, c}

        can expand with "b" - no

        sub str len  = 2, max = (max, len) = 
 
        remove left most char 

        abcbabbb
          ^
          L/R

        char set {c}

        can expand with "b" - no

        */

        while (right_index < s.size()) {
            // std::cout << "substr_chars: " << printSet() << std::endl;
            iteration(s);
        }

        return max_len;
    }
};
