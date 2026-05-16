class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto a: s){
            if(a=='(' || a=='[' || a=='{'){
                st.push(a);
            }

            if(a==')' || a==']' || a=='}'){
                if(st.empty()) return false;

                if(a==')' && st.top()=='('  || a=='}' && st.top()=='{' || a==']' && st.top()=='['){
                    st.pop();
                }
                else
                    return false;
            }
        }

        if(!st.empty()) return false;
        
        return true;
    }
};