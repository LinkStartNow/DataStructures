#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *p;
    p = fopen("D:\\University\\C&C++\\CodeBlocks\\233\\main.cpp", "rt");
    if(p == NULL)
    {
        printf("���ʴ���\n");
        printf("�밴��������˳�");
        exit(1);
    }
    char c;
    c = fgetc(p);
    while(c != EOF)
    {
        putchar(c);
        c = fgetc(p);
    }
    fclose(p);
}
