#include<iostream>
#include<stack>
using namespace std;

int main() 
    {
        string s = "(()())(())";
        stack<char> k;
        string result = "";
        int last = 0;
        for(int i=0; i<s.size(); i++)
        {
            
            if(s[i] == '(')
            k.push('(');
            if(s[i] == ')')
            k.pop();
            if(i!=0 && k.size()==0)
            {
                result = result + s.substr(last+1,i-last-1);
                last = i+1;
            }
        }
        cout<<result;
    }
