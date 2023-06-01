#include<bits/stdc++.h>

#define ll long long
//#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 4e5 + 7;

int n, s, t;
ll ans = 0;
int dep[N];

struct edge
{
    int to, nx, c;
} e[N];

int head[N], tot = 1, now[N];

void add(int u, int v, int c)
{
    e[++ tot] = {v, head[u], c};
    head[u] = tot;
}

bool bfs()
{
    run(i, 0, n) dep[i] = i == s;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        now[p] = head[p];
        for(int i = head[p]; i; i = e[i].nx)
        {
            int to = e[i].to;
            if(dep[to] || !e[i].c)
                continue;
            dep[to] = dep[p] + 1;
            q.push(to);
            if(to == t)
                return 1;
        }
    }
    return 0;
}

int dfs(int u, int guess)
{
    if(u == t)
        return guess;
    int res = 0, flow;
    for(int i = now[u]; i && guess - res; i = e[i].nx)
    {
        now[u] = i;
        int to = e[i].to;
        if(dep[to] == dep[u] + 1 && e[i].c)
        {
            flow = dfs(to, min(guess - res, e[i].c));
            e[i].c -= flow, e[i ^ 1].c += flow;
            res += flow;
        }
    }
    return res;
}

void dinic()
{
    while(bfs())
        ans += dfs(s, 1e9);
}

void zly(int s, int f)
{
    bool x = 0; // �ж��Ƿ��ܼ������£����ж��Ƿ���Ҷ�ӽڵ�
    for(int i = head[s]; i; i = e[i].nx)
    {
        int to = e[i].to;
        if(to == f)
            continue;
        x = 1;
        zly(to, s);
    }
    if(!x) // Ҷ�ӽڵ������������յ�0
        add(s, 0, 1e9), add(0, s, 1e9); // �����ǹ�������ĵ㣬����Ҫ����������
        // Ҳ�ÿ�˫�򣬲�Ȼ����һ�����ż�жϳ����ķ����
}

void solve()
{
    cin >> n >> s;
    run(i, 1, n - 1)
    {
        int u, v, f;
        cin >> u >> v >> f;
        add(u, v, f), add(v, u, f); // ��������ͼ��˫���������Ϊf
    }
    zly(s, s); // dfs����Ҷ�ӽڵ�
    dinic(); // ��ͨ��dinic
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P3931
{
    speed
//    t()
    solve();
    return 0;
}
