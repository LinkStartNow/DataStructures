#include<bits/stdc++.h>
using namespace std;
class riqi
{
    int year,month,day;
public:
    riqi(int a,int b,int c);
    riqi(){;}
    void out();
};
void riqi::out()
{
    printf("生日==%d:%d:%d\n",year,month,day);
}
riqi::riqi(int a,int b,int c)
{
    year = a;
    month = b;
    day = c;
}
class People
{
    int number;
    string sex;
    riqi birthday;
    string id;
public:
    void into(int a,string b,int x,int y,int z,string d);
    void read();
    People();
    ~People();
};
void People::into(int a,string b,int y,int m,int d,string s)
{
    number = a;
    sex = b;
    riqi t(y,m,d);
    birthday = t;
    id = s;
}
void People::read()
{
    printf("编号==%d\n",number);
    cout << "性别==" << sex << endl;
    birthday.out();
    cout << "身份证号==" << id << endl;
}
People::People()
{
    printf("完成构造\n");
    printf("请输入数据:");
}
People::~People()
{
    printf("完成析构\n");
}
int main()
{
    People tom;
    int a;
    string b;
    int y,m,d;
    string s;
    cin >> a >> b >> y >> m >> d >> s;
    tom.into(a,b,y,m,d,s);
    tom.read();
}
