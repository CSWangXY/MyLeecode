#include<iostream>
#include<vector>
using namespace std;

int main()
    {
        vector<int> nums;//调试时需要赋值
        int val;        //调试时需要赋值
        int n =nums.size();
        int slow = 0;
        int fast = 0;
        if(n==0)
        return n;
        while(fast<n)
        {
            if(nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }