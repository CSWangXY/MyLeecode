#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    map<char, char> s;
    int count = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (s.find(key[i]) == s.end()&& key[i]!= ' ')
        {
            s[key[i]] = 'a' + count;
            count++;
            cout << count;
        }
    }

    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] != ' ' )
        {
            message[i] = s[message[i]];
        }
    }
    cout << s['t'] << s['h'];
    cout<<message;
}