class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char val:s){
            if(val=='(' || val=='[' || val=='{'){
                st.push(val);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(val==')' && st.top()!= '('){
                    return false;
                }
                if(val==']' && st.top()!= '['){
                    return false;
                }
                if(val=='}' && st.top()!= '{'){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
