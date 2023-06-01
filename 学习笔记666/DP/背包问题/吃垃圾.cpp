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

const ll N = 3e3 + 7;
ll dp[N], ans;

struct rubbish
{
    ll t, f, h;
    bool operator<(const rubbish &b) const
    {
        return t < b.t;
    }
};

vector<rubbish> lj;

void solve()
{
    int d, g;
    cin >> d >> g;
    run(i, 1, g)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        lj.push_back({a, b, c});
    }
    sort(lj.begin(), lj.end());
    dp[0] = 10;
    for(auto v : lj)
    {
        rep(i, 100, 0)
        {
            if(dp[i] >= v.t)
            {
                dp[i + v.h] = max(dp[i + v.h], dp[i]);
                dp[i] += v.f;
                if(i + v.h >= d)
                {
                    cout << v.t << '\n';
                    return;
                }
            }
        }
    }
    cout << dp[0];
}

int main() // https://www.luogu.com.cn/problem/P1156
{
    speed
//    t()
    solve();
    return 0;
}
