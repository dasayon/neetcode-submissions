class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a= prices[0];
        int ans =0;
        for(int i=0;i<prices.size();i++)
        {
            ans = max(ans,prices[i]-a);
            a= min(a,prices[i]);
        }
        return ans;
    }
};
