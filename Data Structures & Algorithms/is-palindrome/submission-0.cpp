class Solution {
public:

    // bool isAlphaumeric(const char& val){
    //     const int val_ascii = (int)(std::string{val}.tolower());

    //     // ascii value of a 
    //     // ascii value of z
    //     const int a_ascii = (int)'a';
        
    //     int _ascii_diff = val_ascii - a_ascii;

    //     bool is_valid_alphabet = 0 <= _ascii_diff && _ascii_diff <= 25;

    //     const int num_1_scii = (int)'1';

    //     _ascii_diff = val_ascii - num_1_scii;

    //     bool is_valid_num = 0 <= _ascii_diff && _ascii_diff <= 9;

    //     return is_valid_alphabet || is_valid_num;
    // }

    bool isAlphaumeric(const char& val){
        bool is_upper = (val >= 'A' && val <= 'Z');
        bool is_lower = (val >= 'a' && val <= 'z');
        bool is_digit = (val >= '0' && val <= '9');
        return is_upper || is_lower || is_digit;
    }

    char toLower(char val){
        if (val >= 'A' && val <= 'Z'){
            val = val - ((int)'A' - (int)'a');
        }

        return val;
    }

    bool areCharsEqual(const char& left, const char& right) {
        // char does not support lower() attr, need to fix this

        return toLower(left) == toLower(right);
    }

    bool isPalindrome(string s) {
        /*
        Check to the left and right about the center 
        center raises ambiguity

        Go from either side of the array with left and right ptrs
        until left and right cross each other

        value at left == value at right

        make sure that I have not left out any character
        but given the instance at which left would cross right that
        is an indicator that we have spanned the length of the arrart

        how to handle spaces and special character
        if char is not alphanumeric then skip checking and increment ptrs

        edge cases:
        ":" ?
        "1"

        Algorithm
        loop until (l <r)
        - get left char
        - get right char
        - is left_char valid
        - is right_char valid
        - if (left and right are valid)
        - - check for eqaulity 
        - - if not equal return false
        - - increment left and right ptrs
        - else if (left is valid and right is not valid)
        - - only increment right
        - else if (left is not valid and right is valid)
        - - only increment left
        - else (both are not valid)
        - - increment left and right
        */

        int l = 0;
        int r = s.size() -1 ;
        
        while (l < r){
            char left_char = s[l];
            char right_char = s[r];

            bool left_valid = isAlphaumeric(left_char);
            bool right_valid = isAlphaumeric(right_char);

            // std::cout << "l_ptr, r_ptr: " << l << ", " << r << std::endl;
            if (left_valid && right_valid){
                bool are_equal = areCharsEqual(left_char, right_char);
                // std::cout << "(left_char, right_char): " << left_char << ", " << right_char << std::endl;
                if(!are_equal) return false;
                l++;
                r--;
            } else if (left_valid && !right_valid){
                r--;
            } else if (!left_valid && right_valid){
                l++;
            } else {
                l++;
                r--;
            }
        }

        // this should take care of "1"
        return true;
    }
};
