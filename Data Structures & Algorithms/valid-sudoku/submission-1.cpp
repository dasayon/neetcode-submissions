#include<bits/stdc++.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int arr[10],t;

        for(int i=0;i<9;i++)
        {
            memset(arr,0,sizeof(arr));
            for(int j=0;j<9;j++)
                {
                    if(board[i][j]=='.')
                        continue;
                    
                    if(arr[board[i][j]-'0']==1)
                        return false;
                    else
                        arr[board[i][j]-'0']=1;
                }
        }
        for(int j=0;j<9;j++)
        {
            memset(arr,0,sizeof(arr));
            for(int i=0;i<9;i++)
                {
                    if(board[i][j]=='.')
                        continue;
                  
                    if(arr[board[i][j]-'0']==1)
                        return false;
                    else
                        arr[board[i][j]-'0']=1;
                }
        }
        for(int k=0;k<3;k++)
           for(int m=0;m<3;m++)
           {
            memset(arr,0,sizeof(arr));
            for(int i=3*k;i<3*k+3;i++)
                for(int j=3*m;j<3*m+3;j++)
                {
                    if(board[i][j]=='.')
                        continue;
                   
                    if(arr[board[i][j]-'0']==1)
                        return false;
                    else
                        arr[board[i][j]-'0']=1;
                }
           }
        return true;
    }
};
