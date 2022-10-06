#include<iostream>
#include<vector>
using namespace std;


int main()
    {
        vector<int> nums;//调试时记得赋值
        int n = nums.size();
        if(n<=1)
        return n;
        int slow = 1;
        int fast = 1;//快慢双指针去除重复项
        while(fast < n)
        {
            if(nums[fast]!=nums[fast-1])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        //cout<<slow;
        return slow;
    }