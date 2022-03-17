#include<iostream>
using namespace std;
       
    
       int main()
       {
        int nums[]={1,2,2,3,1,4,2};
        int hashtable[10][3]={};
        for(int i=0;i<10;i++)
        {
            hashtable[i][0] = -1;
            hashtable[i][1] = -1;
            hashtable[i][2] = 0;
        }
        for(int i=0;i<7;i++)
        {
            if(hashtable[nums[i]][0] == -1)
            {
                hashtable[nums[i]][0] = i ;
            }
            else  hashtable[nums[i]][1] = i ;
            hashtable[nums[i]][2]++;
        }

        int maxdegree = -1;
        int minlen = 60000;
        for(int i=0;i<10;i++)
        {
            if(hashtable[i][0]==-1 || hashtable[i][1]==-1)
            {}
            else
            {
                if(hashtable[i][2]>maxdegree )
                {
                    
                    maxdegree = hashtable[i][2];
                    minlen = hashtable[i][1]-hashtable[i][0]+1;
                }
                else if(hashtable[i][2] == maxdegree && hashtable[i][1]-hashtable[i][0]+1<minlen)
                {
                
                    minlen = hashtable[i][1]-hashtable[i][0]+1;
                }
            }
        }
        if(minlen == 60000)
        cout<< 1;
        else cout<<minlen;
       }
