class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        long long i,j,x,y,ans=0,n=grid.size(),m=grid[0].size(),cnt;
        vector<vector<int>> color(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            cnt=0;
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    color[i][j]=1;
                    x=i;
                    y=j;
                    cnt++;
                }
            }
            if(cnt==1)
            {
                color[x][y]=0;
            }
            else
            {
                ans+=cnt;
            }
        }
        
        for(i=0;i<m;i++)
        {
            cnt=0;
            int cc=0;
            for(j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                {
                    if(color[j][i]==0)
                    {
                        color[j][i]=1;
                        cnt++;
                    }
                    else if(color[j][i]==1)
                        cc++;
                }
            }
            if(cnt>1)
            {
                ans+=cnt;
            }
            else if(cc>0 && cnt==1)
                ans+=cnt;
        }
        return ans;
        
        
    }
};
