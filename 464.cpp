#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
void DFS(int maxChoosableInteger, int desiredTotal, vector<int>& path, int sum, int start)
    {
        if(sum >= desiredTotal)
            result.push_back(path);
        for(int i=start;i<maxChoosableInteger;i++)
        {
            path.push_back(i);
            DFS(maxChoosableInteger, desiredTotal, path, sum+i, start+1);
            path.pop_back();
        }
    }
int main()
    {
        int maxChoosableInteger = 10;
        int desiredTotal = 11;
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if(sum < desiredTotal)
        return false;
        vector<int> path;
        DFS(maxChoosableInteger, desiredTotal, path, 0, 1);
        for(int i = 0; i<result.size(); i++)
        {
            if(result[i].size()%2 == 0)
            return false;
        }
        return true;
    }

    