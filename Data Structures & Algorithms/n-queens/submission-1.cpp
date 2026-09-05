class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    void placeQueens(int n, int r, vector<string> &curr, vector<vector<string>> &res,
    unordered_set<int> &cols,unordered_set<int> &posDiag, unordered_set<int> &negDiag)
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
                
                placeQueens (n,r+1,curr,res,cols,posDiag,negDiag);

                curr[r][c]='.';
                cols.erase(c);
                posDiag.erase(r+c);
                negDiag.erase(r-c);
            }

    }
    
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        
        vector<string> curr(n,string(n,'.'));
        placeQueens(n,0,curr,res,cols,posDiag,negDiag);
        return res;   
    }
};
