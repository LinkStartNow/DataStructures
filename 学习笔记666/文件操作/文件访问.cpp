#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *p;
    p = fopen("D:\\University\\C&C++\\CodeBlocks\\233\\main.cpp", "rt");
    if(p == NULL)
    {
        printf("访问错误\n");
        printf("请按下任意键退出");
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
