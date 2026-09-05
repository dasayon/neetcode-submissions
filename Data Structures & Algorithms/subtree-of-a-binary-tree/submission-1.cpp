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
    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        if(a==NULL&&b==NULL)
            return 1;
        else if (a!=NULL&&b!=NULL)
        {
            return (a->val==b->val&&isSameTree(a->left,b->left)&&isSameTree(a->right,b->right));
        }
        else return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL||subRoot==NULL)
            return 0;
        if(root->val==subRoot->val)
            return isSameTree(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right, subRoot);
        else
        return isSubtree(root->left,subRoot)||isSubtree(root->right, subRoot);
    }
};
