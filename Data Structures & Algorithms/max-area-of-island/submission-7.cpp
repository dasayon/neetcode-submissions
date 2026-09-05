class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x,int y)
    {
        int m=grid.size();
        int n=grid[0].size();

        return (x>=0&&x<m&&y>=0&&y<n);
    }

    void dfs(vector<vector<int>>& grid, int i,int j, int &curr)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        grid[i][j]=0;
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(isValid(grid,x,y)&&grid[x][y]==1)
                {   
                    curr++;
                    dfs(grid,x,y,curr);
                }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {   
                    int curr=1;
                    dfs(grid,i,j,curr);
                    ans=max(ans,curr);
                }
            }
        return ans;
    }
};
