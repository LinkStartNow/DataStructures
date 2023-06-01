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

const ll N = 1e5 + 7;
int n;
int a[N], mp[N];
int dp[N];

void solve()
{
    int p;
    cin >> n;
    run(i, 1, n) cin >> a[i];
    run(i, 1, n) cin >> p, mp[p] = i; // 求出a中元素在b中的位置
    memset(dp, 0x3f, sizeof dp);
    int ans = 0;
    dp[0] = 0;
    run(i, 1, n) // 跑一边nlogn的最长上升子序列就是答案了
    {
        int l = 0, r = ans;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(dp[m] < mp[a[i]])
                l = m + 1;
            else
                r = m - 1;
        }
        ans = max(ans, r + 1);
        dp[r + 1] = min(dp[r + 1], mp[a[i]]);
    }
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P1439
{
    speed
//    t()
    solve();
    return 0;
}
