#include<iostream>
#include<vector>
using namespace std;

int main()
{
int target;
int a[] ={2,3,1,2,4,3};
vector<int> nums(a,a+6);
int ans = INT_MAX;
int r = 0;
int l = 0;
int currsum = 0;
for( ; r<nums.size();r++)
{
    currsum += nums[r];
    while(l<r && currsum -nums[l] >= target)
    {
        currsum -= nums[l];
        l++;
    }
if(currsum >=target && r-l+1 < ans)
    ans = r-l+1;

}

if(ans == INT_MAX)
cout<< 0;
else
cout<<ans;
}
