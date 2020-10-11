class Solution {
    
    void mtable(string str1,string str2,int n,int m,vector<vector<int>> &t)
    {
        int i,j;
        
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<m+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
           
    }
    
    
    string printscs(string str1,string str2,int n,int m,vector<vector<int>> &t)
    {
        string ans="";
        
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans=ans+str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                {
                    ans+=str1[i-1];
                    i--;
                }
                else
                {
                    ans+=str2[j-1];
                    j--;
                }
                    
            }
            
        }
        if(i==0)
        {
            while(j!=0)
            {
                ans+=str2[j-1];
                j--;
            }
        }
        else if(j==0)
        {
            while(i!=0)
            {
                ans+=str1[i-1];
                i--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }    
        
        
    
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        
        mtable(str1,str2,n,m,t);
        
        string ans=printscs(str1,str2,n,m,t);
        return ans;
        
    }
};



 
