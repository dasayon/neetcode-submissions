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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
            return NULL;
        TreeNode *l=removeLeafNodes(root->left,target);
        TreeNode *r=removeLeafNodes(root->right,target);
        if(l==NULL&&r==NULL&&root->val==target)
            return NULL;
        root->left=l;
        root->right=r;
        return root;
    }
};