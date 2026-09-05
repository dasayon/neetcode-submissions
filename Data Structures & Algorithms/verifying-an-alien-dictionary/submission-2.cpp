class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int pos[26];
        for(int i=0;i<26;i++)
            pos[order[i]-'a']=i;

        for(int i=0;i<words.size()-1;i++)
            {
                string a=words[i];
                string b=words[i+1];

                int m=a.length();
                int n=b.length();
                
                for(int j=0;j<=min(m,n);j++)
                {
                    if(j==min(m,n))
                        {
                            if(n<m)
                                return 0;
                            break;
                        }
                    if(a[j]!=b[j])
                    {
                        if(pos[a[j]-'a']>pos[b[j]-'a'])
                            return 0;
                        break;
                    }
                    
                }

            }
        return 1;
    }
};