#include<bits/stdc++.h>

using namespace std;

typedef struct yyds
{
    int v;
    yyds* l;
    yyds* r;

    yyds(int v)
    {
        this->v = v;
        l = r = nullptr;
    }

    yyds* into(yyds* f, int v)
    {
        if (!f) // 如果f为空则说明该数为空，v就是根节点
        {
            f = new yyds(v);
            return f;
        }
        else
        {
            if (v < f->v) f->l = into(f->l, v); // 小于根节点则插入左子树
            else f->r = into(f->r, v); // 否则插入右子树
            return f;
        }
        return f;
    }

} *jojo;

void ssr(jojo f) // 中序遍历输出排序后的数
{
    if (!f) return;
    ssr(f->l);
    printf("%d ", f->v);
    ssr(f->r);
}

int main()
{
    int t;
    jojo root = nullptr;
    while (cin >> t) root = root->into(root, t); // 把t插入数root中
    ssr(root);
}
