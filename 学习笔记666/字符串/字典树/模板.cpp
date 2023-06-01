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

const ll N = 1e4 + 7;
char s[N];

struct trie
{
    // 数组大小需要字符串长度*字符串数量，最差情况可能每个字符都是一个节点哈哈哈
    int t[N * 55][26], cnt = 0; // cnt记录字典树有多少个节点，t是以i为节点指向j的下一个节点的编号
    bool ed[N * 55], vis[N * 55]; // ed记录是否为结束字符，vis记录是否被点过名
    void init()
    {
        run(i, 0, cnt) ed[i] = vis[i] = 0; // cnt记录的是上一次的字典树有多少节点，在建树之前先把上一次的清空就行了
        ms(t[0]); // 节约时间动态的清空数组，最开始要访问0节点所以先清除0节点
        cnt = 0;
    }
    void build()
    {
        int l = strlen(s + 1), p = 0;
        run(i, 1, l)
        {
            int c = s[i] - 'a';
            if(!t[p][c])
            {
                t[p][c] = ++ cnt;
                ms(t[cnt]); // 访问到新节点，由于该节点可能是上次建树剩下的，所以需要清空
            }
            p = t[p][c];
        }
        ed[p] = 1;
    }
    int find()
    {
        int l = strlen(s + 1), p = 0;
        run(i, 1, l)
        {
            int c = s[i] - 'a';
            if(!t[p][c])
                return 0;
            p = t[p][c];
        }
        if(!ed[p])
            return 0;
        if(vis[p])
            return -1;
        vis[p] = 1;
        return 1;
    }
} t;

void solve()
{
    int n, m;
    cin >> n;
    run(i, 1, n)
    {
        cin >> s + 1;
        t.build(); // 边读入字符串边建树
    }
    cin >> m;
    while(m --)
    {
        cin >> s + 1;
        int f = t.find();
        if(!f)
            cout << "WRONG" << '\n';
        else if(f == 1)
            cout << "OK" << '\n';
        else
            cout << "REPEAT" << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P2580
{
    speed
//    t()
    solve();
    return 0;
}
