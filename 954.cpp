#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
    {
        if(abs(a)!=abs(b))
        return abs(a)<abs(b);
        else return a<=b;
    }
int main()
{
    int a[]={2,2,1,1,1,1};
    vector<int> arr(a,a+6);
    if(arr.size()%2==1)
        return 0;
    map<int,int> hashtable;
    for(int i=0;i<arr.size();i++)
    {
         hashtable[arr[i]]++;
    }
    vector<int> vals;
    for (auto &[x, _] : hashtable) 
        {
            vals.push_back(x);
        }
    sort(vals.begin(),vals.end(),cmp);
    for(int i=0;i<vals.size();i++)
    {
    int num = vals[i];
    if(num==0 && hashtable[0]<=1)
    return 0;
    if(hashtable[num*2]<=0)
    return 0;
    else
        {
            hashtable[num*2]--;
            hashtable[num]--;
        } 
        }
        cout<<1;
        cout<<hashtable[100];
        cout<<'*';
}
 