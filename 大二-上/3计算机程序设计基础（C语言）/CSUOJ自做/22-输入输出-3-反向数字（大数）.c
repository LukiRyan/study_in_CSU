/*
���� A: 22-�������-3-��������
[������ : 219127]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
������Τ���˿����֪��һ�����ֵķ������֣��ָ���һ������a���뽫��������λ�����ַ�ת�õ�һ������������ҲӦ���������ĳ�����ʽ�������Ǹ�����ԭ��Ϊ�㣬����ת��õ������������λ���ֲ�ӦΪ�㡣a��ת�õ��������ַ���λ���䡣
����
����������ÿ����������һ�У�����a��
���
��������
�������� Copy
235
-130
������� Copy
532
-31
*/

/*
#include<stdio.h>
#include<math.h>

int turn(int x);
int wei(int x);

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d\n",turn(a));
    }
    return 0;
}

int turn(int x)
{
    int w=wei(x);
    int m=x, n, sn, sum=0;
    for(int i=0; i<w; )
    {
        n=m%10;
        m=m/10;
        i++;
        sn=n*pow(10,w-i);
        sum+=sn;

    }
    return sum;
}

int wei(int x)
{
    int i;
    for(i=0;x!=0;i++)
    {
        x/=10;
    }
    return i;
}
*/

//����ⷨ��
#include<stdio.h>
#include<math.h>

int main()
{
    char s1[1000];
    while(gets(s1)!=NULL)
    {
        if(s1[0]!='-')
        {
            char s2[1000];
            int w=strlen(s1);
            for(int i=0; i<w; i++)
            {
                s2[i]=s1[w-1-i];
            }
            int flag=0;//��Ĭ�Ͽ�ͷΪ0
            for(int i=0; i<w; i++)
            {
                if(s2[i]!='0')//�����ͷ����0��ֱ����ͷ����0���ܸ�Ϊflag1
                {
                    flag=1;//��Ϊ��ͷ����0
                }
                if(flag==1)
                {
                    printf("%c",s2[i]);
                }
            }
            printf("\n");
        }
        else//(s1[0]=='-')
        {
            printf("%c",s1[0]);
            char s2[1000];
            int w=strlen(s1)-1;
            for(int i=1; i<w+1; i++)
            {
                s2[i]=s1[w-i+1];
            }
            int flag=0;//��Ĭ�Ͽ�ͷΪ0
            for(int i=1; i<w+1; i++)
            {
                if(s2[i]!='0')//�����ͷ����0��ֱ����ͷ����0���ܸ�Ϊflag1
                {
                    flag=1;//��Ϊ��ͷ����0
                }
                if(flag==1)
                {
                    printf("%c",s2[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}