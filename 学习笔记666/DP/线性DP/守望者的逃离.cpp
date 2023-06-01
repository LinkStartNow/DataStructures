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

const ll N = 1007;

void solve()
{
    int m, s, t;
    cin >> m >> s >> t;
    ll s1 = 0, s2 = 0; // 两条线一起进行，s1是一直在走路，s2一直在闪现
    run(i, 1, t)
    {
        s1 += 17;
        if(m >= 10)
        {
            s2 += 60;
            m -= 10;
        }
        else
            m += 4;
        s1 = max(s1, s2); // 走路没有闪现快就用闪现代替
        if(s1 > s)
        {
            puts("Yes");
            printf("%d", i);
            return;
        }
    }
    puts("No");
    printf("%d", s1);
}

int main() // https://www.luogu.com.cn/problem/P1095
{
    speed
//    t()
    solve();
    return 0;
}
