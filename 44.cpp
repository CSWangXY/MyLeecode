class Solution
{
public:
    bool match(int i, int j, string s, string p)
    {
        if (i == 0)
            return false;
        if (p[j - 1] == '*' || p[j - 1] == '?')
            return true;
        return s[i - 1] == p[j - 1];
    }
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')
                f[0][i] = true;
            else
                break;
        }

        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 0)
                    break;
                if (p[j - 1] == '*')
                {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                }
                else if (p[j - 1] == '?')
                {
                    f[i][j] = f[i - 1][j - 1];
                }
                else
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};