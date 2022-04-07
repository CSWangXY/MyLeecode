#include<iostream>
#include<string>
#include <vector>
using namespace std;




int main()
    {
        string s = "aaa";
        string r ="";
        int n = s.size();
        if(n==1)
        cout<<s;
        if(n==2 && s[0]!=s[1])
        cout<<s.substr(0,1);
        else if(n==2 && s[0]==s[1])
        cout<<s;
        vector<vector<int>> p(n, vector<int>(n)); 
       
        for(int i=0;i<n;i++)
        p[i][i]=true;
        int L=2;
        for(;L<=n;L++)
        {
        for(int i=0;i<n-L+1;i++)
        {
            int j = i+L-1;
            if(s[i] != s[j])
            p[i][j]=false;
            else if(i+1 <= j-1)
            {
                if(p[i+1][j-1]==true)
                p[i][j] = true;
                else p[i][j] = false;
            }
            else p[i][j] = true;
            if(p[i][j]==true && r.size() < j-i+1)
            r = s.substr(i,j);//错误，substr的第一个参数是截取起始位置，第二个参数是截取长度

         }
        
        }
         cout<<r;

    }
