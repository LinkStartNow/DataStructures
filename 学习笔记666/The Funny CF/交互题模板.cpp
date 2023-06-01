#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int N = 1e5 + 7;
char a[N], b[N];

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

bool ask(int x)
{
    printf("%d\n", x); //也可以用'\n'，千万不能打开加速用cout询问，会错误
    fflush(stdout);
    char s[5];
    cin >> s + 1;
    if(s[1] == '>')
        return 1;
    return 0;
}

void solve()
{
    int l = 1, r = 1000000;
    while(l <= r)
    {
        int m(l, r);
        if(ask(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << "! " << r << endl;
    fflush(stdout);
}
int main() //https://codeforces.com/gym/101021
{
    speed
//    t()
    solve();
    return 0;
}
