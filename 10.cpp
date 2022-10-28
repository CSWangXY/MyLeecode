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