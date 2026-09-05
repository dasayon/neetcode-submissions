class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j)
    {
        int m=board.size();
        int n=board[0].size();
        return i>=0&&i<m&&j>=0&&j<n;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &visited,string word,int i,int j,int idx)
    {
        visited[i][j] =1;
        if(idx==word.size()-1)
            return true;

        int dx[]={-1,-0,1,0};
        int dy[]={0,1,0,-1};

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(isValid(board,x,y)&&!visited[x][y]&&board[x][y]==word[idx+1])
                if(dfs(board,visited,word,x,y,idx+1))
                    return true;
        }
        visited[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) 
    {   
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0])
                    if(!visited[i][j]&&dfs(board,visited,word,i,j,0))
                        return true;
        return false;
    }
};
