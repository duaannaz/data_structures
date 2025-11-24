#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        vector<long long> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        if (k == 0 || n == 0) {
            cout << 0 << "\n";
            continue;
        }
        vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));
        for (int i = 1; i <= k; i++) {
            long long bestBuy = -price[0];

            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1];
                dp[i][j] = max(dp[i][j], price[j] + bestBuy);
                bestBuy = max(bestBuy, dp[i - 1][j] - price[j]);
            }
        }
        cout << dp[k][n - 1] << "\n";
    }
    return 0;
}
