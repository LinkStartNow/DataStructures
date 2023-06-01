#include <bits/stdc++.h>

#define LIST_SIZE 100

using namespace std;

typedef int elemtype;

struct Lnode
{
    elemtype data; // 存储数值
    Lnode *next; // 指向下一个节点的指针
    int len; // 链表长度，只有链表头有效

    void creat() // 创建函数
    {
        this->len = 0, this->next = nullptr; // 这个初值也一定要赋
        Lnode *p = this;
        int t;
        while(cin >> t)
        {
            Lnode *q = new Lnode; // 这里可以直接用new代替, new返回的是一个指针
            q->data = t, q->next = p->next, p->next = q, p = q;
        }
    }

    void append() // 追加函数
    {
        Lnode *l = this; // this表示结构体对象本身，通过这个可以调用自己，非常有用
        int x;
        printf("请输入要追加的数字：");
        scanf("%d", &x);
        while(l->next != nullptr)
            l = l->next;
        Lnode *p = (Lnode *)malloc(sizeof(Lnode)); // 这里sizeof的括号一定要加上，不然会出错
        p->data = x, p->next = l->next, l->next = p;
        len ++;
    }

    void insert() // 插入函数
    {
        int x, pos;
        printf("请输入插入的位置和插入的值:");
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

    void del() // 删除函数
    {
        int pos;
        printf("请输入删除的位置:");
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

    void change() // 修改函数
    {
        int x, pos;
        printf("请输入改变的位置和改变后的值:");
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

    void show() // 展示函数
    {
        Lnode *l = this;
        while(l->next != nullptr)
        {
            l = l->next;
            printf("%d ", l->data);
        }
        puts("");
    }

    void find() // 查询函数
    {
        Lnode *l = this;
        printf("请输入要查找的数:");
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

    void manager(int k) // 操作管理器
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
    printf("请输入数据创建链表：");
    Lnode *l = new Lnode; // 必须先给指针分配内存空间，不然指针不能用，也就是说连下面的creat函数都调用不出来
    l->creat();
    puts("可输入的操作（0：退出， 1：插入， 2：删除， 3：改变, 4：展示, 5：查找, 6：追加, 7：查询长度）");
    while(1)
    {
        printf("请输入操作数:");
        int k;
        scanf("%d", &k);
        if(!k)
            return 0;
        l->manager(k);
    }
}