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
const int N = 207;
int n, m, mat[N];
bool vis[N], mp[N][N];

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

bool zly(int u)
{
    run(i, 1, n)
    {
        if(!mp[u][i])
            continue;
        if(vis[i])
            continue;
        vis[i] = 1;
        if(!mat[i] || zly(mat[i]))
        {
            mat[i] = u;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    int ans = n;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
    }
    run(i, 1, n)
        run(j, 1, n)
            run(k, 1, n)
                if(mp[j][i] && mp[i][k])
                    mp[j][k] = 1;
    run(i, 1, n)
    {
        ms(vis);
        if(zly(i))
            ans --;
    }
    cout << ans << '\n';
}
int main() //https://ac.nowcoder.com/acm/contest/1063/D
{
    speed
//    t()
    solve();
    return 0;
}
