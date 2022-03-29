#include<iostream>
#include <string>
using namespace std;
int maxTorF(string answerKey, int k , char c)
    {
        int len = answerKey.size();
        int max = -1;
        for(int i=0;i<len;i++)
        {
            int tmp = 0;
            for(int j=i;j<len;j++)
            {
                if(answerKey[j]!= c)
                {
                    if(tmp >k && j-i >max)
                {
                    max = j-i;
                    break;
                }
                else if(tmp >k && j-i <= max )
                break;
                else 
                    {
                        tmp++;
                        if(j-i+1 > max)
                    {
                        max = j-i+1;
                    }
                    }                
                    if(j-i > max)
                    {
                        max = j-i+1;
                    }
                }
                else
                {
                    if(j-i+1> max)
                    {
                        max = j-i+1;
                    }
                    
                }
            }
        }
        return max;
} 

 int main() 
    {
        string answerKey="TFFT";
        int k=1;
        int F = maxTorF(answerKey,k,'F');
        int T = maxTorF(answerKey,k,'T');
        cout<<(T>F? T:F);    
    }

    