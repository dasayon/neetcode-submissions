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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> Q;
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        Q.push(make_pair(root,0));
        vector<int> tmp;
        int currlevel=0;
        while(!Q.empty())
        {   
            pair<TreeNode*,int> p = Q.front();
            Q.pop();
            TreeNode *curr = p.first;
            int level = p.second;
            
            if(level>currlevel)
            {
                res.push_back(tmp);
                tmp.clear();
                currlevel=level;
            }
            tmp.push_back(curr->val);
            if(curr->left)
                Q.push(make_pair(curr->left,level+1));
            if(curr->right)
                Q.push(make_pair(curr->right, level+1));
        }
        res.push_back(tmp);
        return res;
    }
};
