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

const int N = 1e5 + 7;
int a[N], n;

int find(int l, int r)
{
    int p = a[l + r >> 1];
    l --, r ++; // 因为每次都是先变化再比较所以先拉开一格距离
    while(l < r)
    {
        while(a[-- r] > p); while(a[++ l] < p); // 直到找到大于等于停止
        if(l < r) swap(a[l], a[r]); else return r;
    }
}

void quick(int l, int r)
{
    if(l >= r)
        return;
    int m = find(l, r);
    quick(l, m), quick(m + 1, r);
}

void solve()
{
    cin >> n;
    run(i, 1, n) cin >> a[i];
    quick(1, n);
    run(i, 1, n) cout << a[i] << ' ';
}

int main() // https://www.luogu.com.cn/problem/P1177
{
    speed
//    t()
    solve();
    return 0;
}
