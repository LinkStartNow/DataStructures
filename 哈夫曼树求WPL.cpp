#include<bits/stdc++.h>

#define run(i, a, b) for(int i = a; i <= b; i ++)
#define maxn 10000

using namespace std;

int t;

typedef struct yyds
{
    bool f; // 0表示为原数据，1表示为加出来的数据
    yyds* l;
    yyds* r;
    int v; // 记录节点的值
    int lv; // 记录根到节点的路径长度

    yyds(int v) // 方便读取时直接创建结构体指针
    {
        f = 0;
        this->v = v;
        l = r = nullptr;
    }

    yyds(yyds* a, yyds* b) // 在处理哈夫曼树时简化代码
    {
        f = 1;
        l = a, r = b;
        v = a->v + b->v;
    }
} *pp;

struct cmp // 便于优先队列排序
{
    bool operator()(const pp& a, const pp& b)
    {
        return a->v > b->v;
    }
};

priority_queue<pp, vector<pp>, cmp> q; // 优先队列用来优化时间

pp cr(int v) // 创建节点
{
    pp t = new yyds(v);
    return t;
}

pp ssr() // 创造哈夫曼树
{
    while (!q.empty())
    {
        pp t = q.top();
        q.pop();
        if (q.empty()) // 当队列中只剩下一个时，则该值就是树根
        {
            t->lv = 0; // 这里直接把根节点的深度赋值成0可以简化后面代码，虽然只有两行啦
            return t;
        }
        pp s = q.top();
        q.pop();
        pp f = new yyds(t, s);
        q.push(f);
    }
}

int fff(pp s) // 最终求WPL
{
    if (s->l == nullptr) return s->v * s->lv; // 由于有儿子就必定有两个儿子，所以判断一个儿子就够了
    // 如果没有儿子的话就直接判断当前节点是否为原始值进行返回即可
    s->l->lv = s->r->lv = s->lv + 1; // 儿子的深度是父亲的+1，初始根节点为0
    return fff(s->l) + fff(s->r); // 有左右儿子则直接返回左右子树的和即可，因为有左右儿子的情况下自身不可能是原始值
}

int main()
{
    while (cin >> t) q.push(cr(t));
    cout << fff(ssr()) << endl;
}
