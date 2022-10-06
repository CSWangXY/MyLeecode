#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
 
 bool cmp_value( pair<char, int> left, pair<char,int> right)
    {
        return left.second < right.second;
    }

 int main() 
    {
        string s = "abbaccaddaeea";
        string target = "aaaaa";
         map<char,int> k ,t;
        vector<int> ans;
        for(int i=0;i<target.size();i++)
            k[target[i]] = 0;
        for(int i=0; i<target.size();i++)
            k[target[i]]++;
        for(int i=0;i<s.size();i++)
        {
            t[s[i]] = 0;
        }
        for(int i=0;i<s.size();i++)
            t[s[i]]++;
        map<char, int>::iterator it;
        for (it = k.begin(); it != k.end(); it++) 
        {
        char x = it->first;
        if(t[x] == 0)
            return 0;
            else
            {
                int xx = it->second;
                int yy = t[x];
                ans.push_back(yy/xx);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0];
        
    }
    
    