class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> M;
        string tmp,curr;
        for(int i=0;i<strs.size();i++)
        {
           tmp = strs[i];
           sort(tmp.begin(),tmp.end());
           if(M.find(tmp)==M.end())
           {
            vector<int> v;
            v.push_back(i);
            M.insert({tmp,v});
           }
           else
           {
            M[tmp].push_back(i);
           }
        }
        map<string,vector<int>>::iterator it;
        
        
        vector<vector<string>> res;
        for(it = M.begin();it!=M.end();it++)
        {
            vector<string> s; 
            vector<int> v;
            v= it->second;
            for(int i=0;i<v.size();i++)
            {
                s.push_back(strs[v[i]]);
            }
            res.push_back(s);
        }

        return res;
    }
};
