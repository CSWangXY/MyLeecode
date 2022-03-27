class Solution {
public:
    int trailingZeroes(int n) 
    {
        int ans1 = 0;
        int ans2 = 0;
        for(int i=5;i<=n;i=i+5)
        {
            for(int x=i;x%5==0;x = x/5)
            {
                ans1++;
            }
        }
         for(int i=2;i<=n;i=i+2)
        {
            for(int x=i;x%2==0;x = x/2)
            {
                ans2++;
            }
        }
        return min(ans1,ans2);
    }
};