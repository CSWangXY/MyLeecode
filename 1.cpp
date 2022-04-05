class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> HashTables;
        for(int i=0;i<nums.size();i++)
        {
            int x1 = nums[i];
            int x2 = target - x1;
            if(HashTables.find(x2)!=HashTables.end())
            return {HashTables.find(x2)->second,i};
            else HashTables[nums[i]] = i;
        }
        return {};
    }
    
};