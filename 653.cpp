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
    bool findTarget(TreeNode* root, int k) 
    {
        unordered_set<int> HashTable;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int ss=q.size();
            for(int i=0;i<ss;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(HashTable.count(k-curr->val)>0)
                {
                    return true;
                }
                else
                {
                HashTable.insert(curr->val);
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
                }
            }
        }
        
        
        return false;
    }
};