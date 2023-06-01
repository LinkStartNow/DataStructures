#include<bits/stdc++.h>

using namespace std;

struct yyds
{
    int v;
    yyds *ssr;
};

yyds* creat()
{
    yyds* head, *p, *q; //
    head = p = (yyds*)malloc(sizeof(yyds)); // �����pһ����ַ�����Ұ������ַͬʱ��head��Ҳ����˵��ʱhead��p��ָ��ͬһ���ڴ��
    head->ssr = nullptr; // ����ı�ľ����ڴ�������ˣ���Ϊhead��pָ��ͬһ���ڴ����Դ�ʱp->ssrҲ��nullptr
    int t;
    while(cin >> t)
    {
        // ������Ͳ�����ʹ��headָ���ˣ���ΪheadҪ��Ϊͷָ���λ�ñ�ǣ��������׶�
        // ���������¿����½ڵ�ı���ָ���ֱ��������ʹ��p�����ˣ�����ۻ�ȫ����������ȫ��head��
        q = (yyds*)malloc(sizeof(yyds));
        q->v = t;
        q->ssr = p->ssr, p->ssr = q, p = q;
    }
    return head;
}

yyds* rev(yyds *now, yyds *pri)
{
    // �ڲ������������ǰ������������ֻ��ԭ�����϶��ֽ�
    if(now->ssr == nullptr) // �Ѿ���β�ڵ��ˣ��ݹ��յ��־
    {
        yyds *res = (yyds*)malloc(sizeof(yyds)); // �µġ�head��ָ��
        now->ssr = pri, res->ssr = now;
        return res;
    }
    yyds *res =  rev(now->ssr, now); // ��Ϊ��һ��Ҫ�ı䵱ǰ�ڵ��ssrָ�룬���Բ���ֱ��return��һ����ֵ����Ȼnow��ssr��û������
    // ͬ��Ҳ�����ȸı��return����Ϊ�ı��ݹ鴫ֵ������ȷ���ˣ�û�취ֻ���Ҹ���������¼�·���ֵ
    now->ssr = pri;
    return res;
}

yyds* re2(yyds *head)
{
    // ͷ��ʽ�����±�ʵ�����ã�Ҫ�࿪һ�����ڴ�
    yyds *p = head, *q, *res; // Ϊ�˱�֤ԭ�������ı�������p�̳�ԭͷָ���ֵ
    // res���Ƿ��ص��¡�head��
    // ����ľ��Ǿ����ͷ��ʽ������
    res = (yyds*)malloc(sizeof(yyds));
    res->ssr = nullptr;
    while(p->ssr != nullptr)
    {
        p = p->ssr; // pһ�������ȡ��ԭ�����ֵ
        q = (yyds*)malloc(sizeof(yyds)); // q�������������½ڵ�
        q->v = p->v; // ��ֵ��ԭ����������
        q->ssr = res->ssr; // �½ڵ�ָ��֮ǰ����Ԫ�ڵ�
        res->ssr = q;
    }
    return res;
}

void read(yyds *k) // Ĭ�ϴ�����ǵ�ǰ�����ͷָ��
{
    while(k->ssr != nullptr) // ����ĳ�for��ʵ����ʡ����ʡ��ʲô�ģ�����ν��������
    {
        k = k->ssr; // ��while��֪�϶�����һ���ڵ㣬�������������У��տ�ʼ�����ͷ���ѹ��û����������ֱ������Ҳ����©ֵ
        printf("%d ", k->v);
    }
    puts("");
}

int main()
{
    yyds* head = creat(); // ��������
    read(head); // ˳���������
    yyds *re = re2(head);
    free(head); // �ͷ�headָ����ڴ棬��������ϵͳ�㱨����ڴ��Ѿ������ˣ����Է������һ����Ҫ���ˣ����ǽ����ڻ㱨����������ڴ����ʼ�����ڲ���ֵ�������ڵ�
    // headҲ��Ȼָ��ԭ���Ǹ���ַ������һ���漰����ռ�ǰ����ڴ��ֵ������֪��δ�ı�ģ���������(����ǼٵΣ���Ҫ�Ű���cb������֮��)
    head = rev(head->ssr, nullptr); // ���ﴫ��ĵ�һ��������������ĵ�һ��������Ľڵ��ָ�������ͷָ��
    // ��ͬ����˵��headָ����ڴ�ռ�����û�䣬���ڴ��д��ֵҲû�䣬���ǿ���ֱ����ô�ã���Ȼfree�������µ��ڴ����������
    read(re);
}