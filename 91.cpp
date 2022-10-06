#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int  n = s.size();
    vector<int> f(n+5);
    f[0] = 1;
    if(n==1)
    return 1;
    for(int i=1; i<n;i++)
    {
        if(s[i-1] != '0')
        f[i] += f[i-1];
    }
    for(int i=2; i<n; i++)
    {
        if(s[i-2] != '0' && (10*(s[i-1]-'0') + s[i]-'0')<=26)
        f[i] +=f[i-2];
    }
    cout<< f[n-1];
}
        
