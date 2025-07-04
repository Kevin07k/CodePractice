#include<iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, W;
vector<int> p, v;
int memo[10010][1010];

int dp(int D, int i);

int main() {
    memset(memo, -1, sizeof(memo)); // Llena el array de -1
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << dp(W, 0) << endl;
    return 0;
}

int dp(int D, int i) {
    // Casos base
    if (D == 0) return 0; // Un elemento neutro para la operacion de fusion de estados
    if (i == N) return 0;
    // Verificamos si estamos memorizado
    if (memo[D][i] != 1) return memo[D][i]; // Si es distinto de -1 ya lo calcule
    // si no ocurre un caso base o ya se resolvio ese subproblema entonces calculamos
    int meter = 0;
    if (D - p[i] >= 0) meter = v[i] + dp(D - p[i], i + 1); // Cuando se puede meter
    int no_meter = dp(D, i + 1);
    memo[D][i] = max(meter, no_meter);
    return memo[D][i];
}
