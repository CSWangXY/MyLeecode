/*
class Solution
{
public:
    bool match(int i, int j, string s, string p)
    {
        if (i == 0)
            return false;
        if (p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    }
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    if (match(i, j - 1, s, p))
                        f[i][j] = f[i - 1][j] || f[i][j - 2];
                    else
                        f[i][j] = f[i][j - 2];
                }
                else
                {
                    if (match(i, j, s, p))
                        f[i][j] = f[i - 1][j - 1];
                    else
                        f[i][j] = false;
                }
            }
        }
        return f[m][n];
    }
};

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
    f[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        if (p[i - 1] != '*')
            f[0][i] = false;
        else
            f[0][i] = f[0][i - 2];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] >= 'a' && p[j - 1] <= 'z')
            {
                f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
            else if (p[j - 1] == '.')
                f[i][j] = f[i - 1][j - 1];
            else
            {
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                    f[i][j] = f[i][j - 2];
                else if ((s[i - 1] == p[j - 2] && p[j - 2] != '.') || p[j - 2] == '.')
                    f[i][j] = f[i][j - 2] || f[i - 1][j];
            }
        }
    }
    return f[m][n];
}

int main()
{
    string s = "aa";
    string p = "a";
    isMatch(s, p);
}