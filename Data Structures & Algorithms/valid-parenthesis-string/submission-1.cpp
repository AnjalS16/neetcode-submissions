class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> ass;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(') left.push(i);
            if(s[i]=='*') ass.push(i);
            if(s[i]==')'){
                if(!left.empty()) left.pop();
                else if(!ass.empty()) ass.pop();
                else return false;
            }
        }
        while(!left.empty() && !ass.empty()){
            if(left.top() > ass.top()) return false;
            left.pop();
            ass.pop();
        }
        return left.empty();
    }
};
