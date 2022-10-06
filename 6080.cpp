#include<iostream>
#include<vector>
using namespace std; 
 
 int main()
    {
        int a[] = {5,3,4,4,7,3,6,11,8,5,11};
        vector<int> nums(a,a+11);
        vector<int> last(nums);
        vector<int> curr;
        while(true)
        {
            curr.clear();
            curr.push_back(nums[0]);
            int n = last.size();
            
            for(int i=1; i<last.size(); i++)
            {
                if(last[i-1] > last[i])
                {}
                else
                curr.push_back(last[i]);
            }
            if(n == curr.size())
            return n;
            else
            {
                last = curr;
            }
        }    
    }
    