#include <iostream>
#include <vector>
using namespace std;

vector<int> t;
struct Node 
{
    int val;
    Node *left;
    Node *right;
      
};

Node*  NewNode(int v)
{
    Node* node = new Node;
    node->val = v;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}

Node* insert1(vector<int> q, int x)
{
    if(q[x]==-1)
    {
        return NULL;
    }
    else
    {
        Node* root = NewNode(q[x]);
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


void inorderTraversal(Node *root)
{
    if(root ==nullptr)
        return ;
        else 
        {
            inorderTraversal(root->left);
            t.push_back(root->val);
            inorderTraversal(root->right);
        }
}

int main()
    {
        int a[]={1,2,3,4,5,6};
        vector<int> q(a,a+6);

        Node *root =insert1(q,0);
        inorderTraversal(root);
        for(int i = 0;i<t.size();i++)
        cout<<t[i];
    }
    