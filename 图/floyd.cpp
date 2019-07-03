#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 101;
int g[N][N];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < N; i++) {
        g[i][i] = 0;
    }
    int n, m;
    int u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    floyd(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}