#include <bits/stdc++.h>

#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)

using namespace std;

const int N = 100;

int fi[N], tot;

int clone[N];

void init()
{
    run(i, 1, tot) clone[i] = fi[i];
}

void mao() // 冒泡排序
{
    init();
    int mov, com;
    mov = com = 0;
    run(i, 1, tot - 1)
    run(j, 1, tot - i)
    {
        com ++;
        if(clone[j] > clone[j + 1]) swap(clone[j], clone[j + 1]), mov ++;
    }
    printf("冒泡排序比较了%d次, 移动了%d次\n", com, mov);
}

void into() // 插入排序
{
    init();
    int mov, com;
    mov = com = 0;
    run(i, 2, tot)
    run(j, 1, i - 1)
    {
        com ++;
        if(clone[j] > clone[i])
        {
            int t = clone[i];
            rep(k, i, j + 1) clone[k] = clone[k - 1], mov ++;
            clone[j] = t;
            mov ++;
            break;
        }
    }
    printf("插入排序比较了%d次, 移动了%d次\n", com, mov);
}

void choose() // 选择排序
{
    init();
    int mov, com;
    mov = com = 0;
    run(i, 1, tot - 1)
    {
        int k = i;
        run(j, i + 1, tot)
        {
            com ++;
            if(clone[k] > clone[j]) k = j;
        }
        swap(clone[k], clone[i]);
        mov ++;
    }
    printf("选择排序比较了%d次, 移动了%d次\n", com, mov);
}

void fast_sort(int &mov, int &com, int l, int r) // 快速排序
{
    if(l >= r) return;
    int k = clone[l + r >> 1];
//    int k = clone[l] + clone[r] >> 1;
    int p = l - 1, q = r + 1;
    while(p <= q)
    {
        while(clone[++ p] < k && ++ com); while(clone[-- q] > k && ++ com);
        if(p <= q) swap(clone[p], clone[q]), mov ++;
    }
    fast_sort(mov, com, l, q), fast_sort(mov, com, p, r);
}

void fast() // 调用快速排序
{
    init();
    int mov, com;
    mov = com = 0;
    fast_sort(mov, com, 1, tot);
    printf("快速排序比较了%d次, 移动了%d次\n", com, mov);
}

void show()
{
    run(i, 1, tot) cout << clone[i] << ' ';
    cout << endl;
}

int main()
{
    FILE* f = fopen("e:/b.txt", "rt");
    if(f) while(!feof(f)) fscanf(f, "%d", &fi[++ tot]);
    else cout << "error";
    tot --;
//    while(cin >> fi[++ tot]); tot --;
    mao();
    into();
    choose();
    fast();
    show();
}
