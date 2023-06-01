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

const ll N = 1e6 + 7;
char s[N];

struct trie
{
    int nd[N][26], tot;
    bool vis[N];
    int ed[N], fail[N];
    void add() // �ֵ�����������
    {
        int l = strlen(s + 1), p = 0;
        run(i, 1, l)
        {
            int c = s[i] - 'a';
            if(!nd[p][c])
                nd[p][c] = ++ tot;
            p = nd[p][c];
        }
        ed[p] ++;
    }
    void getfail()
    {
        queue<int> q;
        run(i, 0, 25) // �Ӹ��ڵ����Ѱ�Ҹ�����ĸ��ͷ�Ŀ���
            if(int x = nd[0][i]) // ����i��ĸ��ͷ�ĵ��ʴ���
            {
                q.push(x);
                fail[x] = 0; // �����ǵ�һ������ֻ��ָ���0�㣬����0��ֻ��Ψһ��0
            }
        while(!q.empty()) // ����ÿ�����ʧ��������������һ��ģ����ǲ���bfs����
        {
            int p = q.front();
            q.pop();
            run(i, 0, 25) // ÿ�����ڵĽڵ�������̽������û�д��ڵĽڵ�
                if(int x = nd[p][i]) // ��ɧ����if�ṹҲ�ǽ���ո��Գ����Ĺ�����
                {
                    fail[x] = nd[fail[p]][i]; // �ڵ���ڵĻ�����ʧ��������������׽ڵ��ʧ��ڵ�ָ�����һ��ƽ���������
                    q.push(x); // ��Ϊ����ڵ���ڣ�����ѹ��������¸���
                }
                else
                    nd[p][i] = nd[fail[p]][i]; // �����ڸýڵ�ʱ��ֱ�Ӿ�ָ�������ʧ��ڵ����һ��ƽ������ĸýڵ㣬ָ����˼ҵĺ��Ӿ����������
                    // ����Ͳ���ѹ������ˣ���������ڵ���������ڣ������������Ʒ��Ҳ������ν���˼ҵĺ��ӣ���������һ��ģ��ڷ��ʵ�����ڵ�֮ǰ��ͱ��������ˣ�����˵�ڶ�����ȴ�������
        }
    }
    int yyds()
    {
        int res = 0;
        int l = strlen(s + 1), p = 0;
        run(i, 1, l) // ����Ҫ��������������
        {
            int c = s[i] - 'a';
            int x = nd[p][c];
            vis[p] = 1;
            while(!vis[x] && x) // ��һ���ڵ㲻���ڻ����Ѿ������ʹ��˱�ֱ���˳�
            {
                vis[x] = 1; // ÿ�η�����һ���ڵ�Ҫ���Ϸ��ʱ�ǣ������ظ�����
                res += ed[x];
                x = fail[x]; // ͨ��ʧ�����鿪ʼ��Ծ�ڵ�
                // ��ʵ���ͼ��������⣬ac�Զ�������һ����������������������ÿ�����һλ�Ͱѵ�ǰ�����������ĺ�׺����ѯһ��
            }
            p = nd[p][c]; // û�ڵ��˾ͻص����ڵ�0��ͷ��ʼ
        }
        return res;
    }
} t;

void solve()
{
    int n;
    cin >> n;
    run(i, 1, n)
    {
        cin >> s + 1;
        t.add();
    }
    t.getfail(); // �����ֵ���ͳһ����ʧ������
    cin >> s + 1;
    cout << t.yyds();
}

int main() // https://www.luogu.com.cn/problem/P3808
{
    speed
//    t()
    solve();
    return 0;
}