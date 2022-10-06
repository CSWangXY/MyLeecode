#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx)
{
        if(idx == candidates.size())
        return;
        if(target == 0)
        {
            ans.push_back(combine);
            return;
        }
        dfs(candidates, target, ans, combine, idx+1);
        if(target - candidates[idx] >=0)
        {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
}

int main()
    {
        int a[] = {2,3,6,7};
        vector<int> candidates(a,a+4);
        int target = 7;
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
            cout<<endl;
        }
    }
