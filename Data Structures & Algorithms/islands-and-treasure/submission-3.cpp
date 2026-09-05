class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        queue<pair<pair<int,int>,int>> Q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                Q.push(make_pair(make_pair(i,j),0));

        while(!Q.empty())
        {
            auto pp = Q.front();
            Q.pop();
            int i=pp.first.first;
            int j=pp.first.second;
            int d=pp.second;
            for(int k=0;k<4;k++)
            {   
                int x=i+dx[k];
                int y=j+dy[k];

                if(x>=0&&x<m&&y>=0&&y<n)
                    if(grid[x][y]>d+1)
                    {
                        grid[x][y]=d+1;
                        Q.push(make_pair(make_pair(x,y),d+1));
                    }
            }
        }

    }
};
