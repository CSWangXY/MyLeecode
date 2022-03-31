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
private: unordered_map<int,int> index;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
         for(int i=0;i<inorder.size();i++)
        {
            index[inorder[i]] = i;
        }
        return build(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }


     TreeNode* build(vector<int>& postorder, vector<int>& inorder,int postleft, int postright, int inleft, int inright)
     {
         if(postleft > postright)
         return nullptr;
         int postorder_root = postorder[postright];
         int inindex = index[postorder_root];
         TreeNode* root = new TreeNode(postorder_root);
         int leftsize = inindex - inleft;
         root->left = build(postorder,inorder,postleft,postleft+leftsize-1,inleft,inindex-1);
         root->right = build(postorder,inorder,postleft+leftsize,postright-1,inindex+1,inright);
        return root;
     }
};




