/*
���� F: 22-����-2-�޽�λ�ӷ�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
С�Ϻ�ϲ����a+b���������������ǽ�λ����������88+12=90,������100�� ���������С��һЩa+b����ʽ�����������������ʲô��
����
��һ����һ������K����ʾ�����ĸ����� ÿ������ռһ�У�Ϊ��������a,b��0��a,b��1e9��
���
ÿ�����һ�������Ľ��,��Ҫ���ǰ��0��
�������� Copy
3
1 2
5 6
55 55
������� Copy
3
1
0
*/

#include<stdio.h>

int newplus(int,int);

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        int a,b;
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",newplus(a,b));
        }
    }
    return 0;
}

int newplus(int a,int b)
{
    int x=a,y=b,t,sum=0,a3,b3,c3;
    if(x<y)
    {
        t=x;
        x=y;
        y=t;
    }
    for(int i=0; x!=0; i++)
    {
        a3=x%10;
        x/=10;
        b3=y%10;
        y/=10;
        c3=((a3+b3)%10)*pow(10,i);
        sum+=c3;
    }
    return sum;
}