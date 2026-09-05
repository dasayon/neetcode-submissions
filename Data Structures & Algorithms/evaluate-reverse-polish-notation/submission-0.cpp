#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        int a,b;
        for(int i=0;i<tokens.size();i++)
            {
                if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
                    {
                        a=S.top();
                        S.pop();
                        b=S.top();
                        S.pop();
                        if(tokens[i]=="+")
                        S.push(a+b);
                        else if(tokens[i]=="-")
                        S.push(b-a);
                        else if(tokens[i]=="*")
                        S.push(b*a);
                        else
                        S.push(b/a);

                    }
                    else
                    {
                        S.push(stoi(tokens[i]));
                    }
            }
            if(S.size()>0)
                return S.top();
            
    }
};
