class Solution {
public:
    bool isCycle(vector<vector<int>>& adj,vector<bool>& visited, int u, int parent)
    {
        visited[u]=true;

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!visited[v])
                {
                    if(isCycle(adj,visited,v,u))
                    return 1;
                }
            else if (v!=parent)
                return 1;

        }
        return 0;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        if(edges.size() != n-1) return false;
        for(int i=0;i<edges.size();i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        vector<bool> visited(n,0);
        if(isCycle(adj,visited,0,-1))
            return false;
        for(int i=0;i<n;i++)
            if(!visited[i])
                return false;
    return true;
    }
};
