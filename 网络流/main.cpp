//设x等于
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;
const int INF = 1061109567;
const int INC = 30;
const int INN = 30;
int n,m;
int need[5001];
int maxData = 0x7fffffff; 
queue<int> dl;
int head[50001],cost[10001],net[10001],to[10001],cap[10001];//cost为费用数组，cap为容量

int cnt=1;
void add(int x,int y,int c,int z)
{
    to[++cnt]=y;
    cost[cnt]=z;
    cap[cnt]=c;
    net[cnt]=head[x];
    head[x]=cnt;
    // cout<<x<<' '<<y<<' '<<cnt<<endl;
}
int flow[5001];
int pre[5001];//前驱节点
int xb[5001];//记录下标，便于修改容量
 int mflow=0;//最大流
ll mcost=0;//最小费用
ll dis[5001];//记录从源点到当前节点的最小的费用值，学过最小路的都懂
int f[5001];//标记是否在队列中
int BFS(int s,int t)
{
    memset(dis,0x7f,sizeof(dis));//赋初值最大值
    memset(f,0,sizeof(f));//赋值为0
    while(!dl.empty()) dl.pop();
    for(int i=1;i<=n;i++)
     pre[i]=-1;//清空前驱节点
    f[s]=1;
    dis[s]=0;
    pre[s]=0;
    flow[s]=maxData;
    dl.push(s);
    while(!dl.empty())
    {
        int dd=dl.front();
        dl.pop();
        f[dd]=0;
         for(int i=head[dd];i;i=net[i])
        {
            int tmp=to[i];
            if(cap[i]>0&&dis[tmp]>dis[dd]+cost[i])//松弛操作
            {
                dis[tmp]=dis[dd]+cost[i];
                pre[tmp]=dd;
                xb[tmp]=i;
                flow[tmp]=min(flow[dd],cap[i]);
                if(!f[tmp]) f[tmp]=1,dl.push(tmp);
            }
        }
    }
    if(dis[t]>=INF) return 0;//成功找到了增广路
    return 1;
}

void max_flow(int s,int t, int ff)
{
    while((ff>0) && (BFS(s,t)))
    { 
        int k=t;
        while(k!=s)
         {
             cap[xb[k]]-=flow[t];
             cap[xb[k]^1]+=flow[t];
             k=pre[k];
         } 
        ff-=flow[t];
        mcost+=flow[t]*dis[t];//流量乘以最小单位流量的费用即为最小费用
    }
}

int xx[100],yy[100];
double dd[100];
int edge[100][100];
double len[100][100];

int main()
{
    freopen("dis.in","r",stdin);
    for (int i=1; i<=21; i++)
        for (int j=1; j<=21; j++)
            cin>>len[i][j];

    freopen("1.in","r",stdin);
    int s,t,x,y;
    scanf("%d",&n);
    s = 100;
    t = 1;
    double xp;
    int sum = 0;
    for (int i = 2; i<=21; i++) {
        cin>>xp;   //信息需求量
        int pp = xp;
        if (pp%200 == 0) need[i] = pp/200;
        else need[i] = pp/200 + 1;
        sum+=need[i];
    }

    for (int i=2; i<=21; i++) {
        add(s, i, INC, 0),add(i, s, 0, 0);
    }
    for (int i=2; i<=21; i++) {
        add(i, i+20, need[i], 0),add(i+20, i, 0, 0);
    }

    // cout<<"cntL " <<cnt<<endl;
    m = 68;
    // 令X=240，单位传输量为200GB/s
    for (int i = 1; i<=m; i++) {
        cin>>xx[i]>>yy[i];            //建边

        x = xx[i];
        y = yy[i];
        int lp = len[xx[i]][yy[i]];  
        ll cost = 90 * lp;

        if (xx[i]==1) {
            add(yy[i]+20, 1, INC, cost);
            add(1, yy[i]+20, 0, -cost);
            continue;
        }
        else if (yy[i]==1) {
            add(xx[i]+20, 1, INC, cost);
            add(1, xx[i]+20, 0, -cost);
            continue;
        }

        add(x+20, y+20, INN, cost);
        add(y+20, x+20, 0, -cost);
        add(y+20, x+20, INN, cost);
        add(x+20, y+20, 0, -cost);
    }

    max_flow(s,t,sum); //输出最大流与最小费用

    // for (int i=82; i<=182; i++) cout<<cap[i]<<endl;
   
    memset(edge, 0, sizeof(edge));

    int ppx=81;

    for (int i=1; i<=m; i++){   
        if ((xx[i]==1) || (yy[i]==1)){
        	if (yy[i]==1) edge[xx[i]][1] += INC - cap[++ppx];
            else edge[yy[i]][1] += INC - cap[++ppx];
            ppx++;
            continue;
        }
        edge[xx[i]][yy[i]] =  INN - cap[++ppx];
        ppx++;             
        edge[yy[i]][xx[i]] =  INN - cap[++ppx];
        ppx++;
    }

    // for (int i=1; i<21; i++) 
    //     for (int j=i+1; j<=21; j++) 
    //         edge[i][j] += edge[j][i];

    int sum1 = 0;

    for (int i=1; i<=21; i++)
        for (int j=1; j<=21; j++) 
            {
                if (edge[i][j]>0) cout<<i<<' '<<j<<' '<<edge[i][j]<<' '<<endl;
                sum1 += edge[i][j];
            }

            cout<<endl;

    return 0;
}