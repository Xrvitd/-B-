#include <bits/stdc++.h>
using namespace std;
int id(int i, int j) {
    return i * (i - 1) / 2 + j;
}
double dis[100][100];
int main() {
    srand(time(0));
    int n = 6;
    cout << n * (n + 1) / 2 << ' ' << n * (n - 1) / 2 * 3 * 2 << endl;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            cout << id(i, j) << ' ' << id(i, j + 1) << endl;
            cout << id(i, j + 1) << ' ' << id(i, j) << endl;
            cout << id(i, j) << ' ' << id(i + 1, j) << endl;
            cout << id(i + 1, j) << ' ' << id(i, j) << endl;
            cout << id(i, j) << ' ' << id(i + 1, j + 1) << endl;
            cout << id(i + 1, j + 1) << ' ' << id(i, j) << endl;
            cnt += 6;
        }
        cout << id(i, i) << ' ' << id(i + 1, i) << endl;
        cout << id(i + 1, i) << ' ' << id(i, i) << endl;
        cout << id(i, i) << ' ' << id(i + 1, i + 1) << endl;
        cout << id(i + 1, i + 1) << ' ' << id(i, i) << endl;
        cnt += 4;
    }
    for (int i = 1; i < n; ++i) {
        cout << id(n, i) << ' ' << id(n, i + 1) << endl;
        cout << id(n, i + 1) << ' ' << id(n, i) << endl;
        cnt += 2;
    }
    // cout << cnt << endl;

    // for (int i = 1; i <= n * (n + 1) / 2; ++i) {
    //     cout << 1.0 * (rand() % 1000 + 1) / 10000 << endl;
    // }

    // for (int i = 1; i <= n * (n + 1) / 2; ++i) {
    //     for (int j = i + 1; j <= n * (n + 1) / 2; ++j) {
    //         double d = 1.0 * (rand() % 4000 + 100) / 10;
    //         dis[i][j] = dis[j][i] = d;
    //     }
    // }
    // for(int i=1;i<=n*(n+1)/2;++i) {
    //     for(int j=1;j<=n*(n+1)/2;++j) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << 1.0 * (rand() % 400 + 900) << endl;
    // cout << 1.0 * (rand() % 400 + 800) << endl;
    // for (int i = 3; i <= n * (n + 1) / 2; ++i) {
    //     cout << 1.0 * (rand() % 4000 + 1) / 10 << endl;
    // }
    return 0;
}