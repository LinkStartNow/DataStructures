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
bool v[N];
queue<int> q;

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
            run(j, 1, m - 1)
                if(v[j])
                    q.push((x + j) % m);
            v[x] = 1;
            while(!q.empty())
                v[q.front()] = 1, q.pop();
        }
        if(v[0])
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
