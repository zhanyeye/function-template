#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000;
const int M = 10000;
const int INF = 0x3f3f3f3f;

//基于链表的邻接表
struct edge {
    int v;  //顶点
    int w;  //权值
    int next;  //指向head[i] 所链接的链表，表示v 和 i 相邻
    edge() {}
    edge(int _v, int _w, int _next): v(_v), w(_w), next(_next) {}
} E[M];

int head[N];  // head数组的每一个元素代表链表的头指针
int cnt; //边的数量

void init() {
    memset(head, -1, sizeof head);  // 初始化时，每个链表都没有元素，初始化为空，即：-1
    cnt = 0;
}

void insert(int u, int v, int w) {
    E[cnt] = edge(v, w, head[u]);
    head[u] = cnt;  // 更新链表的头指针
    cnt++;  // 结点计数器 +1
}

void insert2(int u, int v, int w) {
    insert(u, v, w);
    insert(v, u, w);
}

int n, m;
int dis[N];   // 标记点到 u 的距离
bool vis[N];  // 标记一个点有没有被加入已确定最小值集合


void dijkstra(int u) {
    memset(dis, 0x3f, sizeof dis);  //将所有定点到u的距离值 无穷大
    memset(vis, false, sizeof vis);
    dis[u] = 0;  // u点到自己距离为0


    // 循环 n 次，每次确定一个dis 最小的点，2种可能
    // 循环 n 次，最终到所有点的最小值都确定
    // 没有循环 n 次，该图非连通图 
    for (int i = 0; i < n; i++) {
        int min_dis = INF, min_index = -1;
        // 找点集中 dis 最小的一个，将该点加入已确定最小值集合
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && min_dis > dis[j]) {
                min_dis = dis[j];
                min_index = j;
            }
        }
        if (min_index == -1) { //未确定点集中，顶点的min dis 是 无穷大， 该图非连通图
            return;
        }
        vis[min_index] = true;
        for (int e = head[min_index]; ~e; e = E[e].next) { //注意这里e是插入序号, 而不是点
            int v = E[e].v;
            int w = E[e].w;
            if (!vis[v] && dis[v] > min_dis + w) {
                dis[v] = min_dis + w;
            }
        }
    }
}

int main() {
    init();
    int u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        insert2(u, v, w);
    }
    dijkstra(1);
    cout << dis[n] << endl;

    return 0;
}