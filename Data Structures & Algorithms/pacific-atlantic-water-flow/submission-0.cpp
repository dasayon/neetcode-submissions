class Solution {
public:
    bool isValid(vector<vector<int>>& heights, int r, int c)
    {
        int m=heights.size();
        int n=heights[0].size();
        return (r>=0&&r<m&&c>=0&&c<n);
    }
    void dfs(vector<vector<int>>& heights, int r, int c,int &left,int &right)
    {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        int m=heights.size();
        int n=heights[0].size();

        if(r==m-1||c==n-1)
            right=1;
        if(r==0||c==0)
            left=1;
        if(right&&left)
            return;
        int h=heights[r][c];
        if(heights[r][c]==INT_MAX)
            return;
        heights[r][c]=INT_MAX;
        for(int k=0;k<4;k++)
        {
            int x=r+dx[k];
            int y=c+dy[k];

            if(isValid(heights,x,y)&&heights[x][y]<=h)
                {
                    dfs(heights,x,y,left,right);
                }

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> ans;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    int left=0;
                    int right=0;
                    vector<vector<int>> tmp=heights;
                    dfs(tmp,i,j,left,right);
                    vector<int> a;
                        if(left&&right)
                            {
                            a.push_back(i);
                            a.push_back(j);
                            ans.push_back(a);
                            }

                }

        return ans;


    }
};
