#include<bits/stdc++.h>

//#define ll long long
#define run(i, a, b) for(double i = a; i <= b; i ++)
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
int check(double x)
{
    double t = x * x * x * a + x * x * b + x * c + d;
    if(t > 0)
        return 1;
    else if(t < 0)
        return -1;
    else
        return 0;
}
void solve()
{
    cin >> a >> b >> c >> d;
    int s = 0;
    run(i, -100, 100)
    {
        double l = i, r = i + 1;
        int x1 = check(l), x2 = check(r);
        if(!x1)
        {
            s ++;
            printf("%.2f ", i);
        }
        if(x1 * x2 < 0)
        {
            while(r - l >= 1e-3)
            {
                double m = (r + l) / 2;
                if(check(m) * check(r) <= 0)
                    l = m;
                else
                    r = m;
            }
            s ++;
            printf("%.2f ", l);
        }
        if(s == 3)
            break;
    }
}
int main()
{
    solve();
    return 0;
}
