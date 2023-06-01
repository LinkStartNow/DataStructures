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
const int N = 1007;
int n, m, k;
vector<int> e[N];
bool vis[N];
int mat[N];

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
    for(auto v : e[u])
    {
        if(vis[v])
            continue;
        vis[v] = 1;
        if(!mat[v] || zly(mat[v]))
        {
            mat[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() /* 实际是求二分图的最小点覆盖， 而最小点覆盖在数值上等于最大匹配数 */
{
    while(cin >> n)
    {
        if(!n)
            break;
        cin >> m >> k;
        ms(e);
        ms(mat);
        while(k --)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if(!b || !c)
                continue;
            e[b].push_back(c);
        }
        int ans = 0;
        run(i, 1, n)
        {
            ms(vis);
            if(zly(i))
                ans ++;
        }
        cout << ans << '\n';
    }
}
int main() //https://ac.nowcoder.com/acm/contest/1063/A
{
    speed
//    t()
    solve();
    return 0;
}
