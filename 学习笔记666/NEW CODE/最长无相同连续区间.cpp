#include<bits/stdc++.h>

#define ll long long
#define lb long double
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
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e5 + 7;
set<int> s;
int a[N], p;

void solve()
{
    int n, k;
    int ans = 0;
    cin >> n >> k;
    run(i, 1, n)
    {
        cin >> a[i];
        a[i] >>= k;
        while(s.count(a[i])) s.erase(a[++ p]); // Ëõ¶Ì×ó±ß½ç
        s.insert(a[i]); // À©Õ¹ÓÒ±ß½ç
        ans = max(ans, int(s.size()));
    }
    cout << ans;
}


int main() // https://ac.nowcoder.com/acm/contest/37895/B
{
    speed
//    t()
    solve();
    return 0;
}
