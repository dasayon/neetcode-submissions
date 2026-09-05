class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> S;

        for(int i=0;i<asteroids.size();i++)
        {
            if(S.empty())
                S.push(asteroids[i]);
            else if(asteroids[i]*S.top()>0)
                S.push(asteroids[i]);
            else
            {
                int a=asteroids[i];
                while(!S.empty()&&S.top()>0&&a<0)
                {
                    int b=S.top();
                    S.pop();
                    if(abs(a)==abs(b))
                        {a=0;continue;}
                    else if (abs(b)>abs(a))
                       a=b;
                }
                if(a)
                    S.push(a);
            }
        }
        vector<int> res;
        while(!S.empty())
            {
                res.push_back(S.top());
                S.pop();
            }
        reverse(res.begin(),res.end());
        return res;
    }
};