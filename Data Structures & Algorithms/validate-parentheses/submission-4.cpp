class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                S.push(s[i]);
            else if (s[i]==')')
                {
                    if(!S.empty()&&S.top()=='(')
                        {   
                            S.pop();
                            continue;
                        }
                    else 
                        return 0;
                }
            else if (s[i]=='}')
                {
                    if(!S.empty()&&S.top()=='{')
                        {
                            S.pop();
                            continue;
                        }
                    else 
                        return 0;
                }
            else if (s[i]==']')
                {
                    if(!S.empty()&&S.top()=='[')
                        {
                            S.pop();
                            continue;
                        }
                    else 
                        return 0;
                }
        }
        return(S.empty());
    }
};
