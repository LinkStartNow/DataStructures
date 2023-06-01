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

const int N = 2e6 + 7;
int n, c, q, ans[N], pos = 1, tr[N], co[N], show1[N], show2[N];

ll lowbit(ll x)
{
    return x & -x;
}

void add(int i, int x)
{
    while(i <= n)
    {
        tr[i] += x;
        i += lowbit(i);
    }
}

int qq(int i)
{
    int res = 0;
    while(i)
    {
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}

struct query
{
    int l, r, i;
    bool operator<(const query &b)const
    {
        return r < b.r;
    }
} ask[N];

void solve()
{
    cin >> n >> c >> q;
    run(i, 1, n)
        cin >> co[i];
    run(i, 1, q)
        cin >> ask[i].l >> ask[i].r, ask[i].i = i;
    sort(ask + 1, ask + 1 + q);
    run(i, 1, q)
    {
        run(j, pos, ask[i].r)
        {
            if(!show1[co[j]])
            {
                show1[co[j]] = j;
                continue;
            }
            if(!show2[co[j]])
            {
                show2[co[j]] = j;
                add(show1[co[j]], 1);
                continue;
            }
            add(show1[co[j]], -1);
            show1[co[j]] = show2[co[j]];
            add(show1[co[j]], 1);
            show2[co[j]] = j;
        }
        pos = ask[i].r + 1;
        ans[ask[i].i] = qq(ask[i].r) - qq(ask[i].l - 1);
    }
    run(i, 1, q)
        cout << ans[i] << '\n';
}

int main() // https://www.luogu.com.cn/problem/P4113
{
    speed
//    t()
    solve();
    return 0;
}
