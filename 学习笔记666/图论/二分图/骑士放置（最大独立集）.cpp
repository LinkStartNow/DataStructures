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
const int N = 107;
int n, m, k;
bool vis[N][N], g[N][N];
pss mat[N][N];
int nx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int ny[8] = {2, -2, 1, -1, 2, -2, 1, -1};

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

bool zly(int x, int y)
{
    run(i, 0, 7)
    {
        int xx = x + nx[i], yy = y + ny[i];
        if(xx > n || xx < 1 || yy > m || yy < 1 || g[xx][yy] || vis[xx][yy])
            continue;
        vis[xx][yy] = 1;
        if(!mat[xx][yy].first || zly(mat[xx][yy].first, mat[xx][yy].second))
        {
            mat[xx][yy] = {x, y}; // pair的赋值， 同样可以用make_pair(x, y)代替
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m >> k;
    int ans = m * n - k;
    while(k --)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    run(i, 1, n)
        run(j, 1, m)
        {
            ms(vis);
            if(!g[i][j] && (i + j) & 1 && zly(i, j))
                ans --;
        }
    cout << ans << '\n';
}
int main() //https://ac.nowcoder.com/acm/contest/1063/C
{
    speed
//    t()
    solve();
    return 0;
}
