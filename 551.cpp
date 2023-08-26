#include <iostream>
#include <string>
using namespace std;
bool checkRecord(string s)
{
    int A = 0;
    int L = 0;
    int i = 0;
    int n = s.size();
    int start;
    while (i < n)
    {
        if (s[i] == 'A')
        {
            A++;
            i++;
            if (A >= 2)
                return false;
        }
        else if ((i == 0 || s[i - 1] != 'L') && s[i] == 'L')
        {
            start = i;
            while (start <= n && s[start] == 'L')
            {
                start++;
            }
            if (start - i >= 3)
                return false;
            i = start;
            cout << start;
        }
        else
            i++;
    }
    return true;
}

int main()
{
    string s = "PPALLP";
    checkRecord(s);
}
