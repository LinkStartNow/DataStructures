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
const int N = 4e6 + 5;
int n, m;
vector<int> mp[N];
int dfn[N], low[N];
int group[N], tot, cnt;
bool vis[N];
stack<int> s;
void Tarjan(int u)
{
    dfn[u] = low[u] = ++ cnt;
    vis[u] = 1;
    s.push(u);
    for(int i = 0; i < mp[u].size(); i ++)
    {
        int v = mp[u][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        vis[u] = 0;
        group[u] = ++ tot;
        while(s.top() != u)
        {
            int son = s.top();
            vis[son] = 0;
            s.pop();
            group[son] = tot;
        }
        s.pop();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    run(i, 1, m)
    {
        int a, va, b, vb;
        scanf("%d%d%d%d", &a, &va, &b, &vb);
        mp[a + n * (va & 1)].push_back(b + n * (vb ^ 1));
        mp[b + n * (vb & 1)].push_back(a + n * (va ^ 1));
    }
    run(i, 1, 2 * n)
        if(!dfn[i])
            Tarjan(i);
    run(i, 1, n)
    if(group[i] == group[i + n])
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    puts("POSSIBLE");
    run(i, 1, n)
        if(group[i] < group[i + n])
            printf("1 ");
        else
            printf("0 ");
}
