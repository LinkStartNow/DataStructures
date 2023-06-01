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
int a[N], n, t[N];

void ssr(int l, int r)
{
    if(r <= l)
        return;
    int m(l, r);
    ssr(l, m), ssr(m + 1, r);
    int p = l, q = m + 1, g = l;
    while(g <= r)
    {
        if((q > r || a[p] < a[q]) && p <= m) // 第二个数组已经用完了直接塞第一个数组或者第一个数组当前的数字更小
            // 但是这些都是以第一个数组还有数字为前提的，所以要判断一下
            t[g ++] = a[p ++];
        else
            t[g ++] = a[q ++];
    }
    run(i, l, r) a[i] = t[i]; // 最后把临时数组的数赋回原数组，以供上一层的排序使用
}

void solve() // https://www.luogu.com.cn/problem/P1177
{
    cin >> n;
    run(i, 1, n) cin >> a[i];
    ssr(1, n);
    run(i, 1, n) cout << a[i] << ' ';
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}
