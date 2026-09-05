class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string a=strs.front();
        string b=strs.back();

        int minlen = min(a.length(),b.length());
        int i=0;

        while(i<minlen&&a[i]==b[i])
            i++;
        return a.substr(0,i);
    }
};