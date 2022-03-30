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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == nullptr)
        return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int l=q.size();
            vector<int> tmp;
            for(int i=0;i<l;i++)
            {
                TreeNode* curr = q.front();
                tmp.push_back(curr->val);
                q.pop();
                if(curr->left !=nullptr)
                q.push(curr->left);
                if(curr->right != nullptr)
                q.push(curr->right);
            }
            if(level%2==0)
            result.push_back(tmp);
            else
            {
                reverse(tmp.begin(),tmp.end());
                result.push_back(tmp);
            }
            level++;
        }
        return result;
    }
};