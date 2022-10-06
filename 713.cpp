#include<iostream>
#include<vector>
using namespace std; 
 
  int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int l = 0 ;
        int r = 0 ;
        if(nums.size()==0 )
        return 0;
        int sum = 1;
        int  ans =0;
        while(r<n)
        {
            sum *= nums[r];
            r++;
           
                
           
            while(sum >= k && l <= r)
            {
                sum /= nums[l];
                l++;
            }
            ans = ans + r-l;
        }
        return ans;
}
int main()
{
    
    int a[] = {10,5,2,6};
    vector<int> nums(a,a+4);
    int  k = 100;
    int ans = numSubarrayProductLessThanK(nums,  k) ;
    cout<<ans;
    
}