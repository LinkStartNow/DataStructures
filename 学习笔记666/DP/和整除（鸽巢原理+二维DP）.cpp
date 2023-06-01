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
ll a[N];
bool v[1007][1007];

void solve()
{
    ll n, m;
    cin >> n >> m;
    run(i, 1, n)
    cin >> a[i];
    if(n > m)
        cout << "YES" << '\n';
    else
    {
        run(i, 1, n)
        {
            ll x = a[i] % m;
            v[i][x] = 1;
            run(j, 0, m - 1)
            {
                if(v[i - 1][j])
                    v[i][(j + x) % m] = 1;
                v[i][j] |= v[i - 1][j];
            }
        }
        if(v[n][0])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main() // https://codeforces.com/problemset/problem/577/B
{
    speed
//    t()
    solve();
    return 0;
}
