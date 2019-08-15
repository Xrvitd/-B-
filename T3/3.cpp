#include <bits/stdc++.h>
using namespace std;
const int N = 22 * 3;
const int M = 78 * 3;
struct edge {
    int to, next;
    double cost;
} e[M], e1[M];
int cnt, head[N], cnt1, head1[N];
int n, m;
inline void add(int u, int v, double w) {
    e[cnt] = {v, head[u], w};
    head[u] = cnt++;
}
inline void add1(int u, int v, double w = 0) {
    e1[cnt1] = {v, head1[u], w};
    head1[u] = cnt1++;
}
double user[N];    //用户量
double rk[N];      //总人口
double dis[N][N];  //城市间距离
double volume[N];  //流量 GB/s
double dp[N];      //最终总流量
double dp2[N];
int pre[N];
void dfs(int u, int fa) {
    // cout << u << endl;
    dp[u] = 0;
    dp2[u] = 0;
    pre[u] = fa;
    for (int i = head1[u]; ~i; i = e1[i].next) {
        int v = e1[i].to;
        if (v == fa) continue;
        dfs(v, u);
        dp[u] += dp[v];
        dp2[u] += dp2[v];
    }
    dp[u] += volume[u];
    dp2[u] += user[u];
}
double f[1000005];
int Pre[1000005];
double solve(int u, double flow) {
    int fa = pre[u];
    double d = dis[fa][u];
    struct firber {
        double max_dis, max_flow, cost;
    } fib[3] = {{200, 4 * 1024, 1}, {100, 6 * 1024, 1.25}, {80, 8 * 1024, 1.5}};
    for (int i = 0; i <= (int)flow * 20; ++i) {
        f[i] = 1e18, Pre[i] = 0;
        // cout << i << ' ';
    }
    // cout << endl;
    f[0] = 0;
    Pre[0] = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = fib[i].max_flow; j <= int(20 * flow); ++j) {
            // cout << j << endl;
            if (f[j] > f[j - (int)fib[i].max_flow] + fib[i].cost * d) {
                f[j] = f[j - (int)fib[i].max_flow] + fib[i].cost * d;
                Pre[j] = j - fib[i].max_flow;
            }
        }
    }
    int mn = -1;
    for (int i = int(flow + 0.5); i <= (int)flow * 20; ++i) {
        if (mn == -1 || f[mn] > f[i]) {
            mn = i;
        }
    }
    int x = mn;
    int ans[3] = {0};
    while (true) {
        if (Pre[x] == -1) break;
        if (x - Pre[x] == 4 * 1024)
            ans[0]++;
        else if (x - Pre[x] == 6 * 1024)
            ans[1]++;
        else
            ans[2]++;
        x = Pre[x];
    }
    // cout << fa << ' ' << u << endl;
    // cout << fa << "->" << u << '\t' << "dis: " << d << "\ttotal_flow: " << flow << '\t' << "fib1: " << ans[0] << "\tfib2: " << ans[1] << "\tfib3: " << ans[2] << "\ttotal_cost: " << f[mn] << endl;
    cout << fa << ',' << u << ',' << flow << endl;
    return f[mn];
}
void bfs(int S) {
    struct node {
        int id, d, pre;
    } st[N];
    struct heap {
        node u;
        int v;
        double pro;
        bool operator<(const heap& t) const { return pro < t.pro; }
    };
    bool vis[N];
    memset(vis, false, sizeof vis);
    memset(head1, -1, sizeof head1);
    std::deque<node> q;
    q.push_back({S, 0, 0});
    while (!q.empty()) {
        int tot = 0;
        int cur = 0;
        // 提出所有同一深度的节点
        do {
            node uu = q.front();
            cur = uu.d;
            st[tot++] = uu;
            q.pop_front();
            // cout << q.size() << endl;
        } while (!q.empty() && cur == q.front().d);
        priority_queue<heap> qq;
        // 计算边权并加入大根堆
        for (int k = 0; k < tot; ++k) {
            node uu = st[k];
            int u = uu.id;
            for (int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].to;
                if (vis[v] || v == uu.pre) continue;
                double pro = sqrt(1.0 * user[u] * user[v]) / (user[u] + user[v]) / (dis[u][v] * volume[v]);
                qq.push({uu, v, pro});
            }
        }
        // 从大到小贪心挑边扩展
        while (!qq.empty()) {
            heap uu = qq.top();
            qq.pop();
            if (vis[uu.v]) continue;
            // cout << uu.v << endl;
            q.push_back({uu.v, uu.u.d + 1, uu.u.id});
            vis[uu.v] = true;
            add1(uu.u.id, uu.v);
            add1(uu.v, uu.u.id);
            // cout << cnt1 << endl;
            // cout << uu.u.id << ' ' << uu.v << endl;
        }
        // cout << q.size() << endl;
    }
    // 计算总流量
    dfs(8, 0);
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 8) continue;
        ans += user[i] * user[pre[i]] * dp2[i] / solve(i, dp[i]);
    }
    cout << ans << endl;
}
void read_data() {
    ifstream in;
    // //////////////////////////////////////////////////
    // // 读入数据&建图
    // in.open("volume.txt");
    // for (int i = 1; i <= 21; ++i) in >> volume[i];
    // in.close();

    // in.open("rate.txt");
    // for (int i = 1; i <= 21; ++i) rk[i] = 1;
    // for (int i = 1; i <= 21; ++i) in >> user[i];
    // in.close();

    // in.open("dis.txt");
    // for (int i = 1; i <= 21; ++i)
    //     for (int j = 1; j <= 21; ++j)
    //         in >> dis[i][j];
    // in.close();

    // in.open("graph.txt");
    // in >> n >> m;
    // for (int i = 1; i <= m; ++i) {
    //     int u, v;
    //     in >> u >> v;
    //     add(u, v, dis[u][v]);
    // }
    // in.close();
    // //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    // 随机化
    // 读入数据&建图
    in.open("randomV.txt");
    for (int i = 1; i <= 21; ++i) in >> volume[i];
    in.close();

    in.open("randomR.txt");
    for (int i = 1; i <= 21; ++i) rk[i] = 1;
    for (int i = 1; i <= 21; ++i) {
        in >> user[i];
    }
    in.close();

    in.open("randomD.txt");
    for (int i = 1; i <= 21; ++i)
        for (int j = 1; j <= 21; ++j)
            in >> dis[i][j];
    in.close();

    in.open("randomP.txt");
    in >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        in >> u >> v;
        add(u, v, dis[u][v]);
    }
    in.close();
    /////////////////////////////////////////
}
int main() {
    auto start = clock();
    memset(head, -1, sizeof head);
    read_data();
    bfs(8);
    auto end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
