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

vector<ll> num;
map<ll, ll> mp;
ll len, n, q, nn[N], cnt[N], sum[N];

struct ope
{
    bool f;
    ll a, b;
} fff[N];

ll lowbit(ll x)
{
    return x & -x;
}

void add(ll i, ll x, ll *ssr)
{
    while(i <= len)
    {
        ssr[i] += x;
        i += lowbit(i);
    }
}

ll query(ll i, ll *ssr)
{
    ll res = 0;
    while(i)
    {
        res += ssr[i];
        i -= lowbit(i);
    }
    return res;
}

void solve()
{
    cin >> n >> q;
    run(i, 1, q)
    {
        char s[5];
        cin >> s;
        if(s[0] == 'U')
            fff[i].f = 1;
        else
            fff[i].f = 0;
        cin >> fff[i].a >> fff[i].b;
        num.push_back(fff[i].b);
    }
    sort(num.begin(), num.end());
    len = unique(num.begin(), num.end()) - num.begin();
    run(i, 0, len - 1)
    mp[num[i]] = i + 1;
    run(i, 1, q)
    {
        if(fff[i].f)
        {
            ll a = fff[i].a, b = fff[i].b;
            ll ssr = nn[a];
            if(ssr)
            {
                add(mp[ssr], -ssr, sum);
                add(mp[ssr], -1, cnt);
            }
            if(b)
            {
                add(mp[b], b, sum);
                add(mp[b], 1, cnt);
            }
            nn[a] = b;
        }
        else
        {
            ll a = fff[i].a, b = fff[i].b;
            ll ssr = query(len, cnt) - query(mp[b] - 1, cnt);
            if(ssr >= a)
            {
                cout << "TAK" << '\n';
                continue;
            }
            a -= ssr;
            ll sm = query(mp[b] - 1, sum);
            if(a * b > sm)
                cout << "NIE" << '\n';
            else
                cout << "TAK" << '\n';
        }
    }

}

int main() // https://www.luogu.com.cn/problem/P3586
{
    speed
//    t()
    solve();
    return 0;
}
