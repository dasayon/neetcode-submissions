class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> S;

        int a,b;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="+")
            {
                a= S.top();
                S.pop();
                b=S.top();
                S.pop();
                S.push(b);
                S.push(a);
                S.push(a+b);
            }
            else if (operations[i]=="D")
            {
                a=S.top();
                S.pop();
                S.push(a);
                S.push(2*a);
            }
            else if (operations[i]=="C")
            {
                S.pop();
            }
            else
            {
                S.push(stoi(operations[i]));
            }
            
        }
        int ans=0;
        if(S.empty())
            return 0;
        while(!S.empty())
        {
            ans+=S.top();
            S.pop();
        }
        return ans;

    }
};