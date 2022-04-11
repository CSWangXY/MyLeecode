#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int a[] = {-1,0,1,2,-1,-4};
    vector<int> nums(a,a+6);
    int n = nums.size();
    vector<vector<int>> result;
    vector<int> tmp;
    sort(nums.begin(),nums.end());
    
    for(int i = 0;i<n-2;i++)
    {
        int k = n-1;
        if(nums[i]>0)
        break;
        if(i==0||nums[i]!=nums[i-1])
        {
            for(int j = i+1;j<n-1;j++)
            {
                if(nums[i]+nums[j]>0)
                break;
                if(j==i+1||nums[j]!=nums[j-1])
                {
                    for(;k>j;k--)
                    {
                        if(nums[i]+nums[j]+nums[k]==0)
                        {
                            tmp.push_back(nums[i]);
                            tmp.push_back(nums[j]);
                            tmp.push_back(nums[k]);
                            result.push_back(tmp);
                            tmp.resize(0);
                            break;
                        }
                        else if(nums[i]+nums[j]+nums[k]<0)
                        break;
                    }
                }
            }
        }
    
    }
}