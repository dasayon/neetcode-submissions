class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        return (i>=0&&i<m&&j>=0&&j<n);
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        grid[i][j]='0';
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(isValid(grid,x,y)&&grid[x][y]=='1')
                dfs(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                    {
                        dfs(grid,i,j);
                        cnt++;
                    }
            }
        return cnt;
    }
};
