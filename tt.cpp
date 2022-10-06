#include<iostream>
#include<string>
using namespace std;
 
 int main()
 {
        string sentence = "ka3caz4837h6ada4 r1 $602";
        int discount = 9;
        
        int i = 0;
        while(i<sentence.size())
        {
            if(sentence[i] == '$')
            {
                int left = i+1;
                int right ;
                for(int j=left ; j<sentence.size(); j++)
                {
                    if(sentence[j]>='0' && sentence[j]<='9')
                    {}
                    else
                    {
                        right = j-1;
                        break;
                    }      
                }
                int n = sentence.size();
                string x = sentence.substr(0,left);
                string y = sentence.substr(left , right-left +1);
                string z = "";
                if(right+1<sentence.size())
                z = sentence.substr(right+1, n-right);
                else z ="";
                //if(right+1 < sentence.size()&&sentence[right+1] == '$')
                //{}
                if(y!="" )
                {
                    double ans = 0.0;
                    for(int j=0;j<y.size();j++)
                    {
                        ans = ans*10 + int(y[j] -'0');
                    }
                ans = ans * double(100-discount)/double(100);
                y = to_string(ans);
                y = y.substr(0,y.size()-4);
                sentence = x+y+z;
                }
                
                //i =right+1;
            }
            i++;
        }
        
        cout<<sentence;
    }