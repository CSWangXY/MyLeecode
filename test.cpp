#include<iostream>
using namespace std;

int main()
{
    bool HashTable[3000]={false};
    int x;
    while(cin>>x)
    {
        if(HashTable[x]==true)
        cout<<"youwenti";
        else
        {
            HashTable[x]=true;
        }

    }
}