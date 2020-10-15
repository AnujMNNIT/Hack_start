class Solution {
public:
    int findMax(vector<int>& prices,vector<int>& dp,int curr,int n)
    {
        if(curr>=n)
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        int maxVal=0;
        for(int i=curr+1;i<n;i++)
        {
            if(prices[curr]<prices[i])
                maxVal=max(maxVal,prices[i]-prices[curr]+findMax(prices,dp,i+2,n));
        }
        maxVal=max(maxVal,findMax(prices,dp,curr+1,n));
        return dp[curr]=maxVal;
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,-1);
        return findMax(prices,dp,0,n);
        
    }
};
