#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
        string s = "ABAA";
        int k = 0;
        vector<int> nums(26);
        int len = s.size();
        int maxnum = 0;
        int ans = 0;
        int l=0;
        int r = 0;
        while(r<len)
        {
            
            nums[s[r]-'A']++;
            maxnum = max(maxnum , nums[s[r]-'A']);
            while(r-l+1-maxnum > k && l<r)
            {
                l++;
                nums[s[l]-'A']--;
            }
            ans = max(ans , r-l+1); 
            r++; 
        }
        cout<< ans;
}