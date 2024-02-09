#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> ret(n + 1, vector<long long>(m + 1)), dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ret[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = dp[i - 1][j] - dp[i - 1][j - 1] + dp[i][j - 1] + ret[i][j];

    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << endl;
    }

}