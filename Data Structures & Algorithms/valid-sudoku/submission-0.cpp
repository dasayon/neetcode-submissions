#include<bits/stdc++.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool hash[10];
        int idx;
        for(int k=0;k<3;k++)
        {
            for(int m=0;m<3;m++)
            {
                memset(hash,0,sizeof(hash));
                for(int i=3*k;i<3*k+3;i++)
                    for(int j=3*m;j<3*m+3;j++)
                    {
                        if(board[i][j]>=49&&board[i][j]<=57)
                        {
                            idx = board[i][j]-'0';
                            if(hash[idx]==1)
                                return false;
                            hash[idx]=1;
                        }   
                       
                    }
                
            }
        }
        for(int i=0;i<9;i++)
        {
            memset(hash,0,sizeof(hash));
            for(int j=0;j<9;j++)
                {
                    
                    if(board[i][j]>=49&&board[i][j]<=57)
                    {
                        idx = board[i][j]-'0';
                        if(hash[idx]==1)
                            return false;
                        hash[idx]=1;
                    }      
                }
        }
        for(int j=0;j<9;j++)
        {
            memset(hash,0,sizeof(hash));
            for(int i=0;i<9;i++)
            {
               
                if(board[i][j]>=49&&board[i][j]<=57)
                        {
                            idx = board[i][j]-'0';
                            if(hash[idx]==1)
                                return false;
                            hash[idx]=1;
                        }     
            }
        }
        return true;
    }
};
