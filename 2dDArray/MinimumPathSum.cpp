#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int SolveUsingRec(vector<vector<int>>& grid,int i,int j) {
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n) {
            //agr main out of bound pe pachooch gaya g toh main min return kr doogna
            return INT_MAX;
        }
        if(i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        int down = SolveUsingRec(grid, i + 1, j);
        int right = SolveUsingRec(grid, i, j + 1);
        return grid[i][j] + min(down, right);
    }

    //ab  main Memoization se solve karoonga
    int SolveUsingMem(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp) {
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n) {
            //agr main out of bound pe pachooch gaya g toh main min return kr doogna
            return INT_MAX;
        }
        if(i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = SolveUsingMem(grid, i + 1, j,dp);
        int right = SolveUsingMem(grid, i, j + 1,dp);
        dp[i][j] = grid[i][j] + min(down, right);
        return dp[i][j];
    }

    //BOTTOM UP APPROACH

    int SolveUsingTab(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) {
                dp[i][j] = grid[i][j];
            } else {
                int down = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;
                int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(down, right);
            }
        }
    }
    return dp[0][0];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1)); // rows x cols
        // return SolveUsingRec(grid, 0, 0);
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return SolveUsingMem(grid, 0, 0,dp);
    }
};