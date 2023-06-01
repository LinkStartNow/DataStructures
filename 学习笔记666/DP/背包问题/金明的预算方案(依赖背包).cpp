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

const ll N = 4e4 + 7;
int l[N], r[N], imp[N], cs[N];
ll dp[N];
ll n, q;

vector<int> v;

void DP()
{
    for(auto x : v)
    {
        rep(i, n, 0)
        {
            if(i < cs[x])
                break;
            int ls = l[x], rs = r[x];
            ll vx = cs[x] * imp[x], vl = cs[ls] * imp[ls], vr = cs[rs] * imp[rs];
            if(i >= cs[x] + cs[ls] + cs[rs])
                dp[i] = max(dp[i], dp[i - cs[x] - cs[ls] - cs[rs]] + vx + vl + vr);
            if(i >= cs[x] + cs[ls])
                dp[i] = max(dp[i], dp[i - cs[x] - cs[ls]] + vx + vl);
            if(i >= cs[x] + cs[rs])
                dp[i] = max(dp[i], dp[i - cs[x] - cs[rs]] + vx + vr);
            if(i >= cs[x])
                dp[i] = max(dp[i], dp[i - cs[x]] + vx);
        }
    }
}

void solve()
{
    cin >> n >> q;
    run(i, 1, q)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(!c)
            v.push_back(i);
        else if(!l[c])
            l[c] = i;
        else
            r[c] = i;
        cs[i] = a, imp[i] = b;
    }
    DP();
    cout << dp[n];
}

int main() // https://www.luogu.com.cn/problem/P1064
{
    speed
//    t()
    solve();
    return 0;
}
