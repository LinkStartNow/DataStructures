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

const ll N = 1e5 + 7;
int a[N];
int n, q;

void solve()
{
    set<int> zly;
    cin >> n >> q;
    run(i, 1, n)
    {
        cin >> a[i];
        if(zly.empty() || a[i] < a[*zly.rbegin()])
            zly.insert(i);
    }
    run(i, 1, q)
    {
        int x, y;
        cin >> x >> y;
        a[x] -= y;
        auto it = zly.upper_bound(x);
        if(it != zly.begin())
        {
            it = prev(it);
            if(*it == x || a[x] < a[*it])
                zly.insert(x);
        }
        else
            zly.insert(x);
        while(1)
        {
            auto it = zly.upper_bound(x);
            if(it != zly.end() && a[x] <= a[*it])
                zly.erase(it);
            else
                break;
        }
        cout << zly.size() << ' ';
    }
    cout << '\n';
}

int main() // https://codeforces.com/problemset/problem/1690/G
{
    speed
    t()
    solve();
    return 0;
}
