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
const int N = 2e5 + 7;
ll n, k;
ll a[N];

ll lowbit(ll x)
{
    return x & -x;
}

void solve()
{
    char ans = 0;
    int n;
    cin >> n;
    n = n << 1 | 1;
    while(n --)
    {
        string s;
        cin >> s;
        for(auto x : s)
            ans ^= x;
    }
    cout << ans << '\n';
}
int main() //https://codeforces.com/contest/1688/problem/C
{
    speed
    t()
    solve();
    return 0;
}
