#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int s = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> f(s, vector<int>(n));
    if (obstacleGrid[0][0] == 0)
        f[0][0] = 1;
    else
        f[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[0][i] == 0)
            f[0][i] = 1;
        if (obstacleGrid[0][i] == 1)
        {

            for (int j = i; j < n; j++)
                f[0][j] = 0;
            break;
        }
    }
    for (int i = 0; i < s; i++)
    {
        if (obstacleGrid[i][0] == 0)
            f[i][0] = 1;
        if (obstacleGrid[i][0] == 1)
        {
            for (int j = i; j < s; j++)
                f[j][0] = 0;
            break;
        }
    }
    for (int i = 1; i < s; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                f[i][j] = 0;
            else
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    // cout<<f[0][0]<<f[1][1]<<f[2][2];
    return f[s - 1][n - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid{{0, 0}};
    uniquePathsWithObstacles(obstacleGrid);
}