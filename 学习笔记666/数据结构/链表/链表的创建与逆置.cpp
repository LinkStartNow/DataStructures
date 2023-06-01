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
    head = p = (yyds*)malloc(sizeof(yyds)); // 分配给p一个地址，并且把这个地址同时给head，也就是说此时head和p是指向同一块内存的
    head->ssr = nullptr; // 这里改变的就是内存的内容了，因为head和p指向同一块内存所以此时p->ssr也是nullptr
    int t;
    while(cin >> t)
    {
        // 这里面就不用再使用head指针了，因为head要作为头指针的位置标记，不能轻易动
        // 而继续往下开辟新节点的保存指针就直接用替身使者p就行了，脏活累活全给他，功劳全是head的
        q = (yyds*)malloc(sizeof(yyds));
        q->v = t;
        q->ssr = p->ssr, p->ssr = q, p = q;
    }
    return head;
}

yyds* rev(yyds *now, yyds *pri)
{
    // 在不产生新链表的前提下逆置链表，只在原链表上动手脚
    if(now->ssr == nullptr) // 已经到尾节点了，递归终点标志
    {
        yyds *res = (yyds*)malloc(sizeof(yyds)); // 新的“head”指针
        now->ssr = pri, res->ssr = now;
        return res;
    }
    yyds *res =  rev(now->ssr, now); // 因为这一步要改变当前节点的ssr指针，所以不能直接return上一个的值，不然now的ssr就没更改了
    // 同样也不能先改变后return，因为改变后递归传值就难以确定了，没办法只能找个替罪羔羊记录下返回值
    now->ssr = pri;
    return res;
}

yyds* re2(yyds *head)
{
    // 头插式创建新表实现逆置，要多开一倍的内存
    yyds *p = head, *q, *res; // 为了保证原链表不被改变所以用p继承原头指针的值
    // res就是返回的新”head“
    // 下面的就是经典的头插式建链表法
    res = (yyds*)malloc(sizeof(yyds));
    res->ssr = nullptr;
    while(p->ssr != nullptr)
    {
        p = p->ssr; // p一步步向后取出原链表的值
        q = (yyds*)malloc(sizeof(yyds)); // q是新链表创建的新节点
        q->v = p->v; // 把值从原链表拷贝过来
        q->ssr = res->ssr; // 新节点指向之前的首元节点
        res->ssr = q;
    }
    return res;
}

void read(yyds *k) // 默认传入的是当前链表的头指针
{
    while(k->ssr != nullptr) // 这里改成for其实可以省括号省行什么的，无所谓啦哈哈哈
    {
        k = k->ssr; // 由while可知肯定有下一个节点，所以无脑跳就行，刚开始传入的头结点压根没有数据所以直接跳过也不会漏值
        printf("%d ", k->v);
    }
    puts("");
}

int main()
{
    yyds* head = creat(); // 创建链表
    read(head); // 顺序输出链表
    yyds *re = re2(head);
    free(head); // 释放head指向的内存，本质是向系统汇报这块内存已经不用了，可以分配给下一个需要的人，但是仅限于汇报，并不会把内存给初始化，内部的值依旧是在的
    // head也依然指向原先那个地址，在下一次涉及分配空间前这块内存的值都是已知且未改变的（神不神奇捏）(这个是假滴，不要信啊，cb的离谱之处)
    head = rev(head->ssr, nullptr); // 这里传入的第一个参数就是链表的第一个有意义的节点的指针而不是头指针
    // 如同上面说的head指向的内存空间依旧没变，其内存中存的值也没变，于是可以直接这么用，当然free后又有新的内存操作另当别论
    read(re);
}