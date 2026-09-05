class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        int m=grid.size();
        int n=grid[0].size();
        int perimeter=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int neighbours=0;
                    for(int k=0;k<4;k++)
                        {
                            int x=i+dx[k];
                            int y=j+dy[k];
                            if(x>=0&&x<m&&y>=0&&y<n)
                            neighbours+=(grid[x][y]==1);
                        }
                    perimeter+=4-neighbours;
                }
            }
        return perimeter;
    }
};