#include<stdio.h>
#include<string.h>

int main()
{
    char a[10],b[10];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int len1=strlen(a);
        int len2=strlen(b);
        if(len1 >= len2)
        {
            for(int i=0; i<len2; i++)
            {
                a[len1-1-i]+=(b[len2-1-i]-48);//��Ҫ����-48 ������������������������������������������
            }
            int flag=0;
            for(int i=0; i<len1; i++)
            {
                if(a[i] > '9')
                {
                    a[i]-=10;
                }
                if(a[i] != '0')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%c",a[i]);
                }
                if(flag==0 && i==len1-1)//������˼ά�Ĳ����ܣ�
                {
                    printf("0");
                }
            }
            printf("\n");
        }
        else
        {
            for(int i=0; i<len1; i++)
            {
                b[len2-1-i]+=(a[len1-1-i]-48);
            }
            int flag=0;
            for(int i=0; i<len2; i++)
            {
                if(b[i] > '9')
                {
                    b[i]-=10;
                }
                if(b[i] != '0')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%c",b[i]);
                }
                if(flag==0 && i==len2-1)
                {
                    printf("0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

/*
���� AI: 21������-��λ��ӣ�10�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
С�Ϻ�ϲ����a+b�������������ǽ�λ����������88+12=90,������100��������ʦ����С��һЩa+b����ʽ�����������������ʲô��
����
����������ÿ��һ�����������ÿո�ֿ�����������a��b��0��a,b��109����
���


����ÿһ�������������Ӻ�Ľ����ע�ⲻҪ�����0������ǰ��0��ÿ�����ռһ�С�

�������� Copy
5 6
55 6
81 22
������� Copy
1
51
3
*/

/*
#include<stdio.h>
#include<string.h>

int main()
{
    char a[10],b[10];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int len1=strlen(a);
        int len2=strlen(b);
        if(len1 >= len2)
        {
            for(int i=0; i<len2; i++)
            {
                a[len1-1-i]+=(b[len2-1-i]-48);
            }
            int flag=0;
            for(int i=0; i<len1; i++)
            {
                if(a[i] > '9')
                {
                    a[i]-=10;
                }
                if(a[i] != '0')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%c",a[i]);
                }
                if(flag==0 && i==len1-1)
                {
                    printf("0");
                }
            }
            printf("\n");
        }
        else
        {
            for(int i=0; i<len1; i++)
            {
                b[len2-1-i]+=(a[len1-1-i]-48);
            }
            int flag=0;
            for(int i=0; i<len2; i++)
            {
                if(b[i] > '9')
                {
                    b[i]-=10;
                }
                if(b[i] != '0')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%c",b[i]);
                }
                if(flag==0 && i==len2-1)
                {
                    printf("0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
*/