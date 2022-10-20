class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        map<int , int> s;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            s[nums[i]] = 1;
            else
            s[nums[i]]++;
        }
        for(auto it=s.begin(); it!=s.end(); it++)
        {
            if(it->second > n/2)
            ans.push_back(it->first);
        }
        return ans[0];
    }
};