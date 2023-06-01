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
    void add() // 字典树基本操作
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
        run(i, 0, 25) // 从根节点出发寻找各种字母开头的可能
            if(int x = nd[0][i]) // 若以i字母开头的单词存在
            {
                q.push(x);
                fail[x] = 0; // 由于是第一层所以只能指向第0层，而第0层只有唯一的0
            }
        while(!q.empty()) // 由于每个点的失配数组至少是上一层的，于是采用bfs遍历
        {
            int p = q.front();
            q.pop();
            run(i, 0, 25) // 每个存在的节点向下试探看看有没有存在的节点
                if(int x = nd[p][i]) // 这骚气的if结构也是今天刚刚试出来的哈哈哈
                {
                    fail[x] = nd[fail[p]][i]; // 节点存在的话他的失配数组就是他父亲节点的失配节点指向的另一个平行宇宙的他
                    q.push(x); // 因为这个节点存在，所以压入队列往下更新
                }
                else
                    nd[p][i] = nd[fail[p]][i]; // 不存在该节点时，直接就指向自身的失配节点的另一个平行宇宙的该节点，指向别人家的孩子就是香哈哈哈
                    // 这里就不用压入队列了，首先这个节点根本不存在，再者他的替代品（也就是所谓别人家的孩子）至少是上一层的，在访问到这个节点之前早就被处理完了，或者说在队列里等待被处理
        }
    }
    int yyds()
    {
        int res = 0;
        int l = strlen(s + 1), p = 0;
        run(i, 1, l) // 依旧要把整个串遍历完
        {
            int c = s[i] - 'a';
            int x = nd[p][c];
            vis[p] = 1;
            while(!vis[x] && x) // 下一个节点不存在或者已经被访问过了便直接退出
            {
                vis[x] = 1; // 每次访问完一个节点要打上访问标记，以免重复访问
                res += ed[x];
                x = fail[x]; // 通过失配数组开始跳跃节点
                // 其实结合图更方便理解，ac自动机就是一步步遍历完整个串，并且每多遍历一位就把当前串能搜索到的后缀都查询一遍
            }
            p = nd[p][c]; // 没节点了就回到根节点0从头开始
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
    t.getfail(); // 建完字典树统一处理失配数组
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