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

const int N = 2e6 + 7;
int ans = N;
int n, d;
int mi[N], ma[N], lx, rx = -1, ln, rn = -1;

struct zly
{
    int x, y;
    bool operator<(const zly &b)const
    {
        if(x == b.x)
            return y < b.y;
        return x < b.x;
    }
} yi[N];

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

void solve()
{
    cin >> n >> d;
    run(i, 1, n)
    cin >> yi[i].x >> yi[i].y;
    sort(yi + 1, yi + 1 + n);
    int l = 1;
    run(i, 1, n)
    {
        while(lx <= rx && yi[i].y > yi[ma[rx]].y) rx --;
        ma[++ rx] = i;
        while(ln <= rn && yi[i].y < yi[mi[rn]].y) rn --;
        mi[++ rn] = i;
        while(l <= i && yi[ma[lx]].y - yi[mi[ln]].y >= d)
        {
            ans = min(ans, yi[i].x - yi[l].x);
            l ++;
            while(ln <= rn && mi[ln] < l) ln ++;
            while(lx <= rx && ma[lx] < l) lx ++;
        }
    }
    printf("%d\n", ans == N ? -1 : ans);
}

int main() // https://www.luogu.com.cn/problem/P2698
{
    speed
//    t()
    solve();
    return 0;
}
