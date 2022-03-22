#include <iostream>
#include <string>
using namespace std;
    int main()
    {
        int a=0;
        int b=0;
        int cnt = 0;
        char cur='C';
        string colors="AAAABBBB";
        for(int i=0;i<colors.size();i++)
        {
            char now = colors[i];
            if(now != cur)
            {
                if(cur == 'A' && cnt>=3)
                {
                    a = a + cnt -2;
                }
                else if(cur == 'B'&& cnt>=3)
                {
                    b = b + cnt -2;
                }
                cur = now;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        if(a>b && a>=1)
        cout<<1;
        else cout<<0;
        cout<<a<<"    "<<b;
    }