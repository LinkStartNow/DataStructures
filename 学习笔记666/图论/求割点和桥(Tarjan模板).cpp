#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;

const int N = 2e5 + 5;
int n, m, tot;
int head[N];
int low[N], dfn[N], num;
set<int> ans;
struct yyds
{
    int to, nxt;
} edge[N];

void Tarjan(int x, int root)
{
    int child = 0;
    low[x] = dfn[x] = ++ num;
    for(int i = head[x]; i; i = edge[i].nxt)
    {
        int to = edge[i].to;
        if(!low[to])
        {
            Tarjan(to, root);
            low[x] = min(low[x], low[to]);
            if(dfn[x] <= low[to] && x != root) // 求桥的话用<,割点用<=
                ans.insert(x);
            if(x == root)
                child ++;
        }
        else
            low[x] = min(low[x], dfn[to]);
    }
    if(child >= 2 && x == root) // 如果是根节点且有两个及以上的儿子则必定为割点
        ans.insert(x);
}
void add(int u, int v)
{
    edge[++ tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
int main()
{
    scanf("%d%d", &n, &m);
    run(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    run(i, 1, n)
    if(!dfn[i])
        Tarjan(i, i);
    printf("%d\n", (int)ans.size());
    for(auto it = ans.begin(); it != ans.end(); it ++)
        printf("%d\n", *it);
}
