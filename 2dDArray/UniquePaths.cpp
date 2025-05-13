#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//YEH MAINE RECUSION SE SOLVE KIYA H AB MAIN TOP DOWN LAGA OOONGA
    int SolveUsingRec(int i, int j, int m, int n) {
        // base case: reached destination
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        // out of bounds
        if(i >= m || j >= n) {
            return 0;
        }
        // move down and right
        int down = SolveUsingRec(i + 1, j, m, n);
        int right = SolveUsingRec(i, j + 1, m, n);
        return down + right;
    }


    //TOP DOWN APPROACH

    
    int uniquePaths(int m, int n) {
        return SolveUsingRec(0, 0, m, n);
    }
};
