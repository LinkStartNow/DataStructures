#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n,d[N],m,s,f[N][30],t,head[N],tot,u,v;
struct egde
{
    int to,nt;
} edge[2*N];
int lca(int u,int v)
{
    if(d[u]<d[v])
        swap(u,v);
    for(int i = t; i >= 0; i --)
        if(d[f[u][i]] >= d[v])
            u = f[u][i];
    if(u == v)
        return u;
    for(int i = t; i >= 0; i --)
        if(f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    return f[u][0];
}
void dfs(int x,int fa)
{
    d[x] = d[fa] + 1;
    for(int i = 1; i <= t; i ++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for(int i = head[x]; i; i = edge[i].nt)
    {
        int y = edge[i].to;
        if(y != fa)
        {
            f[y][0] = x;
            dfs(y,x);
        }
    }
}
void add(int u,int v)
{
    tot++;
    edge[tot].to = v;
    edge[tot].nt = head[u];
    head[u] = tot;
}
int main()
{
    f[0][0] = 0;
    f[s][0] = 0;
    d[0] = 0;
    scanf("%d%d%d",&n,&m,&s);
    t = log(n) / log(2) + 1;
    for(int i = 1; i < n; i ++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(s,0);
    while(m --)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}
