class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int sum=1;
       int carry=0;
       reverse(digits.begin(),digits.end());
       for(int i=0;i<digits.size();i++)
       {
            sum+=digits[i];
            carry=sum/10;
            sum%=10;
            digits[i]=sum;
            sum=carry;
            carry=0;
       } 
       if(sum>0)
            digits.push_back(sum);
       reverse(digits.begin(),digits.end());
       return digits;
    }
};
