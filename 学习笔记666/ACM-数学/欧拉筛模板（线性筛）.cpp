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

const ll N = 1e8 + 7;
int pri[N], tot;
bool vis[N];
int n, q;

void init()
{
    run(i, 2, n)
    {
        if(!vis[i]) // ����ǰ������ɸѡ��û�������������������
            pri[++ tot] = i;
        run(j, 1, tot) // �����ǰ�һ�������������С�������벻�����Լ���������ӵĳ˻�����ɸѡ
        {
            if(i * pri[j] > n) break; // ����������ݷ�Χֹͣ
            vis[i * pri[j]] = 1; // �ѳ˻��ó�������ɸ��
            if(i % pri[j] == 0) break; // ���貿�֣���Ϊi����С��������pri��j���������ڴ�֮���pri��k��*i����С�����Ӷ���pri��j�����ظ�ɸѡ����ֱ���˳�
        }
    }
}

void solve()
{
    cin >> n >> q;
    init();
    while(q --)
    {
        int t;
        cin >> t;
        cout << pri[t] << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P3383
{
    speed
//    t()
    solve();
    return 0;
}
