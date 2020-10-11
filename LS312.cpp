class Solution 
{   
    
    int solve( vector<int>& nums,vector<vector<int>> &dp,int l,int h)
    {
        if(dp[l][h]!=-1)
            return dp[l][h];
        if(l>h)return 0;
        int ans=0,n=nums.size();
        for(int i=l+1;i<h;i++)
        {
                ans=max(ans,solve(nums,dp,l,i)+solve(nums,dp,i,h)+nums[l]*nums[i]*nums[h]);
        }
        return dp[l][h]=ans;
    }
public:
    int maxCoins(vector<int>& v) 
    {
        vector<int> nums;
        nums.push_back(1);
        for(int i=0;i<v.size();i++)
        {
           nums.push_back(v[i]);
        }
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,dp,0,nums.size()-1);
    }
};
