#include<iostream>
#include<vector>
using namespace std;



int main() 
    {
        int a[] = {1, 1, 2, 2, 2, 3, 3, 3};
        vector<int> nums(a , a+8);
        int n = nums.size();
        if(n <= 2)
        return n;
        int fast = 2;
        int slow = 2;
        while(fast < n)
        {
            if(nums[fast] != nums[fast-2])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        cout<<slow;
    }
