class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> Q;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==0)
                        Q.push({{i,j},0});
                }

        while(!Q.empty())
        {  
            pair<pair<int,int>,int> pp=Q.front();
            Q.pop();

            int i=pp.first.first;
            int j=pp.first.second;

            int dist=pp.second;
            
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&x<m&&y>=0&&y<n)
                    if(grid[x][y]>0)
                        if(dist+1<grid[x][y])
                        {
                            grid[x][y]=dist+1;
                            Q.push({{x,y},dist+1});
                        }
 

            }
        }
    }
};
