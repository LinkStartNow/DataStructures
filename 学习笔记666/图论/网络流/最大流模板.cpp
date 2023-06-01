#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e4 + 7;
int n, m, s, t;
int deep[N];
ll ans;

struct edge
{
    int to, nx, flow; // flow是边的最大容量
} e[N];

int head[N], tot = 1, no[N];

void add(int x, int y, int w)
{
    e[++ tot] = {y, head[x], w};
    head[x] = tot;
}

bool bfs()
{
    run(i, 1, n)
    deep[i] = i == s; // 初始化深度，出发点的深度为1，其他点初始为0表示还未遍历到
    queue<int> q;
    q.push(s);
    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        no[u] = head[u]; // 这里的no数组很神奇，假如是第一个能到达终点的节点，那么就在下面return 1了
        // 于是同为能到达终点的最后一批节点都没有no值，因此每一轮更新只会更新一条增广路径
        for(int i = head[u]; i; i = e[i].nx)
        {
            v = e[i].to;
            if(deep[v] || !e[i].flow) // 因为要用deo记录层数，所以已经拜访完了就不要再继续了
                // 如果已经没有残余容量了说明此路不通。
                continue;
            deep[v] = deep[u] + 1;
            q.push(v);
            if(v == t) // 存在某条从s到t的路径可以流通说明存在增广路径
                return 1;
        }
    }
    return 0;
}

int dfs(int u, int guess)
{
    if(u == t) // 只要能流到终点便可以流，故可以假设终点可以流向一个能接受无限流量的点
        return guess; // 于是可以直接返回猜测值，即把能留到终点的流量记录下来
    int v, flow = 0, back = 0; // back表示当前节点能流出多少流量，用于最后的返回
    for(int i = no[u]; i && guess - back; i = e[i].nx)
    {
        no[u] = i; // 弧优化，避免多次访问已用边
        // 每次访问到一个新点便更新no数组，因为能更新到这个节点必然是因为前面几个节点的容量全被用完了
        // 不然则会因为u节点流出量不够而提早退出，便不会再访问到目前的节点了
        v = e[i].to;
        if(deep[v] == deep[u] + 1 && e[i].flow)
        {
            flow = dfs(v, min(e[i].flow, guess - back));
            e[i].flow -= flow;
            e[i ^ 1].flow += flow;
            back += flow;
        }
        // 关于上面为什么只去更新deep + 1的点：
            // dep之差大于1：
                // 深度之差大于1的点很显然根本不能直接到达，所以不能更新

            // dep小1：
                // 因为考虑到反悔回流的情况，所以建图的时候就建立了双向边，所以每条边都是成对的，所以肯定会存在指向dep-1的点
                // 如果比当前点的深度还小1属于回流，遍历到后期自然深度就交换变成大1了，到时候便会判断这种回流的情况，在这里提前处理不仅多此一举，而且容易死循环

            // dep相等：
                // 因为深度相等所以另外一个点肯定也是由当前节点的父节点直接可以到达的，也可以理解为父节点播给那个节点的经费都还没用完，当前节点不用着急提前资助他
                // 如果父节点到那个节点的容量大于那个节点所有能流出的容量那之后访问到该节点肯定dep不会变更深，也就是说当前节点没有机会更新到他
                // 如果父节点给的经费不够用了可以理解为父节点不能直接到达那个节点，此时当前节点在被父节点赋予dep时就可以在之后遍历到那个节点并让它的dep变得比当前的dep大1，也就是可以更新资助他了
    }
    return back;
}

void dinic()
{
    while(bfs())
        ans += dfs(s, 0x7f7f7f); // 因为源头可以无限流出所以假定源头的流量为一个极大值
}

void solve()
{
    cin >> n >> m >> s >> t;
    run(i, 1, m)
    {
        int u, v, f;
        cin >> u >> v >> f;
        add(u, v, f);
        add(v, u, 0);
    }
    dinic();
    cout << ans << endl;
}

int main() // https://www.luogu.com.cn/problem/P3376
{
    speed
//    t()
    solve();
    return 0;
}