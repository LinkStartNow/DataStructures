#include <bits/stdc++.h>

#define LIST_SIZE 100

using namespace std;

typedef int elemtype;

struct Lnode
{
    elemtype data; // �洢��ֵ
    Lnode *next; // ָ����һ���ڵ��ָ��
    int len; // �����ȣ�ֻ������ͷ��Ч

    void creat() // ��������
    {
        this->len = 0, this->next = nullptr; // �����ֵҲһ��Ҫ��
        Lnode *p = this;
        int t;
        while(cin >> t)
        {
            Lnode *q = new Lnode; // �������ֱ����new����, new���ص���һ��ָ��
            q->data = t, q->next = p->next, p->next = q, p = q;
        }
    }

    void append() // ׷�Ӻ���
    {
        Lnode *l = this; // this��ʾ�ṹ�������ͨ��������Ե����Լ����ǳ�����
        int x;
        printf("������Ҫ׷�ӵ����֣�");
        scanf("%d", &x);
        while(l->next != nullptr)
            l = l->next;
        Lnode *p = (Lnode *)malloc(sizeof(Lnode)); // ����sizeof������һ��Ҫ���ϣ���Ȼ�����
        p->data = x, p->next = l->next, l->next = p;
        len ++;
    }

    void insert() // ���뺯��
    {
        int x, pos;
        printf("����������λ�úͲ����ֵ:");
        scanf("%d%d", &pos, &x);
        if(pos > len || pos < 0)
        {
            puts("Error!");
            return;
        }
        Lnode *p = this, *q = (Lnode *)malloc(sizeof(Lnode));
        q->data = x;
        int cnt = 0;
        while(cnt < pos - 1)
        {
            p = p->next;
            cnt ++;
        }
        len ++;
        q->next = p->next;
        p->next = q;
    }

    void del() // ɾ������
    {
        int pos;
        printf("������ɾ����λ��:");
        scanf("%d", &pos);
        if(pos > len || pos < 0)
        {
            puts("error!");
            return;
        }
        Lnode *p = this;
        int cnt = 0;
        while(cnt < pos - 1)
        {
            cnt ++;
            p = p->next;
        }
        p->next = p->next->next;
        len --;
    }

    void change() // �޸ĺ���
    {
        int x, pos;
        printf("������ı��λ�ú͸ı���ֵ:");
        scanf("%d%d", &pos, &x);
        if(pos > len || pos < 0)
        {
            puts("error!");
            return;
        }
        Lnode *p = this;
        int cnt = 0;
        while(cnt < pos)
        {
            cnt ++;
            p = p->next;
        }
        p->data = x;
    }

    void show() // չʾ����
    {
        Lnode *l = this;
        while(l->next != nullptr)
        {
            l = l->next;
            printf("%d ", l->data);
        }
        puts("");
    }

    void find() // ��ѯ����
    {
        Lnode *l = this;
        printf("������Ҫ���ҵ���:");
        int x;
        scanf("%d", &x);
        int cnt = 0;
        while(l->next != nullptr)
        {
            l = l->next;
            cnt ++;
            if(l->data == x)
            {
                printf("%d", cnt);
                return;
            }
        }
        puts("Not Find!");
    }

    void manager(int k) // ����������
    {
        switch(k)
        {
        case 1:
            this->insert();
            break;
        case 2:
            this->del();
            break;
        case 3:
            this->change();
            break;
        case 4:
            this->show();
            break;
        case 5:
            this->find();
            break;
        case 6:
            this->append();
            break;
        case 7:
            printf("%d\n", this->len);
            break;
        }
    }

};

int main()
{
    printf("���������ݴ�������");
    Lnode *l = new Lnode; // �����ȸ�ָ������ڴ�ռ䣬��Ȼָ�벻���ã�Ҳ����˵�������creat���������ò�����
    l->creat();
    puts("������Ĳ�����0���˳��� 1�����룬 2��ɾ���� 3���ı�, 4��չʾ, 5������, 6��׷��, 7����ѯ���ȣ�");
    while(1)
    {
        printf("�����������:");
        int k;
        scanf("%d", &k);
        if(!k)
            return 0;
        l->manager(k);
    }
}