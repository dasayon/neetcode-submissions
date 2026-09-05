class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int x,int y)
    {
        int m=grid.size();
        int n=grid[0].size();

        return (x>=0&&x<m&&y>=0&&y<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        int x,y,ans=0;
        queue<pair<pair<int,int>,int>> Q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    Q.push(make_pair(make_pair(i,j),0));
                
            }
        
        while(!Q.empty())
        {
            pair<pair<int,int>,int> pp = Q.front();
            Q.pop();
            int i=pp.first.first;
            int j=pp.first.second;
            int time =pp.second;
            if(time>ans)
                ans=time;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];

                if(isValid(grid,x,y)&&grid[x][y]==1&&!visited[x][y])
                {
                    Q.push(make_pair(make_pair(x,y),time+1));
                    visited[x][y]=1;
                }
            }
        }
          for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!visited[i][j])
                    return -1;
            }
        return ans;
    }
};
