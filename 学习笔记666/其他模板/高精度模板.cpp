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

const ll N = 3007;
char s[N];
int a[N], b[N], c[N];

struct ssr
{
    int a[1007];

    void init(char *s)
    {
        ms(a);
        int l = strlen(s + 1);
        run(i, 1, l)
        a[i] = s[l - i + 1] - '0';
        a[0] = l;
        return;
    }

    void init(int *c)
    {
        ms(a);
        run(i, 1, c[0])
            a[i] = c[i];
        a[0] = c[0];
    }

    void init(ssr c)
    {
        ms(a);
        run(i, 1, c.a[0])
            a[i] = c.a[i];
        a[0] = c.a[0];
    }

    int* operator+(const ssr &b) const
    {
        static int c[1007]; // 要返回一个静态数组不然会出错
        ms(c);
        int l = max(a[0], b.a[0]);
        run(i, 1, l)
        c[i] += (a[i] + b.a[i]) % 10, c[i + 1] += (a[i] + b.a[i]) / 10;
        c[0] = c[l + 1] ? l + 1 : l;
        return c;
    }

    int* operator*(const ssr &b) const
    {
        static int c[1007];
        ms(c);
        run(i, 1, a[0])
        run(j, 1, b.a[0])
        c[i + j] += (a[i] * b.a[j]) / 10, c[i + j - 1] += (a[i] * b.a[j]) % 10;
        rep(i, a[0] + b.a[0] + 1, 1)
        if(c[i])
        {
            c[0] = i;
            return c;
        }
    }

    void ww()
    {
        rep(i, a[0], 1)
        putchar(a[i] + '0');
        puts("");
    }
};

void solve()
{
    ssr a, b;
    cin >> s + 1;
    a.init(s);
    b.init(a);
    b.ww();
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}
