#include<bits/stdc++.h>

#define run(i, a, b) for(int i = a; i <= b; i ++)
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

FILE *p, *co; // �����ļ�ָ��
char s[1000];
char ii[1000], jj[1000], kk[1000], fff[10];

void check(FILE *p)
{
    if(p == NULL) //����Ƿ�����ļ�
    {
        printf("error!\n");
        printf("���������ַ��˳�\n");
        getchar(); // ���û����������ַ����˳�
        exit(1);
    }
}

void copy(FILE *p, FILE*co)
{
    char s;
    s = fgetc(p);
    while(s != EOF)
    {
        fputc(s, co);
        putchar(s);
        s = fgetc(p);
    }
}

void into(FILE *p, char *s)
{
    fprintf(p, "%s", s);
}

void trains(char *s, char *ss)
{
    int l = strlen(s);
    ss[0] = '(';
    int i = 0, j = 1;
    if(s[0] == '-')
    {
        ss[j ++] = '-';
        i ++;
    }
    while(i < l)
    {
        if(s[i] == 'g')
        {
            i ++;
            if(s[i] == '(')
            {
                ss[j ++] = '(';
                while(s[i] != ')')
                    ss[j ++] = s[i ++];
                if(s[i] == ')')
                    ss[j ++] = s[i ++];
            }
            else
            {
                ss[j ++] = '(';
                while(i < l && s[i] >= '0' && s[i] <= '9')
                    ss[j ++] = s[i ++];
                ss[j ++] = ')';
            }
            ss[j ++] = '^', ss[j ++] = '(';
            ss[j ++] = '1', ss[j ++] = '/', ss[j ++] = '2';
            ss[j ++] = ')';
        }
        if(i == l)
            break;
        ss[j ++] = s[i ++];
    }
    ss[j ++] = ')';
}

char ssr[100];
int main()
{
    p = fopen("E:\\����\\����.txt", "rt+"); // ���ļ�ָ�븳ֵ
    co = fopen("E:\\����\\����.txt", "at+");
    check(co); // ����Ƿ����p�ļ�

    copy(co, p); // ��p�ļ����Ƶ�co�ļ�

    /*run(i, 1, 10)
    {
        s[i] = 'a';
        into(co, s);
    }*/



    /*char id[100];
    printf("���������\n");
    while(1)
    {
        scanf("%s", id);
        if(id[0] == 'a')
            break;
        int ll = strlen(id);
        run(p, 0, ll - 1)
        fff[p] = id[p];
        fff[ll] = '.';
        run(p, ll + 1, ll + 4)
        fff[p] = ' ';
        ms(ii), ms(jj), ms(kk);
        fputc('\n', co);
        char i[1000], j[1000], k[1000];
        scanf("%s%s%s", i, j, k);
        trains(i, ii), trains(j, jj), trains(k, kk);
        ii[strlen(ii)] = 'i', jj[strlen(jj)] = 'j', kk[strlen(kk)] = 'k';
        ii[strlen(ii)] = '+', jj[strlen(jj)] = '+';
        into(co, fff), into(co, ii), into(co, jj), into(co, kk);
        printf("\n%s%s%s%s\n", fff, ii, jj, kk);
        printf("���������\n");
    }
    fclose(p);*/
}
