#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
#define m(l, r) mid = (l + r) >> 1
using namespace std;
const int N = 500010;
int n, m, s;
int tot, head[N], edge[2 * N], nxt[2 * N];
int top[N], son[N], siz[N], dep[N], fa[N];
void add(int u, int v)
{
    edge[++ tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void da(int s, int f)
{
    siz[s] = 1;
    dep[s] = dep[f] + 1;
    fa[s] = f;
    for(int i = head[s]; i; i = nxt[i])
    {
        int to = edge[i];
        if(to == f)
            continue;
        da(to, s);
        siz[s] += siz[to];
        if(siz[son[s]] < siz[to])
            son[s] = to;
    }
}
void db(int s, int f)
{
    top[s] = f;
    if(!son[s])
        return;
    db(son[s], f);
    for(int i = head[s]; i; i = nxt[i])
    {
        int to = edge[i];
        if(to == fa[s] || to == son[s])
            continue;
        db(to, to);
    }
}
int lca(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    if(dep[x] > dep[y])
        return y;
    return x;
}
int main()
{
    int u, v;
    cin >> n >> m >> s;
    run(i, 1, n - 1)
    {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    da(s, s), db(s, s);
    run(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
