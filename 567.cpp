#include<iostream>
#include<vector>
#include<string>
using namespace std;


 
 
 bool checkInclusion(string s1, string s2) 
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 < len2)
        return false;

        vector<int> num1(26);
        vector<int> num2(26);

        for(int i=0 ; i<len2 ; i++)
        {
            num2[s2[i]-'a']++;
            num1[s1[i]-'a']++;
        }
        if(num1 == num2)
        return true;
        for(int i=1; i<=len1-len2; i++)
        {
            num1[s1[i-1]-'a']--;
            num1[s1[i+len2-1]-'a']++;
            if(num1==num2)
            return true;
        }
        return false;
    }


int main()
{
    string s1 = "eidbaooo";
    string s2 = "ab";
    bool result =  checkInclusion(s1 , s2);
    cout<<result;
}