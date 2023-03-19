#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n)
{
    if (n == 1)
        return {"()"};

    vector<vector<string>> f(n + 1, vector<string>(n + 1));
    ;
    f[0] = {};
    f[1] = {"()"};

    for (int i = 2; i <= n; i++)
    {
        vector<string> ans;
        for (int j = 0; j <= i - 1; j++)
        {
            vector<string> leftpart = f[j];
            vector<string> rightpart = f[i - j - 1];

            if (leftpart.size() == 0)
            {
                for (auto tmp : rightpart)
                {
                    auto thistmp = "()" + tmp;
                    ans.push_back(thistmp);
                }
            }
            else if (rightpart.size() == 0)
            {
                for (auto tmp : leftpart)
                {
                    auto thistmp = "(" + tmp + ")";
                    ans.push_back(thistmp);
                }
            }
            else
            {
                for (auto lefttmp : leftpart)
                {
                    for (auto righttmp : rightpart)
                    {
                        auto tmp = "(" + lefttmp + ")" + righttmp;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        f[i] = ans;
    }
    return f[n];
}

int main()
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (auto item : ans)
        cout << item;
}