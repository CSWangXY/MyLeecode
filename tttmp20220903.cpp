#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> a{1,2,3,4};
    vector<int>::iterator it = a.begin();
    cout<<*it;
}