class Solution {
public:
    const unordered_map<char, char> bracket_pairs {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };

    const set<char> closing_brackets {
        ')',
        '}',
        ']'
    };

    vector<char> brackets;

    bool getExpectedClosingBracket(char& closing_bracket) {
        // last open bracket
        if (brackets.size() == 0) return false;
        
        char last_open_bracket = brackets[brackets.size() -1];

        closing_bracket = bracket_pairs.at(last_open_bracket);

        return true;
    }

    bool isValid(string s) {

        // trackk the 

        /*
            vector<char>

            // append the open bracket to vector
            // if we encoutnter a closed bracket 
            // we need to check 
            // if it matches with the last opened bracket 
            // remove the last openeded [-1] bracket from vector
            // else false
            
            // once we finish parsing the array
            // return true if vector is empty else false

            vector<chars> brackets "[{("

            // we would expect to see a closed bracket ")"

            edge cases:

            "h{ap[p]y}jack"

            "{[()]}"

            "[()]()"

            "[]{}])"
        */
        


        for (const auto& val: s) {
            if (bracket_pairs.find(val) != bracket_pairs.end()){
                brackets.push_back(val);
            } else {
                // expected bracket
                char expected_closing_bracket;

                if (closing_brackets.contains(val))
                {
                    if (getExpectedClosingBracket(expected_closing_bracket) && expected_closing_bracket == val){
                        // remove last open vector
                        brackets.pop_back();
                    } else {
                        return false;
                    }
                } 
            }
        }  

        if (brackets.size() == 0)
            return true;

        return false;
    }
};
