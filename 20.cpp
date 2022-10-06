#include<iostream>
#include<string> 
#include<map>
#include<stack>
using namespace std;

int main() 
    {
        string s = "()";
        bool flag = true;
        int n=s.size();
        if(n%2==1)
        {
            flag = false;
            cout<<flag;
            return 0;
        }
        map<char,char> ss ={
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char> m;
        m.push(s[0]);
        for(int i=1;i<n;i++)
        {
            char curr = s[i];
            if(curr=='}'||curr==')'||curr==']')
            {
                
                if(m.empty()||ss[curr] != m.top())
                {
                    {
                        flag = false;
                        cout<<flag;
                        return 0;
                    }
                }
                else m.pop();
            }
            else m.push(curr);
        }
        cout<<flag;
        return 0;
    }