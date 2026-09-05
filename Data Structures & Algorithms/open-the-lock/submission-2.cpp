class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> Q;

        //int ans=INT_MAX;
        unordered_set<string> visited;
        for(int i=0;i<deadends.size();i++)
            visited.insert(deadends[i]);
        if(!visited.contains("0000"))
        {
            visited.insert("0000");
            Q.push({"0000",0});
        }
        
        while(!Q.empty())
        {
            pair<string,int> p=Q.front();
            Q.pop();
            string s=p.first;
            int turn=p.second;
            //cout<<turn<<" "<<s<<endl;
            if(s==target)
                return turn;
            for(int i=0;i<4;i++)
            {
                string s1=s;
                string s2=s;
                if(s1[i]=='0') // s1 is decrement
                    s1[i]='9';
                else 
                    s1[i]--;
                if(s2[i]=='9')
                    s2[i]='0';
                else
                    s2[i]++;

                if(!visited.contains(s1))
                    {
                        Q.push({s1,turn+1});
                        visited.insert(s1);
                    } 
                if(!visited.contains(s2))
                    {
                        Q.push({s2,turn+1});
                        visited.insert(s2);
                    } 
                
            }

        }
        return -1;
    }
};