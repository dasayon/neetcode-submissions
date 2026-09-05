
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> strsort;

        for (int i=0;i<strs.size();i++)
            {
                string t = strs[i];
                sort(t.begin(),t.end());
                strsort.push_back(make_pair(t,i));
            }

        sort(strsort.begin(),strsort.end());
        string a=strsort[0].first;
        vector<string> tmp;
        tmp.push_back(strs[strsort[0].second]);
        vector<vector<string>> res;
        for(int i=1;i<strsort.size();i++)
        {
            //cout<<strsort[i].first<<" "<<strsort[i].second<<endl;
            if(a.compare(strsort[i].first))
                {
                    res.push_back(tmp);
                    tmp.clear();
                    a=strsort[i].first;
                    tmp.push_back(strs[strsort[i].second]);
                }
            else
                tmp.push_back(strs[strsort[i].second]);
        }
        res.push_back(tmp);
        return res;
    }
};
