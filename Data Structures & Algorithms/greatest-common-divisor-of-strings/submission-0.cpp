class Solution {
public:
    int gcd(int a,int b)
    {
        int res=min(a,b);
        while(res>0)
        {
            if(a%res==0&&b%res==0)
                break;
            res--;
        }
        return res;
    }
    string gcdOfStrings(string str1, string str2) {
        
        int j=gcd(str1.length(),str2.length());
        string a=str1+str2;
        string b=str2+str1;
        if(a.compare(b)==0)    
            return str1.substr(0,j);
        else 
            return "";
    }
};