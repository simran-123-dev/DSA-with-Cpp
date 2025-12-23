class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int temp2=st.top();
                st.pop();
                int temp1=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(temp1+temp2);
                }
                else if(tokens[i]=="-"){
                    st.push(temp1-temp2);
                }
                else if(tokens[i]=="*"){
                    st.push(temp1*temp2);
                }
                else {
                    st.push(temp1/temp2);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

//complexity sc=tc=O(n)
