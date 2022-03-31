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
private:
    unordered_map<int,int> index;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int preleft, int preright, int inleft, int inright)
    {
        if(preleft>preright)
        return nullptr;

        int preorder_root = preorder[preleft];
        int inindex = index[preorder_root];
        TreeNode* root = new TreeNode(preorder_root);
        int leftsize = inindex - inleft;
        root->left = build(preorder,inorder,preleft+1,preleft+leftsize,inleft,inindex-1);
        root->right = build(preorder,inorder,preleft+leftsize+1,preright,inindex+1,inright);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i=0;i<inorder.size();i++)
        {
            index[inorder[i]] = i;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};