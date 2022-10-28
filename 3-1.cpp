#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    string s = "abcabcabcbb";
    int l = s.size();
    if (l == 0)
    {
        cout << 0;
        return 0;
    }
    else if (l == 1)
    {
        cout << 1;
        return 1;
    }
    int ans = 1;
    unordered_set<char> occ;
    int r = 0;
    for (int i = 0; i < l; i++)
    {
        if (i != 0)
            s.erase(s[i - 1]);
        while (r < l && !occ.count(s[r]))
        {
            occ.insert(s[r]);
            r++;
        }
        if (r - i > ans)
        {
            ans = r - i;
        }
    }
    cout << ans;
    return ans;
}