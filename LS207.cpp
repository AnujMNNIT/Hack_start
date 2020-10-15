class Solution {
public:
    bool dfs(vector<int> adj[],vector<int> &visited,int i)
    {
        if(visited[i]==1)
            return true;
        visited[i]=1;
            for(auto edge : adj[i]){
                if(dfs(adj,visited,edge))
                    return true;
            }
        visited[i] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++)
            adj[pre[i][0]].push_back(pre[i][1]);
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
            if(visited[i]==0)
                if(dfs(adj,visited,i))
                    return false;
        return true;
    }
};
