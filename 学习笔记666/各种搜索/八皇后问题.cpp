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

const ll N = 2e5 + 7;
bool vis[3][N]; // vis[0]��¼�У�vis[1]��vis[2]��¼�����Խ���
// ���¶Խ���i-jΪ��ֵ�����ܳ��ָ������ʲ���i-j+n�� ͬ�����¶Խ���i+j�Ƕ�ֵ
int ans[N], n, cnt = 0;

void dfs(int x)
{
    if(x > n)
    {
        cnt ++;
        if(cnt > 3)
            return;
        run(i, 1, n)
            cout << ans[i] << " \n"[i == n];
        return;
    }
    run(i, 1, n)
        if(!vis[0][i] && !vis[1][x + i] && !vis[2][x - i + n])
        {
            vis[0][i] = vis[1][x + i] = vis[2][x - i + n] = 1;
            ans[x] = i;
            dfs(x + 1);
            vis[0][i] = vis[1][x + i] = vis[2][x - i + n] = 0;
        }
}

void solve()
{
    cin >> n;
    dfs(1);
    cout << cnt << '\n';
}

int main() // https://www.luogu.com.cn/problem/P1219
{
    speed
//    t()
    solve();
    return 0;
}
