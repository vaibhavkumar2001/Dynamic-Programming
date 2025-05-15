#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int SolveUsingRec(vector<vector<int>>& obstacleGrid, int i, int j) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Out of bounds
        if(i >= m || j >= n) return 0;

        // Obstacle found
        if(obstacleGrid[i][j] == 1) return 0;

        // Reached destination
        if(i == m - 1 && j == n - 1) return 1;

        int down = SolveUsingRec(obstacleGrid, i + 1, j);
        int right = SolveUsingRec(obstacleGrid, i, j + 1);
        return down + right;
    }

    //Ab main Top Down approach lagaoonga
    int SolveUsingMem(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(i >= m || j >= n) return 0;
    if(obstacleGrid[i][j] == 1) return 0;
    if(i == m - 1 && j == n - 1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int down = SolveUsingMem(obstacleGrid, i + 1, j, dp);
    int right = SolveUsingMem(obstacleGrid, i, j + 1, dp);

    return dp[i][j] = down + right;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // Edge case: if start or end is an obstacle
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    vector<vector<int>> dp(m, vector<int>(n, -1)); // rows x cols
    return SolveUsingMem(obstacleGrid, 0, 0, dp);
}
};


//BOTTOM UP APPROACH
class Solution {
public:
    int SolveUsingTab(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // If starting point is an obstacle, return 0
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        // Fill first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1)
                dp[i][0] = 1;
        }
        // Fill first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1)
                dp[0][j] = 1;
        }
        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return SolveUsingTab(obstacleGrid);
    }
};


