#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, x;
int h[1001], s[100001];

int main() {
    cin >> n >> x;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    // mochila iteradora
    for (int i = 1; i <= n; ++i) {
        int costo = h[i - 1];
        int pag = s[i - 1];
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (costo <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - costo] + pag);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
