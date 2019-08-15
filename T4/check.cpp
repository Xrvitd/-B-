#include <bits/stdc++.h>
using namespace std;
const int N = 22 * 3;
const int M = 78 * 3;
struct edge {
    int v, next;
} e[M];
int cnt, head[N];
int n, m;
void add(int u, int v) {
    e[cnt] = {v, head[u]};
    head[u] = cnt++;
}
struct node {
    int u, v;
} g[M];
int tot;
double user[N];    //用户量
double rk[N];      //总人口
double dis[N][N];  //城市间距离
double volume[N];  //流量 GB/s
double dp[N];      //最终总流量
double dp2[N];
double ans_dp[N];
double ans_dp2[N];
int ans_pre[N];
int pre[N];
void dfs(int u, int fa, int uu, int vv) {
    dp[u] = 0;
    dp2[u] = 0;
    pre[u] = fa;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        if ((u == uu && v == vv) || (u == vv && v == uu)) continue;
        dfs(v, u, uu, vv);
        dp[u] += dp[v];
        dp2[u] += dp2[v];
    }
    dp[u] += volume[u];
    dp2[u] += user[u];
}
double f[1000005];
int Pre[1000005];
double solve(int u, double flow, bool display = false) {
    int fa = pre[u];
    if(display) fa = ans_pre[u];
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
    // cout << fa << "," << u << "," << flow << endl;
    if (display) cout << fa << "->" << u << '\t' << "dis: " << d << "\ttotal_flow: " << flow << '\t' << "fib1: " << ans[0] << "\tfib2: " << ans[1] << "\tfib3: " << ans[2] << "\ttotal_cost: " << f[mn] << endl;
    // cout << fa << ' ' << u << endl;
    return f[mn];
}
void read_data() {
    ifstream in;
    ////////////////////////////////////////////////////
    // 读入数据&建图
    in.open("volume.txt");
    for (int i = 1; i <= 21; ++i) in >> volume[i];
    in.close();

    in.open("rate.txt");
    for (int i = 1; i <= 21; ++i) rk[i] = 1;
    for (int i = 1; i <= 21; ++i) in >> user[i];
    in.close();

    in.open("dis.txt");
    for (int i = 1; i <= 21; ++i)
        for (int j = 1; j <= 21; ++j)
            in >> dis[i][j];
    in.close();

    in.open("graph.txt");
    in >> n >> m;
    bool vis[N][N];
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        in >> u >> v;
        if (vis[u][v] || vis[v][u]) continue;
        g[tot++] = {u, v};
        vis[u][v] = vis[v][u] = true;
        // add(u, v, dis[u][v]);
    }
    in.close();

    ////////////////////////////////////////////////////
}
int getCircle;
bool inStack[N];
vector<int> st;
void find_circle(int u, int fa) {
    inStack[u] = true;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        if (inStack[v]) {
            getCircle = v;
            st.push_back(u);
            return;
        }
        find_circle(v, u);
        if (getCircle > 0) {
            st.push_back(u);
            if (u == getCircle) getCircle = -2;
            return;
        }
        if (getCircle == -2) return;
    }
    inStack[u] = false;
}
int main() {
    read_data();
    bool vis[N][N];
    bool vis1[M];
    double mn = 3.04044e-6;
    for (int i = 0; i < tot; ++i) {
        ifstream in("out.txt");
        memset(vis, false, sizeof vis);
        memset(vis1, false, sizeof vis1);
        memset(head, -1, sizeof head);
        cnt = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            in >> u >> v;
            add(u, v);
            add(v, u);
            vis[u][v] = vis[v][u] = true;
        }
        in.close();

        int u = g[i].u;
        int v = g[i].v;
        if (vis[u][v] || vis[v][u]) continue;
        add(u, v);
        vis1[cnt - 1] = true;
        add(v, u);
        vis1[cnt - 1] = true;
        getCircle = -1;
        memset(inStack, false, sizeof inStack);
        st.clear();
        find_circle(1, 0);
        int sz = st.size();
        for (int j = 0; j < sz; ++j) {
            int uu = st[j];
            int vv = st[(j + 1) % sz];
            if ((uu == u && vv == v) || (uu == v && vv == u)) continue;
            memset(dp, 0, sizeof dp);
            memset(pre, 0, sizeof pre);
            dfs(1, 0, uu, vv);
            double ans = 0;
            for (int i = 2; i <= n; ++i) {
                ans += user[i] * user[pre[i]] * dp2[i] / solve(i, dp[i]);
            }
            // cout << ans << endl;
            if (mn < ans) {
                mn = ans;
                // cout << uu << ' ' << vv << ' ' << u << ' ' << v << endl;
                memcpy(ans_dp, dp, sizeof ans_dp);
                memcpy(ans_pre, pre, sizeof ans_pre);
                memcpy(ans_dp2, dp2, sizeof ans_dp2);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        // solve(i, ans_dp[i], true);
        cout << i << ',' << ans_pre[i] << ',' << ans_dp[i] << endl;
    }
    cout << mn << endl;
    return 0;
}