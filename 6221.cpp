#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct creats
{
    string name;
    string maxid;
    int maxview;
    int sum;
} f[100005];
static bool cmp(creats a, creats b)
{
    return a.sum > b.sum;
}

vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
{
    map<string, int> c;
    int peonum = 0;
    for (int i = 0; i < creators.size(); i++)
    {
        if (c.find(creators[i]) == c.end())
        {
            c[creators[i]] = peonum;
            f[peonum].name = creators[i];
            f[peonum].maxid = ids[i];
            f[peonum].maxview = views[i];
            f[peonum].sum = views[i];
            peonum++;
        }
        else
        {
            int index = c[creators[i]];
            if (f[index].maxview < views[i] || (f[index].maxview == views[i] && f[index].maxid < ids[i]))
            {
                f[index].maxid = ids[i];
                f[index].maxview = views[i];
            }
            f[index].sum += views[i];
        }
    }
    sort(f, f + peonum, cmp);
    vector<vector<string>> ans;
    ans.push_back({f[0].name, f[0].maxid});
    // cout<<f[1].maxview;
    for (int i = 1; i < peonum; i++)
    {
        if (f[i].sum == f[i - 1].sum)
            ans.push_back({f[i].name, f[i].maxid});
        else
            break;
    }
    return ans;
}
int main()
{
    vector<string> creators{"q", "p", "i"};
    vector<string> ids{"sfoj", "qqgo", "yanl"};
    vector<int> views{4, 0, 4};
    mostPopularCreator(creators, ids, views);
}