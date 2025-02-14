// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


class Solution {
    public:
        bool isValid(string s) {
            stack<char>st;
            for(int i=0;i<s.length();i++){
                if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    if(st.empty())return false;
                    char ch = st.top();
                    if(s[i]==')' && ch=='('){
                        st.pop();
                    }
                    else if(s[i]=='}' && ch=='{'){
                        st.pop();
                    }
                    else if(s[i]==']' && ch=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
    
            }
                return st.empty();
        }    
    
    };