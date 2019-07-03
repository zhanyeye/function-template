#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e3 + 9;
const int M = 1e4 + 9;
const int INF = 0x3f3f3f3f;

struct edge {
    int v, w, next;
    edge() {}
    edge(int _v, int _w, int _next) : v(_v), w(_w), next(_next) {}
} E[2 * M];

int head[N];
int cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void insert(int u, int v, int w) {
    E[cnt] = edge(v, w, head[u]);
    head[u] = cnt++;
}

void insert2(int u, int v, int w) {
    insert(u, v, w);
    insert(v, u, w);
}

int n, m;
int dis[N];
bool vis[N];
int in[N];

bool spfa(int u) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    memset(in, 0, sizeof in);
    dis[u] = 0;
    vis[u] = true;
    in[u] = 1;
    
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for (int e = head[tmp]; ~e; e = E[e].next) {
            int v = E[e].v;
            int w = E[e].w;
            if (dis[v] > dis[tmp] + w) {
                dis[v] = dis[tmp] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    in[v]++;
                    if (in[v] > n) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    init();
    int u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        insert2(u, v, w);
    }
    if (spfa(1)) {
        cout << "没有负环" << endl;
    } else {
        cout << "有负环" << endl;
    }
    return 0;
}