#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> used(n , false);
        vector<int> path;
        dfs(nums , used, path, 0);
        return ans;
    }

    void dfs(vector<int>& nums , vector<bool>& used, vector<int> path, int depth)
    {
        if(depth == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(used[i] == false)
            {
                path.push_back(nums[i]);
                used[i] = true;//选择，添加操作
                dfs(nums , used, path, depth+1);
                used[i] = false;//回溯，撤销操作
                path.pop_back();

            }
        }
    }

};