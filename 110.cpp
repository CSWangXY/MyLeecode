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
    int height(TreeNode* root)
    {
        if(root == nullptr)
        return 0;
        else return max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr)
        return true;
        int l = height(root->left);
        int r = height(root->right);
        int num = abs(l-r);
        return num<=1 && isBalanced(root->right) && isBalanced(root->left);
    }
};