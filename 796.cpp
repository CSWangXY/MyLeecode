#include<iostream>
#include<string>
using namespace std;
    
int main()
    {
        string s,goal;
        cin>>s>>goal;
        int slen = s.size();
        int glen = goal.size();
        if(slen != glen)
        {
            cout<<"No"<<endl;
            return 0;
        }
        if(s == goal)
       {
           cout<<"Yes"<<endl;
           return 0;
       }
        for(int i=1;i<slen;i++)
        {
            bool flag = true;
            for(int j=0;j<slen;j++)
            {
                int po = j;
                int curr = (j+i)%slen;
                if(goal[j] != s[curr])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }