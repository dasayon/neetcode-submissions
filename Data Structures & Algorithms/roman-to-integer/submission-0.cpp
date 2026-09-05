class Solution {
public:
    int romanToInt(string s) {
        map<char,int> M={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;

        for(int i=0;i<s.length();i++)
            if(i+1<s.length()&&M[s[i+1]]>M[s[i]])
                    ans-=M[s[i]];
                else
                    ans+=M[s[i]];
        return ans;
    }
};