#include<iostream>
#include<vector>
#include<string>
using namespace std;

void DFS(string s , vector<string>& result, vector<string>& path, int num, int start )
    {
        if(num == 4  )
        {
            if(path.size() == 4 && start == s.size())
            {
                string r = "";
                for(int i=0; i<=3; i++)
                {
                    r = r + path[i];
                    if(i !=3)
                    r = r + '.';
                }
                result.push_back(r);
            }
            return;
        }
        int c = 0 ;
        for(int i = start; i<s.size(); i++)
        {
            c = c*10 + int(s[i]-'0');
            string curr = s.substr(start,i-start+1);
            
           
            if(c<0 || c>=256 || curr[0] == '0')
            break;
            path.push_back(curr);
            DFS(s , result, path, num+1, i+1);
            path.pop_back();
        }
}

int main() 
    {
        string s = "25525511135";
        vector<string> res;
        vector<string> path;
        DFS(s , res, path, 0, 0);
        for(int i = 0; i<res.size(); i++)
        cout<<res[i];
    }

    
