class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i]) 
                {
                    if(len[i]<len[j]+1)
                    {
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    }
                    else if(len[i]==len[j]+1)
                    {
                        count[i] += count[j];
                    }
                }
            }
        }
        int ans=0;
        unordered_map<int, int> lis;
        for(int i=0; i<n; i++) 
        {
            lis[len[i]] += count[i];
            ans = max(ans, len[i]);
        }
        //for(int i=0; i<n; i++) if(dp[i]==l-1) ans++;
        return lis[ans];
        
    }
};
