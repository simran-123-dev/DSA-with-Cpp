class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                st.pop();
            }
            else if (ops[i] == "D") {
                st.push(st.top() * 2);
            }
            else if (ops[i] == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);              
                st.push(top1 + top2);
            }
            else {
                st.push(stoi(ops[i]));      
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
