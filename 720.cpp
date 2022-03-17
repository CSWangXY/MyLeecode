#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
bool cmp(string a, string b)
    {
        if(a.length() != b.length())
            return a.length()<b.length();
            else return a<b;
    }
int main()
{
    string b[]={"a","banana","app","appl","ap","apply","apple"};
    vector<string> a(b,b+7);
    //vector<string> a ;//={"a","banana","app","appl","ap","apply","apple"};
    sort(a.begin(),a.end(),cmp);
    string longest; 
    unordered_set<string> w={""};
    //sort(words.begin(),words.end(),cmp);
        for(int i =0;i<a.size();i++ )
        {
            cout<<a[i]<<endl;
            if(w.count(a[i].substr(0,a[i].size()-1))==1)
                {
                    w.emplace(a[i]);
                    longest = a[i];
                }
        }
       
        cout<<longest;
    
}



/*class Solution {
public:
    static bool cmp(string a, string b)
    {
        if(a.length() != b.length())
            return a.length()<b.length();
            else return a>b;
    }
    string longestWord(vector<string>& words) 
    {
        string longest;
        unordered_set<string> w={""};
        sort(words.begin(),words.end(),cmp);
        for(int i =0;i<words.size();i++ )
        {
            if(w.count(words[i].substr(0,words[i].size()-1))==1)
                {
                    w.emplace(words[i]);
                    longest = words[i];
                }
        }
        return longest;
    }

    

};*/
