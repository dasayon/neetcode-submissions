/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
public:
    TreeNode* fun(vector<int>& preorder,int &p,int start, int end,map<int,int> M)
    {
        int n=preorder.size();
        if(start>end)
            return NULL;
        int curr = preorder[p++];
        int pos = M[curr];
        TreeNode *tmp = new TreeNode (curr);
        tmp->left=fun(preorder,p,start,pos-1,M);
        tmp->right=fun(preorder,p,pos+1,end,M);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> M;
        for(int i=0;i<inorder.size();i++)
            M[inorder[i]]=i;
        int p=0;
        return fun(preorder,p,0,inorder.size()-1,M);

    }
};
