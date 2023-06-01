#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 1e6 + 7;
ll a[N], pos[N], ans[N], p = 1, t[N];
int n, q;

struct query
{
    int l, r, id;
    bool operator<(const query &b) const
    {
        return r < b.r;
    }
} ask[N];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int v)
{
    while(x <= n)
    {
        t[x] += v;
        x += lowbit(x);
    }
}

int qq(int x)
{
    int res = 0;
    while(x)
    {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}

void solve()
{
    cin >> n;
    run(i, 1, n)
        cin >> a[i];
    cin >> q;
    run(i, 1, q)
        cin >> ask[i].l >> ask[i].r, ask[i].id = i;
    sort(ask + 1, ask + 1 + q);
    run(i, 1, q)
    {
        run(j, p, ask[i].r)
        {
            if(pos[a[j]])
                add(pos[a[j]], -1);
            add(j, 1);
            pos[a[j]] = j;
        }
        p = ask[i].r + 1;
        ans[ask[i].id] = qq(ask[i].r) - qq(ask[i].l - 1);
    }
    run(i, 1, q)
        cout << ans[i] << '\n';
}

int main() // https://www.luogu.com.cn/problem/P1972
{
    speed
//    t()
    solve();
    return 0;
}
