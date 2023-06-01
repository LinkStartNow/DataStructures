#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int N = 1e6 + 7;
int f[N << 1];
vector<int> num;
map<int, int> ssr;

int fa(int x)
{
    return x == f[x] ? x : f[x] = fa(f[x]);
}

struct zly
{
    int a, b;
    bool k;
    bool operator<(const zly &b) const
    {
        return k > b.k;
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

void li()
{
    sort(num.begin(), num.end());
    int ss = unique(num.begin(), num.end()) - num.begin() - 1;
    run(i, 0, ss)
    ssr[num[i]] = i + 1;
}

void solve()
{
    int n, a, b, k;
    bool fl = 1;
    cin >> n;
    num.clear(), ssr.clear();
    run(i, 1, n)
    {
        cin >> yi[i].a >> yi[i].b >> yi[i].k;
        num.push_back(yi[i].a);
        num.push_back(yi[i].b);
    }
    li();
    run(i, 1, n << 1)
    f[i] = i;
    sort(yi + 1, yi + 1 + n);
    run(i, 1, n)
    {
        a = ssr[yi[i].a], b = ssr[yi[i].b], k = yi[i].k;
        int x = fa(a), y = fa(b);
        if(k)
        {
            if(x != y)
                f[x] = y;
        }
        else
        {
            if(x == y)
            {
                fl = 0;
                break;
            }
        }
    }
    if(fl)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main() // https://www.luogu.com.cn/problem/P1955
{
    speed
    t()
    solve();
    return 0;
}
