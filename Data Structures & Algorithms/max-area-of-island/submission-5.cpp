#include<bits/stdc++.h>
class Solution {
public:
    bool visited[55][55];
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        return i>=0&&i<m&&j>=0&&j<n;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        if(visited[i][j])
            return 0;
        visited[i][j]=1;
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(isValid(grid,x,y)&&!visited[x][y]&&grid[x][y])
                ans+= dfs(grid,x,y);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(visited,0,sizeof(visited));
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]&&!visited[i][j])
                {
                    ans = max(ans,dfs(grid,i,j));
                }
        return ans;
    }
};
