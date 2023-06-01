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
    // �����С��Ҫ�ַ�������*�ַ�������������������ÿ���ַ�����һ���ڵ������
    int t[N * 55][26], cnt = 0; // cnt��¼�ֵ����ж��ٸ��ڵ㣬t����iΪ�ڵ�ָ��j����һ���ڵ�ı��
    bool ed[N * 55], vis[N * 55]; // ed��¼�Ƿ�Ϊ�����ַ���vis��¼�Ƿ񱻵����
    void init()
    {
        run(i, 0, cnt) ed[i] = vis[i] = 0; // cnt��¼������һ�ε��ֵ����ж��ٽڵ㣬�ڽ���֮ǰ�Ȱ���һ�ε���վ�����
        ms(t[0]); // ��Լʱ�䶯̬��������飬�ʼҪ����0�ڵ����������0�ڵ�
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
                ms(t[cnt]); // ���ʵ��½ڵ㣬���ڸýڵ�������ϴν���ʣ�µģ�������Ҫ���
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
        t.build(); // �߶����ַ����߽���
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
