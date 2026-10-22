class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                if(tokens[i]=="+"){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(b+a);
                }
                if(tokens[i]=="-"){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(a-b);
                }
                if(tokens[i]=="*"){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(b*a);
                }
                if(tokens[i]=="/"){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(a/b);
                }
            }
            
        }
        return st.top();
    }
};
