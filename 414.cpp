#include <iostream>
#include <vector>
using namespace std;
     
     
     int main()
     {
        vector<int> nums;
        nums = {1, -2147483648, 2};
        int len = nums.size();
        long long first = LONG_MIN;
        long long  second = LONG_MIN;
        long long  third = LONG_MIN;
        bool flag = false;
        for(int i=0;i<len;i++)
        {
            if(nums[i] >first)
            {
                third = second;
                second =first;
                first = nums[i];
            }
            else if(nums[i] < first && nums[i] >second)
            {
                third = second;
                second = nums[i];
            }
            else if(nums[i]<second && nums[i] >=third)
            {
                third = nums[i];
                flag = true;
            }
        }
        if(third > INT_MIN || (third == INT_MIN && flag ==true))
        cout<< third;
        else 
        cout<< first;
     }