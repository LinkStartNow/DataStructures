#include<bits/stdc++.h>

//#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
//#define t() int t; cin >> t; while(t --)
#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;
double a, b, c, d;
int ssr(double x)
{
    if(pow(x, 3) * a + pow(x, 2) * b + x * c + d > 0)
        return 1;
    return -1;
}
bool check(double x)
{
    double t = x + 0.001;
    if(ssr(x) * ssr(t) < 0)
        return 1;
    return 0;
}
void solve()
{
    cin >> a >> b >> c >> d;
    int ans = 0;
    for(double i = -100; i <= 100; i += 0.001)
    {
        if(check(i))
        {
            ans ++;
            printf("%.2f ", i);
        }
        if(ans == 3)
            break;
    }
}
int main()
{
    solve();
    return 0;
}  //https://www.luogu.com.cn/problem/P1024
