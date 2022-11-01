#include <iostream>
using namespace std;

int cal()
{
    static int c = 0;
    return 1;
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << cal();
}