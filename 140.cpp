#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<int, vector<string>> ans;
unordered_set<string> wordSet;




void backtrack(const string& s, int index) 
{
    if (ans.count(index)==0) 
    {
        if (index == s.size()) 
        {
            ans[index] = {""};
            return;
        }
        ans[index] = {};
        for (int i = index + 1; i <= s.size(); ++i) 
        {
            string word = s.substr(index, i - index);
            if (wordSet.count(word)) 
            {
                backtrack(s, i);
                for (const string& succ: ans[i]) 
                {
                    ans[index].push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) 
{
    for(int i=0; i<wordDict.size(); i++)
    wordSet.insert(wordDict[i]);
    backtrack(s, 0);
    return ans[0];
}
int main()
{
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple","pen","applepen", "pine", "pineapple"};
    
    wordBreak(s , wordDict);
    for(int i=0; i<ans[0].size(); i++)
    cout<<ans[0][i]<<endl;
    
}