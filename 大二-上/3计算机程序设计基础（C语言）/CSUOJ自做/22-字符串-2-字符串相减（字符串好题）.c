/*ԭ�𰸳�ʱ��
#include<stdio.h>
#include<string.h>

int main()
{
    char a[10000], b[10000];
    while(gets(a)!=NULL)
    {
        gets(b);
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=0; i<len1; i++)
        {
            for(int j=0; j<len2; )
            {
                if(a[i] == b[j])
                {
                    for(int k=i; k<len1; k++)
                    {
                        a[k]=a[k+1];
                    }
                    len1--;
                    j=0;
                }
                else
                {
                    j++;
                }
            }
        }
        for(int i=0; i<len1; i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char a[10000], b[10000];
    while(gets(a)!=NULL)
    {
        gets(b);
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=0; i<len1; i++)
        {
            for(int j=0; j<len2; j++)
            {
                if(a[i] == b[j])
                {
                    a[i]='{';//�ҶĶ�����������{����ַ�
                }
            }
        }
        for(int i=0; i<len1; i++)
        {
            if(a[i] != '{')
            {
                printf("%c",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

/*���ϴ�-����c[10000]����
#include<stdio.h>
#include<string.h>
 
int main()
{
    char s1[10000],s2[10000],s3[10000];
    while(gets(s1)!=NULL)
    {
        gets(s2);
        int n1=strlen(s1), n2=strlen(s2);
        int m=0;
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(s1[i] == s2[j])
                {
                    break;
                }
                if(j==n2-1)
                {
                    s3[m]=s1[i];
                    m++;
                }
            }
        }
        for(int l=0; l<=m-1; l++)//��Ϊǰ��m++����һ����Ե��
        {
            printf("%c",s3[l]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
���� B: 22-�ַ���-2-�ַ������
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
С�������������ַ���S1��S2����������һ���ַ���������S1-S2����S1��ȥ��������S2�е��ַ���ʣ�µ��ַ�����
����: S1="ABA", S2="A"���� S1-S2="B"��
����
��������������������ÿ������������������ַ���S1��S2���ַ������Ȳ�����104��ÿ���ַ��������ɿɼ�ASCII�ַ��Ϳո���ɡ�
���
����ÿ��������������S1-S2�Ľ����ÿ�����ռһ�С�
�������� Copy
ABA
A
A B&&1
&
������� Copy
B
A B1
��ʾ
������������ո���ַ���ʱ����ò���while(gets(a)!=NULL)�����������
*/