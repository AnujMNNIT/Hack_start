class Solution {
public:
    int dp[103][10005];
    int solve(int e,int f)
    {
        if(f<=1||e==1)
            return f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int res=f,l=1,h=f;
        while(l<h)
        {
            int m=(l+h)/2;
            int lo,hi;
            if(dp[e-1][m-1]!=-1)
                lo=dp[e-1][m-1];
            else
                lo=solve(e-1,m-1);
            if(dp[e][f-m]!=-1)
                hi=dp[e][f-m];
            else
                hi=solve(e,f-m);
            res=min(res,1+max(hi,lo));
            if(lo==hi)
                break;
            else if(lo<hi)
                l=m+1;
            else 
                h=m;
        }
        return dp[e][f]=res;
    }
    int superEggDrop(int K, int N) {
        memset(dp,-1,sizeof(dp));
        if(K==0)
            return 1;
        if(N==0)
            return 1;
        return solve(K,N);
    }
};
