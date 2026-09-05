class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0,m=matrix.size()-1,n=matrix[0].size()-1;
        vector<int> res;
        while(i<=m&&j<=n)
        {
            for(int k=j;k<=n;k++)
                res.push_back(matrix[i][k]);
            i++;
            for(int k=i;k<=m;k++)
                res.push_back(matrix[k][n]);
            n--;
            if(!(i<=m&&j<=n))
                break;
            for(int k=n;k>=j;k--)
                res.push_back(matrix[m][k]);  
            m--;
            for(int k=m;k>=i;k--)
                res.push_back(matrix[k][j]);  
            j++;
        }
        return res;
    }
};
