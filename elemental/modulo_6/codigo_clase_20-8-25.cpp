//
// Created by brand on 8/20/2025.
//
#include<iostream>
#include<assert.h>
#include<unordered_map>
#include<queue>

using namespace std;

int divisor_3(int N) {
    int res = -1, x = 3;
    while (x <= N) {
        if (N % x == 0) {
            res = x;
        }
        x = x * 3;
    }
    return res;
}

int empty(int N) {
    unordered_map<int, int> s;
    s[N] = 0; // * La catidad de operaciones para llegar a N es 0
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        N = q.front();
        q.pop();
        if (N > 1000000000) continue;
        if (N == 0) break;
        // * Recorremos los vecinos
        // * +1
        if (s.find(N + 1) != s.end()) {
            s[N + 1] = s[N] + 1;
            q.push(N + 1);
        }
        // * -1
        if (s.find(N - 1) != s.end()) {
            s[N - 1] = s[N] + 1;
            q.push(N - 1);
        }
        // * X2
        if (s.find(N * 2) != s.end()) {
            s[N * 2] = s[N] + 1;
            q.push(N * 2);
        }
        // * / 3 ^ k
        int divisor = divisor_3(N);
        cout << "El divisor de " << N << " es " << divisor << "\n";
        if (divisor == -1) continue;
        if (s.find(N / divisor) != s.end()) {
            s[N / divisor] = s[N] + 1;
            q.push(N / divisor);
        }
    }
    return s[0];
}

int main() {
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%d\n", empty(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
