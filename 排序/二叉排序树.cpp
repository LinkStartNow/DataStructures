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
        if (!f) // ���fΪ����˵������Ϊ�գ�v���Ǹ��ڵ�
        {
            f = new yyds(v);
            return f;
        }
        else
        {
            if (v < f->v) f->l = into(f->l, v); // С�ڸ��ڵ������������
            else f->r = into(f->r, v); // �������������
            return f;
        }
        return f;
    }

} *jojo;

void ssr(jojo f) // ������������������
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
    while (cin >> t) root = root->into(root, t); // ��t������root��
    ssr(root);
}
