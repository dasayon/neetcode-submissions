class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        queue<pair<string,int>> Q;
        Q.push({"0000",0});
        map<string,int> de;

        for(int i=0;i<deadends.size();i++)
            de.insert({deadends[i],1});
        if(de.find(target)!=de.end())
            return -1;
          if(de.find("0000")!=de.end())
            return -1;
        while(!Q.empty())
        {
            auto t=Q.front();
            Q.pop();
            string curr=t.first;
            int turn=t.second;
           
            if(target==curr)
                return turn;
            for(int i=0;i<curr.length();i++)
                {
                    string tmp1=curr;
                    string tmp2=curr;
                    if(tmp1[i]=='0')
                        tmp1[i]='9';
                    else tmp1[i]--;

                    if(de.find(tmp1)==de.end())
                    {
                        Q.push({tmp1,turn+1});
                        de.insert({tmp1,1});
                    }
                

                    if(tmp2[i]=='9')
                        tmp2[i]='0';
                    else tmp2[i]++;

                    if(de.find(tmp2)==de.end())
                    {
                        Q.push({tmp2,turn+1});
                        de.insert({tmp2,1});
                    }
                    
                }
        }

    return -1;
    }
};