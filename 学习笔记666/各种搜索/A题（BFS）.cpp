#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
int nx[4] = {-1, 1, 0, 0}, ny[4] = {0, 0, -1, 1};
const int N = 105;
char mp[N][N];
bool vis[N][N];
int n, m, k;
struct yyds
{
    int x, y, time;
};
queue<yyds> q;
struct train
{
    int tox, toy, key;
} tr[N][N];

int bfs(int sx, int sy, int ex, int ey)
{
    while(!q.empty())
        q.pop();
    if(sx == ex && sy == ey)
        return 0;
    bool f = 0;
    int ans = -1;
    ms(vis);
    vis[sx][sy] = 1;
    if(tr[sx][sy].key)
    {
        int xx = tr[sx][sy].tox, yy = tr[sx][sy].toy;
        sx = xx, sy = yy;
        if(sx == ex && sy == ey)
            return 0;
        if(mp[sx][sy] == '~')
            return -1;
        vis[sx][sy] = 1;
    }
    q.push(yyds{sx, sy, 0});
    while(!q.empty())
    {
        yyds s = q.front();
        q.pop();
        int x = s.x, y = s.y;
        vis[x][y] = 1;
        run(i, 0, 3)
        {
            int tx = x + nx[i], ty = y + ny[i];
            if(vis[tx][ty])
                continue;
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if(tx == ex && ty == ey)
            {
                f = 1;
                ans = s.time + 1;
                break;
            }
            if(mp[tx][ty] == '~')
                continue;
            if(tr[tx][ty].key)
            {
                vis[tx][ty] = 1;
                int xx, yy;
                xx = tr[tx][ty].tox;
                yy = tr[tx][ty].toy;
                vis[xx][yy] = 1;
                if(mp[xx][yy] == '~')
                    continue;
                if(xx == ex && yy == ey)
                {
                    f = 1;
                    ans = s.time + 1;
                    break;
                }
                q.push(yyds{xx, yy, s.time + 1});
                continue;
            }
            vis[tx][ty] = 1;
            q.push(yyds{tx, ty, s.time + 1});
        }
        if(f)
            break;
    }
    return ans;
}

int main()
{
    t()
    {
        ms(tr);
        ms(mp);
        int ans1 = -1, ans2 = -1;
        int sx, sy, ex, ey;
        scanf("%d%d", &n, &m);
        run(i, 1, n)
        scanf("%s", mp[i] + 1);

        run(i, 1, n)
        run(j, 1, m)
        if(mp[i][j] == 'C')
            sx = i, sy = j;
        else if(mp[i][j] == 'G')
            ex = i, ey = j;
//        printf("%d %d,,,%d %d", sx, sy, ex, ey);

        scanf("%d", &k);
        run(i, 1, k)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            tr[a][b] = train{c, d, 1};
        }
        ans1 = bfs(sx, sy, ex, ey);
        ans2 = bfs(ex, ey, sx, sy);
        printf("%d %d\n", ans1, ans2);
    }
}
