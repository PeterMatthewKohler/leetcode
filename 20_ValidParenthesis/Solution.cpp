class Solution {
public:
    bool isValid(string s) {
        // Use a stack
        std::stack<char> st;
        for(const auto& c : s) {
            // Open brackets go into stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Closing brackets need to have their opening partner be
            // on top of stack, if not it is invalid
            else {
                if(st.empty()){return false;}
                switch(c) {
                    case ')' : {
                        if(st.top() != '('){return false;}
                        else{st.pop(); break;}
                    }
                    case '}' : {
                        if(st.top() != '{'){return false;}
                        else{st.pop(); break;}
                    }
                    case ']' : {
                        if(st.top() != '['){return false;}
                        else{st.pop(); break;}
                    }
                    default : {return false;} // wrong character somehow should never hit this
                }
            }
        }
        return st.empty();  // Should be no unprocessed brackets
    }
};
