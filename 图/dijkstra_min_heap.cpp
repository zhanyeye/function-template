#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 1005;
const int M = 5005;

struct edge {
    int v, w, next;
    edge() {}
    edge(int _v, int _w, int _next):v(_v), w(_w), next(_next) {}
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

int dis[N];
bool vis[N];
int n, m;
typedef pair<int, int> PII;
set<PII, less<PII> > min_heap;


bool dijstra(int u) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    dis[u] = 0;
    min_heap.insert(make_pair(0, u));

    for (int i = 0; i < n; i++) {
        if (min_heap.size() == 0) {
            return false;
        }

        set<PII, less<PII> >::iterator it = min_heap.begin();
        int min_v = it->second;
        vis[min_v] = true;
        min_heap.erase(*it);

        for (int e = head[min_v]; e != -1; e = E[e].next) {
            int v = E[e].v;
            int w = E[e].w;
            if (!vis[v] && dis[min_v] + w < dis[v]) {
                min_heap.erase(make_pair(dis[v], v));
                dis[v] = dis[min_v] + w;
                min_heap.insert(make_pair(dis[v], v));
            }
        }
    }
    return true;
}


int main() {
    int a, b, c;
    cin >> n >> m;
    init();
    while (m--) {
        cin >> a >> b >> c;
        insert2(a, b, c);
    }
    dijstra(1); 
    cout << dis[n] << endl;
}