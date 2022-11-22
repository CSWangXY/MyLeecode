//深度优先解决方法
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    map<Node *, Node *> c;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        if (c.find(node) != c.end())
            return c[node];

        Node *clonenode = new Node(node->val);
        c[node] = clonenode;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            clonenode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return clonenode;
    }
};
