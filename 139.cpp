#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <map>
using namespace std;

map<string, bool> m;
bool back_track(string s, unordered_set<string> dic)
{
    // cout<<s<<endl;
    if (m.find(s) != m.end())
        return m[s];
    if (s.size() == 0)
        return true;
    bool res = false;
    for (int i = 1; i <= s.size(); i++)
    {
        string curr = s.substr(0, i);
        if (dic.find(curr) != dic.end())
        {
            cout << curr << endl;
            cout << res;
            curr = s.substr(i, s.size() - i);
            res = back_track(curr, dic) || res;
            cout << res << endl;
        }
    }
    m[s] = res;
    return res;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dic;
    for (int i = 0; i < wordDict.size(); i++)
    {
        dic.insert(wordDict[i]);
    }
    bool a = back_track(s, dic);
    return a;
}

int main()
{
    string s = "abcd";
    vector<string> wordDict = {"a", "abc", "b", "cd"};

    bool a = wordBreak(s, wordDict);
}