#include<bits/stdc++.h>

#define ll long long
//#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
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

const ll N = 1e3 + 7;
int nd[5000007][26], cnt;
bitset<N> has[5000007]; // 一个bitset只占1bit，可以大大优化内存，尤其适合表示bool（8bit），或者状压dp
// 同时时间也会得到优化
char s[23];
int n, m;

void add(int id)
{
    int l = strlen(s + 1), p = 0, c;
    run(i, 1, l)
    {
        c = s[i] - 'a';
        if(!nd[p][c])
            nd[p][c] = ++ cnt;
        p = nd[p][c];
    }
    has[p][id] = 1;
}

void work()
{
    int l = strlen(s + 1), p = 0, c;
    run(i, 1, l)
    {
        c = s[i] - 'a';
        if(!nd[p][c])
            return;
        p = nd[p][c];
    }
    run(i, 1, n)
        if(has[p][i])
            cout << i << ' ';
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    {
        int f;
        cin >> f;
        run(j, 1, f) cin >> s + 1, add(i);
    }
    cin >> m;
    while(m --)
    {
        cin >> s + 1;
        work();
        cout << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P3879
{
    speed
//    t()
    solve();
    return 0;
}
