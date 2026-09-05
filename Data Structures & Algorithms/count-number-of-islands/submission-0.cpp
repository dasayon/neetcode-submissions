#include<bits/stdc++.h>
class Solution {
public:
    bool visited[105][105];
    bool isValid(vector<vector<char>>& grid,int x,int y)
    {
        int m= grid.size();
        int n=grid[0].size();
        return (x>=0&&x<m&&y>=0&&y<n);
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        if(visited[i][j])
            return;
        visited[i][j]=1;
        int x,y;
        for(int k=0;k<4;k++)
            {
                x=i+dx[k];
                y=j+dy[k];

                if(isValid(grid,x,y)&&grid[x][y]=='1'&&!visited[x][y])
                {
                    dfs(grid,x,y);
                }
            }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       int n=grid[0].size();
       memset(visited,0,sizeof(visited));
       int cnt=0;
       for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1'&&!visited[i][j])
                {
                    dfs(grid,i,j);
                    cnt++;
                }
        return cnt;

    }
};
