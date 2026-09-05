#include<bits/stdc++.h>
class Solution {
public:
    bool visited[55][55];
    bool isValid(vector<vector<int>>& grid,int x,int y)
    {
        int m=grid.size();
        int n=grid[0].size();

        return (x>=0&&x<m&&y>=0&&y<n);
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        if(visited[i][j])
            return 0;
        visited[i][j] =1;
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(isValid(grid,x,y)&&grid[x][y]==1)
                ans+=dfs(grid,x,y);
        }   
        return ans;   
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1&&!visited[i][j])
                    cnt=max(cnt,dfs(grid,i,j));

        return cnt;
    }
};
