// �ҵ�ԭ�𰸣��������
// Ҫ�����ϸ�����С���ݵ���ʾ!�����ǶԵ�
#include<stdio.h>

int this(int x);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",this(n));
    }
    return 0;
}

int this(int x)
{
    int y;
    if(x>=41)
    {
        y=0;
    }
    else
    {
        y=1;
        for(int i=x; i>=1; i--)
        {
            y*=i;
            y%=2009;
        }
    }
    return y;
}

/*
https://blog.csdn.net/hjd_love_zzt/article/details/43413373?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-43413373-blog-127467866.pc_relevant_landingrelevant&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-43413373-blog-127467866.pc_relevant_landingrelevant&utm_relevant_index=1

���� I: 22-ѭ��-2-����n��
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
Alice��Bob���ڸ�ʲô��
Bob�����ڼ���n�Ľ׳�����2009��Ľ������s=n!%2009
Alice��n�ж�󰡣�
Bob��0��n��1000000000  
Alice������˰�
Bob�����ģ��һ�Ӧ��������������ʵģ���(axb)%c�ȼ���((a%c)x(b%c))%c������n���Ҳ��109 
����
��������������һ������n(0 ��n��109)
���
���һ��������ʾ�������Ľ׳�����2009��Ľ����
�������� Copy
4
������� Copy
24
��ʾ
0! = 1, n! =n*(n-1)!
*/