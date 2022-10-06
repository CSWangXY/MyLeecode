#include<iostream>
#include<string>
using namespace std;

int main()
{
    string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    int index1 = queryIP.find(".");
    int index2 = queryIP.find(":");
    int n = queryIP.size();
    string x;
    string y = queryIP;
    string z = "Neither";
    int last = 0;
    if(index1 == -1 && index2 == -1)
    {
           cout<< z;
           return 0;
    }
    else if(index1 != -1 && index2 == -1)
    {
        for(int i=1; i<=4; i++)
        {
            int index = y.find(".");
            if(index != -1 && i==4)
            {
                cout<<z;
                return 0;
            }
            else if(index == -1)
            {
                cout<<z;
                return 0;
            }
            else
            {
            x = y.substr(last , index-last);
            y = y.substr(index+1 , n-index-1 );
            }

            if(x[0]=='0' && x!="0")
            {
                cout<<z;
                return 0;
            }
            else
            {
                int val = 0;
                for(int i=0;i<x.size();i++)
                {
                    if(val > 30)
                    {
                        cout<<z;
                        return 0;
                    }
                    val = val*10+int(x[i]-'0');
                }
                if(val >255 || val < 0)
                {
                    cout<<z;
                    return 0;
                }
            }
        }
        cout<<"IPv4";
        return 0;
    }
        else 
        {
            for(int i=1; i<=8; i++)
            {
                int index = y.find(":");
                if(index != -1 && i==8)
               {
                   cout<<z;
                   return 0;
               }
                else if(index == -1)
                {
                    cout<<z;
                    return 0;
                }
                else
                {
                    x = y.substr(last , index-last);
                    y = y.substr(index+1 , n-index-1 );
                }
                for(int i=0; i<x.size(); i++)
                {
                    if((x[i]>='a'&&x[i]<='z')||(x[i]>='0'&&x[i]<='9')||(x[i]>='A'&&x[i]<='Z'))
                    {}
                    else
                    {
                        cout<<z;
                        return 0;
                    }
                }
            }
            cout<<"IPv6";
            return 0;
        }
    
    cout<< z;
    return 0;
       
}