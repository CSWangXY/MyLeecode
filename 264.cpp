#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
 
 
int main()
    {
        int n = 10;
        vector<int> ans;
        ans.push_back(1);
        int p2=0, p3=0, p5=0;

        for(int i=1; i<n ; i++)
        {
            int tmp = min(ans[p2]*2, min(ans[p3]*3 , ans[p5]*5));
            ans.push_back(tmp);

            if(tmp == ans[p2]*2)
            p2++;
            if(tmp == ans[p3]*3)
            p3++;
            if(tmp == ans[p5]*5)
            p5++;
        }
    cout<<ans[n-1];
    return 0;

    }