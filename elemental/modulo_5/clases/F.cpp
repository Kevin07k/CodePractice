/*
 * Coin Change
*/
#include<iostream>
#include<vector>

using namespace std;
typedef vector<int> vi;

vi memo, moneda;

int change(int digit) {
    if (digit == 0) return 0;
    if (digit < 0) return 100000000;
    int res = 100000000;
    if (memo[digit] != -1) return memo[digit];
    for (int i = 0; i < moneda.size(); i++) {
        res = min(res, 1 + change(digit - moneda[i]));
    }
    return memo[digit] = res;
}

int main() {
    int number, totalChain;
    cin >> number >> totalChain;
    memo.assign(totalChain + 1, -1);
    for (int i = 0; i < number; ++i) {
        int x;
        cin >> x;
        moneda.push_back(x);
    }
    int res = change(totalChain);
    if (res >= 100000000) {
        cout << "-1" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}