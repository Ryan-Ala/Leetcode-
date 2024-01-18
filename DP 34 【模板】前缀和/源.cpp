#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;

    cin >> n;
    cin >> q;

    vector<long long> ret(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> ret[i];

    for (int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] + ret[i];

    int left, right;
    while (cin >> left >> right)
    {
        cout << dp[right] - dp[left - 1] << endl;
    }
}