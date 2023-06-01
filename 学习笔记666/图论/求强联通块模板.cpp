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

const int N = 1e6 + 5;
int n, m;
vector<int> mp[N], mp2[N], fan;
int num, group[N];
bool vis[N];

void dfs(int x)
{
    vis[x] = 1;
    for(int i = 0; i < mp[x].size(); i ++)
        if(!vis[mp[x][i]])
            dfs(mp[x][i]);
    fan.push_back(x);
}

void dfs2(int x)
{
    vis[x] = 1;
    group[x] = num;
    for(int i = 0; i < mp2[x].size(); i ++)
        if(!vis[mp2[x][i]])
            dfs2(mp2[x][i]);
}
int main()
{
    scanf("%d%d", &n, &m);
    run(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        mp[u].push_back(v);
        mp2[v].push_back(u);
    }
    run(i, 1, n)
        if(!vis[i])
            dfs(i);
    ms(vis);
    for(int i = fan.size() - 1; i >= 0; i --)
        if(!vis[fan[i]])
            num ++, dfs2(fan[i]);
    ms(vis);
    int sum = 0;
    int st;
    run(i, 1, n)
        if(group[i] == num)
            st = i, sum ++;
    dfs2(st);
    run(i, 1, n)
        if(!vis[i])
        {
            puts("0");
            return 0;
        }
    printf("%d", sum);
}
