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
        if(root==nullptr)
        return 0;
        else if(root->left!=nullptr && root->right !=nullptr)
        return min(height(root->left),height(root->right))+1;
        else if(root->left==nullptr && root->right ==nullptr )
        return 1;
        else return max(height(root->left),height(root->right))+1;
    }
    int minDepth(TreeNode* root) 
    {
        return height(root);
    }
};