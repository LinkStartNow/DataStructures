#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e4 + 7;
int n, m, s, t;
int deep[N];
ll ans;

struct edge
{
    int to, nx, flow; // flow�Ǳߵ��������
} e[N];

int head[N], tot = 1, no[N];

void add(int x, int y, int w)
{
    e[++ tot] = {y, head[x], w};
    head[x] = tot;
}

bool bfs()
{
    run(i, 1, n)
    deep[i] = i == s; // ��ʼ����ȣ�����������Ϊ1���������ʼΪ0��ʾ��δ������
    queue<int> q;
    q.push(s);
    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        no[u] = head[u]; // �����no��������棬�����ǵ�һ���ܵ����յ�Ľڵ㣬��ô��������return 1��
        // ����ͬΪ�ܵ����յ�����һ���ڵ㶼û��noֵ�����ÿһ�ָ���ֻ�����һ������·��
        for(int i = head[u]; i; i = e[i].nx)
        {
            v = e[i].to;
            if(deep[v] || !e[i].flow) // ��ΪҪ��deo��¼�����������Ѿ��ݷ����˾Ͳ�Ҫ�ټ�����
                // ����Ѿ�û�в���������˵����·��ͨ��
                continue;
            deep[v] = deep[u] + 1;
            q.push(v);
            if(v == t) // ����ĳ����s��t��·��������ͨ˵����������·��
                return 1;
        }
    }
    return 0;
}

int dfs(int u, int guess)
{
    if(u == t) // ֻҪ�������յ����������ʿ��Լ����յ��������һ���ܽ������������ĵ�
        return guess; // ���ǿ���ֱ�ӷ��ز²�ֵ�������������յ��������¼����
    int v, flow = 0, back = 0; // back��ʾ��ǰ�ڵ������������������������ķ���
    for(int i = no[u]; i && guess - back; i = e[i].nx)
    {
        no[u] = i; // ���Ż��������η������ñ�
        // ÿ�η��ʵ�һ���µ�����no���飬��Ϊ�ܸ��µ�����ڵ��Ȼ����Ϊǰ�漸���ڵ������ȫ��������
        // ��Ȼ�����Ϊu�ڵ������������������˳����㲻���ٷ��ʵ�Ŀǰ�Ľڵ���
        v = e[i].to;
        if(deep[v] == deep[u] + 1 && e[i].flow)
        {
            flow = dfs(v, min(e[i].flow, guess - back));
            e[i].flow -= flow;
            e[i ^ 1].flow += flow;
            back += flow;
        }
        // ��������Ϊʲôֻȥ����deep + 1�ĵ㣺
            // dep֮�����1��
                // ���֮�����1�ĵ����Ȼ��������ֱ�ӵ�����Բ��ܸ���

            // depС1��
                // ��Ϊ���ǵ����ڻ�������������Խ�ͼ��ʱ��ͽ�����˫��ߣ�����ÿ���߶��ǳɶԵģ����Կ϶������ָ��dep-1�ĵ�
                // ����ȵ�ǰ�����Ȼ�С1���ڻ�����������������Ȼ��Ⱦͽ�����ɴ�1�ˣ���ʱ�����ж����ֻ������������������ǰ���������һ�٣�����������ѭ��

            // dep��ȣ�
                // ��Ϊ��������������һ����϶�Ҳ���ɵ�ǰ�ڵ�ĸ��ڵ�ֱ�ӿ��Ե���ģ�Ҳ�������Ϊ���ڵ㲥���Ǹ��ڵ�ľ��Ѷ���û���꣬��ǰ�ڵ㲻���ż���ǰ������
                // ������ڵ㵽�Ǹ��ڵ�����������Ǹ��ڵ�������������������֮����ʵ��ýڵ�϶�dep�������Ҳ����˵��ǰ�ڵ�û�л�����µ���
                // ������ڵ���ľ��Ѳ������˿������Ϊ���ڵ㲻��ֱ�ӵ����Ǹ��ڵ㣬��ʱ��ǰ�ڵ��ڱ����ڵ㸳��depʱ�Ϳ�����֮��������Ǹ��ڵ㲢������dep��ñȵ�ǰ��dep��1��Ҳ���ǿ��Ը�����������
    }
    return back;
}

void dinic()
{
    while(bfs())
        ans += dfs(s, 0x7f7f7f); // ��ΪԴͷ���������������Լٶ�Դͷ������Ϊһ������ֵ
}

void solve()
{
    cin >> n >> m >> s >> t;
    run(i, 1, m)
    {
        int u, v, f;
        cin >> u >> v >> f;
        add(u, v, f);
        add(v, u, 0);
    }
    dinic();
    cout << ans << endl;
}

int main() // https://www.luogu.com.cn/problem/P3376
{
    speed
//    t()
    solve();
    return 0;
}