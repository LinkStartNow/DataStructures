#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, u, v, w, ans;
struct Trie01
{
    int trie[32 * N][2], cnt;
    void init()
    {
        trie[0][0] = trie[0][1] = 0;
    }
    void putin(int n)
    {
        int p = 0;
        for(int i = 31; i >= 0; i --)
        {
            if((n >> i) & 1)
            {
                if(!trie[p][1])
                {
                    trie[p][1] = ++ cnt;
                    trie[cnt][0] = trie[cnt][1] = 0;
                }
                p = trie[p][1];
            }
            else
            {
                if(!trie[p][0])
                {
                    trie[p][0] = ++ cnt;
                    trie[cnt][0] = trie[cnt][1] = 0;
                }
                p = trie[p][0];
            }
        }
    }
    int sear(int n)
    {
        int p = 0, ans = 0;
        for(int i = 31; i >= 0; i --)
        {
            if(trie[p][((n >> i) & 1) ^ 1])
            {
                ans |= (1 << i);
                p = trie[p][((n >> i) & 1) ^ 1];
            }
            else
            {
                p = trie[p][((n >> i) & 1)];
            }
        }
        return ans;
    }
}trie;
struct point
{
    int to, val, nx;
} edge[N * 2];
int head[N * 2], tot, dis[N];
bool vis[N];
void add(int u, int v, int w)
{
    tot ++;
    edge[tot].to = v;
    edge[tot].val = w;
    edge[tot].nx = head[u];
    head[u] = tot;
}
void init()
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    tot = 0, ans = 0;
    memset(head, 0,sizeof(head));
}
void dfs(int u, int vs)
{
    for(int i = head[u]; i; i = edge[i].nx)
    {
        int v = edge[i].to, w = edge[i].val;
        dis[v] = w ^ vs;
        if(!vis[v])
        {
            vis[v] = 1;
            dfs(v, dis[v]);
        }
    }
}
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        init();
        for(int i = 1; i < n; i ++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        vis[0] = 1;
        dfs(0, 0);
        trie.init();
        for(int i = 1; i < n; i ++)
        {
            ans = max(ans, dis[i]);
            ans = max(ans, trie.sear(dis[i]));
            trie.putin(dis[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}