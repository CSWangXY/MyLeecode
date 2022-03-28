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
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> t;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
      
};

TreeNode*  NewNode(int v)
{
    TreeNode* node = new TreeNode;
    node->val = v;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}

TreeNode* insert1(vector<int> q, int x)
{
    if(q[x]==-1)
    {
        return NULL;
    }
    else
    {
        TreeNode* root = NewNode(q[x]);
        int lnode = 2*x+1;
        int rnode = 2*x+2;
        if(lnode>q.size()-1)
        {
            root->left = nullptr;
        }
        else root->left =insert1(q,lnode);
        if(rnode>q.size()-1)
        {
            root->right = nullptr;
        }
        else root->right =insert1(q,rnode);
        return root;
    }
    
}

 void inorder1(TreeNode* root, vector<int>& result)
    {
        if(root == nullptr)
       {}
        else
        {
            inorder1(root->left, result);
            result.push_back(root->val);
            inorder1(root->right,result);
        }
    }
    void inorder2(TreeNode* root, vector<int>& faslenum)
    {
        if(root == nullptr)
        return;
        else
        {
            inorder2(root->left, faslenum);
            if(root->val == faslenum[0])
            {
                root->val = faslenum[1];
            }
            else if(root->val == faslenum[1])
            {
                root->val = faslenum[0];
            }
            inorder2(root->right,faslenum);
        }
    }

    int main() 
    {
        
        int a[] = {1,3,-1,-1,2}; 
        vector<int> q(a,a+5);
        TreeNode* root = insert1(q,0);
        vector<int> oldresult;
        inorder1(root , oldresult);
        vector<int>newresult(oldresult);
        sort(newresult.begin(),newresult.end());
        vector<int> faslenum;
        for(int i=0;i<oldresult.size();i++)
        {
            if(oldresult[i] != newresult[i])
            faslenum.push_back(oldresult[i]);
        }
        inorder2(root,faslenum);
        
    }