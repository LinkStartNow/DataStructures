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
const int N = 1e5 + 7;
char a[N], b[N];

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
    int n;
    cin >> n >> a + 1 >> b + 1;
    int ba = 0, bb = 0;
    run(i, 1, n)
    {
        if(a[i] == 'b')
            ba ++;
        if(b[i] == 'b')
            bb ++;
    }
    if(ba != bb)
    {
        cout << "NO" << '\n';
        return;
    }
    int j = 1;
    run(i, 1, n)
    {
        if(a[i] == 'b')
            continue;
        while(b[j] == 'b')
            j ++;
        if(a[i] != b[j] || (a[i] == 'a' && i > j) || (i < j && a[i] == 'c'))
        {
            cout << "NO" << '\n';
            return;
        }
        j ++;
    }
    cout << "YES" << '\n';
}
int main() //https://codeforces.com/contest/1697/problem/C
{
    speed
    t()
    solve();
    return 0;
}
