class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();

        return(i>=0&&i<m&&j>=0&&j<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> Q;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==2)
                        {
                            Q.push(make_pair(make_pair(i,j),0));
                            grid[i][j]=0;
                        }
                }
        int ans=0;
        while(!Q.empty())
        {
            auto p= Q.front();
            Q.pop();

            int i=p.first.first;
            int j=p.first.second;
            int t=p.second;
            ans=max(ans,t);
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];

                if(isValid(grid,x,y)&&grid[x][y]==1)
                    {
                        Q.push(make_pair(make_pair(x,y),t+1));
                        grid[x][y]=0;
                    }
            }
        }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]!=0)
                return -1;

    return ans;
    }
};
