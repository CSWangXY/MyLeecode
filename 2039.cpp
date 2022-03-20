//广度优先搜索
#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
 
int b[] = {0,2,1};
vector<vector<int>> edges(2);
vector<int> patience(b,b+3);



int main()
{
        edges[0].push_back(0);
        edges[0].push_back(1);
        edges[1].push_back(1);
        edges[1].push_back(2);
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n,false);
        for(int i = 0;i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }    
        queue<int> qu;
        qu.push(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while(!qu.empty())
        {
            cout<<1;
            int ss=qu.size();
            for(int i=0;i<ss;i++)
            {
                int curr = qu.front();
                qu.pop();
                for(int j=0;j<adj[curr].size();j++)
                {
                    int v = adj[curr][j];
                    if(visit[v] ==true)
                    continue;
                    qu.push(v);
                    int time = patience[v]*((2*dist-1)/patience[v])+2*dist+1;
                    ans = max(ans,time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        cout<<ans;
}