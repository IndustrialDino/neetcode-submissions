class Solution {
public:

    uint getValFrom3DigitString(string str){
        return std::stoul(str);
    }

    string getValAs3Digits(uint val){
        // using manual string insertion 
        std::string val_str = to_string(val);
        switch(val_str.size()){
            case 1: 
                return "00" + val_str;
            case 2:
                return "0" + val_str;
            case 3:
                return val_str;
            default:
                return "000";
        }

        // modern cpp
        // return std::format("{:03}", str_len);
    }

    string getSubString(const uint start_idx, const uint length, const std::string& s){
        return s.substr(start_idx, length);
    }

    string encode(vector<string>& strs) {
        // the key is create a consolidated message
        // that is easy to decipher without any message specific information

        // Design of a Format
        // cannot control the specific of each of the input string

        /*
        "Format<>_" + append(strs)_with_no_separators
        // Prepend a fixed size header
        NumWords_NumCharsStr1_NumCharStr2_
        ["a"]
        001_001a
        
        [999999999999]_[9999999]
        */

        /*
        Form a json and convert the json to a string
        */

        uint num_strs = strs.size();
        std::string h_num_strs = this->getValAs3Digits(num_strs);

        std::string result = h_num_strs;
        for (const auto& str: strs){
            std::string h_num_str = this->getValAs3Digits(str.size());
            result += h_num_str;
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        const uint kStrLenDigitCnt = 3;
        uint start_idx = 0;
        // get number of string
        std::string h_num_strs = this->getSubString(start_idx, kStrLenDigitCnt, s);
        const uint num_strs = this->getValFrom3DigitString(h_num_strs);
        // treat header differently
        start_idx = 3;

        std::vector<string> result;
        result.reserve(num_strs);
        // loop through the string
        // first 3 chars 

        // tmp vars
        std::string substr_len_as_str = "";
        uint substr_len = 0;
        std::string substr = "";
        while (result.size() != num_strs && start_idx < s.size()) {
            // get length of next string
            substr_len_as_str = this->getSubString(start_idx, kStrLenDigitCnt, s);
            substr_len = this->getValFrom3DigitString(substr_len_as_str);

            start_idx += kStrLenDigitCnt;

            substr = this->getSubString(start_idx, substr_len, s);

            result.push_back(substr);

            start_idx += substr_len;
        }

        return result;
    }
};
