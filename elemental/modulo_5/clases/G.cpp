#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
int n;
vector<int> monedas, memo;

int contar_formas(int x)
{
    // Caso base
    if (x == 0)
        return 1; // Una forma de hacer 0, no usar monedas
    // Memorización
    if (memo[x] != -1)
        return memo[x];
    // Proceso
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= monedas[i])
        {
            sum = (sum % MOD + contar_formas(x - monedas[i]) % MOD) % MOD; // Sumar las formas de hacer x-monedas[i]
        }
    }
    return memo[x] = sum;
}

int main(){
    int x;
    cin >> n >> x;
    memo.assign(x + 1, -1);
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        monedas.push_back(c);
    }
    cout << (contar_formas(x)) << endl; // Imprimir el número de formas de hacer x
    return 0;
}