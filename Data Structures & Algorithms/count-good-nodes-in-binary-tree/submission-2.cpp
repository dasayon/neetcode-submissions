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
    int fun(TreeNode* root, int max_so_far)
    {
        if(!root)
            return 0;
        if(root->val>=max_so_far)
            {
                return 1+fun(root->left,root->val)+fun(root->right,root->val);
            }
        else
            return fun(root->left,max_so_far)+fun(root->right,max_so_far);
    }
    int goodNodes(TreeNode* root) {
        return fun(root,INT_MIN);
    }
};
