#include <bits/stdc++.h>
using namespace std;

/*
    🔥 LEETCODE PATTERN: 2D PREFIX SUM (Immutable Matrix)
    ------------------------------------------------------
    Build a prefix matrix "pre" of size (m+1) x (n+1):

        pre[i][j] = sum of rectangle from (0,0) to (i-1, j-1)

    Then sumRegion(r1,c1,r2,c2) = 
        pre[r2+1][c2+1]
      - pre[r1][c2+1]
      - pre[r2+1][c1]
      + pre[r1][c1]

    Time:
        Constructor:  O(m * n)
        Query:        O(1)
    Space:
        O(m * n)
*/

class NumMatrix {
public:
    vector<vector<int>> pre;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Build prefix matrix with 1-based indexing
        pre.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = matrix[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        return pre[r2 + 1][c2 + 1]
             - pre[r1][c2 + 1]
             - pre[r2 + 1][c1]
             + pre[r1][c1];
    }
};


// ----------------------------------------------------
//                         MAIN
// ----------------------------------------------------

void printMatrix(const vector<vector<int>>& mat) {
    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    cout << "Input Matrix:\n";
    printMatrix(matrix);

    NumMatrix obj(matrix);

    vector<vector<int>> queries = {
        {2,1,4,3},  // → 8
        {1,1,2,2},  // → 11
        {1,2,2,4},  // → 12
        {0,0,0,0},  // → 3
    };

    cout << "\n2D Prefix Sum Query Results:\n\n";

    for (auto &q : queries) {
        int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
        int ans = obj.sumRegion(r1, c1, r2, c2);
        cout << "sumRegion(" << r1 << "," << c1 << "," << r2 << "," << c2 
             << ") = " << ans << "\n";
    }

    return 0;
}
