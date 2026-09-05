class Solution {
public:
    unordered_set <int> cols;
    unordered_set <int> posDiag;
    unordered_set <int> negDiag;
    
    int placeQueens(int n,int r)
    {
        if(r==n)
            return 1;
        int ans=0;
        for(int c=0;c<n;c++)
        {
            if(cols.contains(c)||posDiag.contains(r+c)||negDiag.contains(r-c))
                continue;
            cols.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            ans+=placeQueens(n,r+1);
            cols.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
        }
        return ans;
    }
    int totalNQueens(int n) {
        return placeQueens(n,0);
    }
};