class Solution {
public:
    vector<vector<int>>  ans;
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> path;
        vector<bool> used(n+4,false);
        dfs(n, k, 0, path, used, 1);
        return ans;
    }

    void dfs(int n ,int k, int depth, vector<int> &path, vector<bool> &used, int tag)
    {
        if(depth == k)
        {
            ans.push_back(path);
            return;
        }
        for(int i=tag; i<=n; i++)
        {
            if(used[i] == false)
            {
                path.push_back(i);
                used[i] = true;
                dfs(n, k, depth+1, path, used, i+1);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
