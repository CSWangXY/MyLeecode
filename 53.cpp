#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
 
 
 int main() 
    {
        int a[] = {-2,1,-3,4,-1,2,1,-5,4};
        vector<int> nums(a,a+9);
        vector<int> d;
        int ans = nums[0];
        d.push_back(ans);
        for(int i = 1;i<nums.size();i++)
        {
            int tmp = max(d[i-1],d[i-1]+nums[i]);
            if(tmp > ans)
            ans = tmp;
            d.push_back(tmp);
        }
        return ans;
    }