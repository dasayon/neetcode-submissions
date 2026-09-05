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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue <pair<TreeNode*,int>> Q;
        Q.push(make_pair(root,0));
        int currlevel=0;
        int prev = root->val;
        while(!Q.empty())
        {
            pair<TreeNode*,int> p = Q.front();
            Q.pop();
            if(p.second>currlevel)
            {
                res.push_back(prev);
                currlevel=p.second;
            }
            TreeNode* tmp = p.first;
            prev = p.first->val;
            if(tmp->left)
                Q.push(make_pair(tmp->left,currlevel+1));
            if(tmp->right)
                Q.push(make_pair(tmp->right,currlevel+1));   
            
        }
        res.push_back(prev);
        return res;
    }
};
