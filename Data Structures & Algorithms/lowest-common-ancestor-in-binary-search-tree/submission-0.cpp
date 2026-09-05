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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode *left_lca,*right_lca;
        left_lca = lowestCommonAncestor(root->left, p,q);
        right_lca = lowestCommonAncestor(root->right,p,q);

        if(left_lca&&right_lca)
            return root;
        
        return (left_lca)?left_lca:right_lca;
    }
};
