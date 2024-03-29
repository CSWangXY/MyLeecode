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
    bool isValidBST(TreeNode* root) 
    {
        
        inorder(root);
        for(int i =1;i<result.size();i++)
        {
            if(result[i] <= result[i-1])
            return false;
        }
        return true;
    }

    void inorder(TreeNode* root)
    {
        if(root ==nullptr)
        return ;
        else
        {
            inorder(root->left);
            result.push_back(root->val);
            inorder(root->right);
        }
    }

private:
    vector<int> result;
};