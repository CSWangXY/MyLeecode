#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int sum = 0;
int diff = INT_MAX;
vector<int> rans;
vector<int> path;
void backtrack(vector<int> a, vector<int> path, int index, int rsum)
{
    int lsum = sum - rsum;
    if(index != 0 && abs(lsum-rsum)<diff)
    {
        rans = path;
        diff = abs(lsum-rsum);
        
    }

    for(int i=index; i<a.size(); i++)
    {
        path.push_back(a[i]);
        int tmp = 0;
        for(int j=0; j<path.size(); j++)
        tmp += path[j];
        backtrack(a, path, i+1, tmp);
        path.pop_back();
    }
}

int main()
{
    vector<int> a{4,5,6,7,8,12};
    for(int i=0; i<a.size(); i++)
    sum += a[i];
    
    backtrack(a , path, 0, 0);
    cout<<rans.size()<<endl;
    for(int i=0; i<rans.size(); i++)
    cout<<rans[i]<<endl;
}