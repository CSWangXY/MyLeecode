#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    
    int m = s1.size();
    int n = s2.size();
    int k = s3.size();
    if(m+n != k)
    return false;
    vector<vector<int>>  f(m+1 ,  vector <int> (n + 1, false));
    f[0][0] = true;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            int p = i+j-1;
            if(i>0 && s3[p] == s1[i-1])
            f[i][j] = f[i-1][j];
            else if(i>0 && s3[p] != s1[i-1]) 
            f[i][j] = false;

            else if(j >0 && s3[p] == s2[j-1])
            f[i][j] = f[i][j-1];
            else
            f[i][j] = false;
        }
    }

    cout<<f[m][n];
}