#include<bits/stdc++.h>

#define ll long long
#define lb long double
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
char buf[100000], *pa = buf, *pd = buf;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e5 + 7, p = 1e15; // ����n��С������+7�˷��˸�����wa�˰�����ҳ���
char s[N], st[N << 1];
ll re[N << 1], tot;
ll llen[N << 1], rlen[N << 1];

ll lowbit(ll x)
{
    return x & -x;
}

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

ll read()
{
    int f(1);
    ll res(0);
    char c(gc);
    for(; c > '9' || c < '0'; c = gc)
        if(c == '-')
            f = -1;
    for(; c >= '0' && c <= '9'; c = gc)
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res * f;
}

void init()
{
    st[0] = '@';
    st[1] = '#';
    ll l = strlen(s + 1);
    tot = 2;
    run(i, 1, l)
        st[tot ++] = s[i], st[tot ++] = '#';
    st[tot] = '\0';
}

void exp(ll x)
{
    ll l = x - re[x], r = x + re[x];
    while(st[l] == st[r])
        l --, r ++, re[x] ++;
}

void fresh(ll x)
{
    ll l = x - re[x] + 1, r = x + re[x] - 1;
    llen[l] = max(llen[l], re[x] - 1), rlen[r] = max(rlen[r], re[x] - 1);
}

void yyds()
{
    // ��һ����ĸ�ǻ��Ĵ���һ���֣���ô�����Ŀո��ȻҲ�ǻ��Ĵ���һ���֣��Ͼ��ո�һһ��Ӧ
    for(int i = 1; i <= tot; i += 2)  // ����ѡȡ��Ҳ�ǿո�λ�����ݣ����Ǹ��¿ո�λ���
        llen[i] = max(llen[i], llen[i - 2] - 2);
    for(int i = tot; i >= 1; i -= 2)
        rlen[i] = max(rlen[i], rlen[i + 2] - 2);
}

void man()
{
    init();
    ll id = 0, r = 0;
    run(i, 1, tot)
    {
        ll j = id * 2 - i;
        re[i] = i < r ? min(re[j], r - i) : 1;
        exp(i);
        fresh(i);
        if(i + re[i] > r)  // ������֪�߽�
            r = i + re[i], id = i;
    }
    yyds();  // ����һ������
}

void solve()
{
    cin >> s + 1;
    man();
    ll ans = 0;
    for(int i = 1; i <= tot; i += 2)
        ans = llen[i] && rlen[i] ? max(ans, llen[i] + rlen[i]) : ans;
    // ������Ϊ�������Ĵ������й������֣�����ֱ�ӿ����Կո񲿷�Ϊ��ͷ�ͽ�β������Ĵ��;�����
    // ��Ȼ��Ϊ�������Ĵ��������ǿմ����Ի���Ҫ����һ���ǲ��ǿմ�
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P4555
{
    speed
//    t()
    solve();
    return 0;
}
