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

const ll N = 2e5 + 7;
char s[N];
int len;
int p[N], tot;

bool yyds(int k)
{
    if(!k)
    {
        int l = p[1], r = p[tot];
        int re0 = r - l + 1 - tot;
        if(re0)
            return 0;
        return 1;
    }
    int ssr = tot - k;
    run(i, 0, k)
    {
        int f = i + ssr + 1;
        int l = i == 0 ? 1 : p[i] + 1;
        int r = f > tot ? len : p[f] - 1;
        int re0 = r - l + 1 - ssr;
        int sr = i == tot ? len + 1 : p[i + 1];
        re0 -= (sr - l);
        sr = f <= 1 ? 0 : p[f - 1];
        re0 -= (r - sr);
        if(re0 <= k)
            return 1;
    }
    return 0;
}

void solve()
{
    tot = 0;
    cin >> s + 1;
    len = strlen(s + 1);
    run(i, 1, len)
        if(s[i] == '1')
            p[++ tot] = i;
    int l = 0, r = tot;
    if(tot == 0 || tot == len)
    {
        cout << 0 << '\n';
        return;
    }
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if(yyds(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << '\n';
}

int main() // https://codeforces.com/problemset/problem/1680/C
{
    speed
    t()
    solve();
    return 0;
}
