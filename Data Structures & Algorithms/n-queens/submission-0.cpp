class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    void placeQueens(int n, vector<string> &curr,int r)
    {
        if(r==n)
            {
                res.push_back(curr);
                return;
            }
        
        for(int c=0;c<n;c++)
            {
                if(cols.contains(c)||posDiag.contains(r+c)||negDiag.contains(r-c))
                    continue;
                curr[r][c]='Q';
                cols.insert(c);
                posDiag.insert(r+c);
                negDiag.insert(r-c);
                
                placeQueens (n,curr,r+1);

                curr[r][c]='.';
                cols.erase(c);
                posDiag.erase(r+c);
                negDiag.erase(r-c);
            }

    }
    
    vector<vector<string>> solveNQueens(int n) {

        vector<string> curr(n,string(n,'.'));
        placeQueens(n,curr,0);
        return res;   
    }
};
