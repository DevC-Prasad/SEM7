
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int W, int wt[], int val[],
          vector<vector<int>>& dp) {

    if (i == 0) {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    // Not Take
    int notTake = solve(i - 1, W, wt, val, dp);

    // Take
    int take = 0;

    if (wt[i] <= W) {
        take = val[i] + solve(i - 1, W - wt[i],
                              wt, val, dp);
    }

    return dp[i][W] = max(take, notTake);
}

int main() {
    int n = 4;
    int W = 7;

    int wt[] = {1, 3, 4, 5};
    int val[] = {4, 1, 5, 7};

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    int maxProfit = solve(n - 1, W, wt, val, dp);

    cout << "Maximum Profit: " << maxProfit;

    // Find selected items using backtracking
    cout << "\nSelected Items:\n";

    int remainingW = W;

    for (int i = n - 1; i > 0; i--) {

        int notTake = solve(i - 1, remainingW, wt, val, dp);

        if (dp[i][remainingW] != notTake) {
            cout << "Item " << i + 1
                 << " (Weight: " << wt[i]
                 << ", Profit: " << val[i] << ")\n";

            remainingW -= wt[i];
        }
    }

    // Check first item
    if (remainingW >= wt[0]) {
        cout << "Item 1 (Weight: " << wt[0]
             << ", Profit: " << val[0] << ")\n";
    }

    return 0;
}
