#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000];
    while(scanf("%s",a)!=EOF)
    {
        int min,c=0,s=0,u=0;
        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]=='C')
            {
                c++;
            }
            if(a[i]=='S')
            {
                s++;
            }
            if(a[i]=='U')
            {
                u++;
            }
        }
        min=c;//��ϰ����ֵ�ķ�����������������������1
        if(min>s){min=s;}
        if(min>u){min=u;}
        printf("%d\n",min);
    }
    return 0;
}

/*
���� F: 20�����л���-С˧��CSU��20�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
��С˧һ���ַ������ɴ�д��ĸ���ɣ�ÿ����ĸ����һ�Σ������������ɶ��ٸ�CSU��
����
����������ÿ��һ���ַ���
���
���һ�����֣����������CSU�ĸ���
�������� Copy
CSU
CCC
CCSSUU
������� Copy
1
0
2
*/