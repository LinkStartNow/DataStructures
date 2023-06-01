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
int n, m;
bool fail[N][N], vis[N][N];
pair<int, int> mat[N][N];
int nx[4] = {0, 1, -1, 0}, ny[4] = {1, 0, 0, -1};

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
    run(i, 0, 3)
    {
        int a = x + nx[i], b = y + ny[i];
        if(vis[a][b] || a < 1 || a > n || b < 1 || b > n || fail[a][b])
            continue;
        vis[a][b] = 1;
        if(!mat[a][b].first || zly(mat[a][b].first, mat[a][b].second)) //只用判断一个坐标是否为0便可以看出是否匹配过
        {
            mat[a][b].first = x, mat[a][b].second = y;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        fail[a][b] = 1;
    }
    int ans = 0;
    run(i, 1, n)
        run(j, 1, n)
        {
            if((i + j) % 2 == 0)
                continue;
            ms(vis);
            if(!fail[i][j])
                if(zly(i, j))
                    ans ++;
        }
    cout << ans << '\n';
}
int main() //https://ac.nowcoder.com/acm/contest/1062/B
{
    speed
//    t()
    solve();
    return 0;
}
