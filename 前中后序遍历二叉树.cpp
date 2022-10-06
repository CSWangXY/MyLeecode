/*遍历结果需要存为全局变量，或在传参数时设置为引用*/

/*
 void inorder(TreeNode* root)或者void inorder(TreeNode* root , vector<int> &path )
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

*/