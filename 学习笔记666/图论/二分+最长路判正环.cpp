#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 2e4 + 7;
const double ssr = 1e-10;
bool vis[N]; // ��ǵ�ʱ���ڶ�����
int cnt[N]; // ���ÿ���㱻�ɳڵĴ���
double dis[N]; // ÿ���㵽����Դ��ľ���
int n, m;

struct edge
{
    int to, nx;
    double v;
}   e[N << 2];

int head[N], tot;
void add(int u, int v, double w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
}

bool spfa(double x) // �·������
{
    queue<int> q;
    run(i, 1, n)
    {
        cnt[i] = dis[i] = 0;
        vis[i] = 1;
        q.push(i); // ��ÿ����������н����ж�
    }
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for(int i = head[p]; i; i = e[i].nx)
        {
            int to = e[i].to;
            double w = e[i].v + log(x);
            if(dis[to] < dis[p] + w)
            {
                dis[to] = dis[p] + w;
                cnt[to] = cnt[p] + 1; // �ǳ���Ҫ���Ż�������������������ܻ����У��������ַ����ܼ���ʱ��
                if(cnt[to] > n + 1) // ÿ������౻�ɳ�n�Σ��࿪���α���һ��
                    return 1;
                if(!vis[to]) // ���ɳڵĵ㲻�ڶ�������������
                {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, m)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        add(b, d, log(c / a));
    }
    double l = 0, r = 1;
    while(r - l >= ssr)
    {
        double mid = (l + r) / 2;
        if(spfa(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.10f", l);
}

int main() // https://ac.nowcoder.com/acm/contest/33187/D
{
    speed
//    t()
    solve();
    return 0;
}