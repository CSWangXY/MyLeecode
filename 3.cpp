class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       /* int max = 0;
        if(s.size()==0)
        return 0;
        if(s.size()==1)
        return 1;
        //cout<<s.size();
        for(int i = 0;i<s.size();i++)
        {
            unordered_set<char>  k;
            for(int j=i;j<s.size();j++)
            {
                if(k.find(s[j])==k.end())
                {
                    k.insert(s[j]);
                    if(j-i+1 >max)
                    max = j-i+1;
                }
                else
                {
                    if(j-i>max)
                    {
                        max = j-i;
                    }
                    break;
                }
            }
        }
        return max;*/

        int ans = 0;
        int rk = 0;
        unordered_set<char> k;
        for(int i=0;i<s.size();i++)
        {
            if(i!=0)
            k.erase(s[i-1]);
            while(rk<s.size()&&k.find(s[rk])== k.end())
            {
                k.insert(s[rk]);
                rk++;
            }
            ans = max(rk-i,ans);
        }
    return ans;
    }
};