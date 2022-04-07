#include<iostream>
#include<string>
using namespace std;

int main()
{
    {
        string s;
        cin>>s;
        int n = s.size();
        int result = 0;
        int i=0;
        int flag = 1;
        while(s[i]==' ' && i<n)
        i++;
        if(i==n)
        {
            cout<<0;
            return 0;
        }
        
        if(s[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if(s[i]=='+')
        {
            flag = 1;
            i++;
        }
        while(s[i]>='0' && s[i]<='9'&& i<n)
        {
             if(result>(INT_MAX-int(s[i]-'0'))/10&&flag == -1 )
            {
                cout<<INT_MIN;
                return 0;
            }
            if(result<(INT_MIN)/10&&flag == -1)
            {
                cout<<INT_MAX;
                return 0;
            }
            if(result>(INT_MAX-int(s[i]-'0'))/10&&flag == 1)
            {
                cout<<INT_MAX;
                return 0;
            }
            if(result<(INT_MIN)/10&&flag == 1)
            {
                cout<<INT_MIN;
                return 0;
            }
            result = result*10 + int(s[i]-'0');
            i++;
            result = result*10 + int(s[i]-'0');
            i++;
        }

        cout<<result*flag;
    }
}