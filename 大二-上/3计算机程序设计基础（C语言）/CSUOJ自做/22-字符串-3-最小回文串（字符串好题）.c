//OJ�ᳬʱ������ʱ���㹻ûʲô������
#include<stdio.h>
#include<string.h>

int isHuiWenChar(char str[], int len);

int main()
{
    char n[10010];
    while(scanf("%s",n)!=EOF)
    {
        int len=strlen(n);
        while(1)
        {
            int i=len-1;
            n[i]++;
            int i3=i;
            while(n[i3] == ':')//�ַ��������Լ�������λ
            {
                n[i3]='0';
                if(i3 == 0)//����λʱ����һλ
                {
                    len++;
                    for(int j=len-1; j>=1; j--)
                    {
                        n[j]=n[j-1];
                    }
                    n[i3]='1';
                }
                i3--;
                n[i3]++;
            }
            if(isHuiWenChar(n, len))
            {
                break;
            }
        }
        for(int i=0; i<len; i++)
        {
            printf("%c",n[i]);
        }
        printf("\n");
    }
    return 0;
}

//�ж��ǲ��ǻ������ַ���
int isHuiWenChar(char str[], int len)
{//(������,���鳤��)
    for(int i=0; i<len/2; i++)
    {
        if(str[i] != str[len-1-i])
        {
            return 0;
        }
    }
    return 1;
}

/*
#include<stdio.h>
#include<string.h>
  
char a[10010];
int main(){
    while(scanf("%s",a)!=EOF)
        {
        int len=strlen(a);
        int flag=0;
        for(int i=len/2-1;i>=0;i--)
        {
            if(a[i]>a[len-i-1])
                {
                  flag=1;
                  break;
                }
            else
            if(a[i]<a[len-i-1])
            {
                flag=0;
                break;
            }
        }
        if(!flag)
            {
            for(int i=(len-1)/2;i>=0;i--)
            {
                a[i]++;
                if(a[i]>'9')
                  a[i]='0';
                else break;
            }
            if(a[0]=='0')
            {
                a[0]='1';
                len++;
                a[len/2]='0';
            }
        }
        for(int i=0;i<len/2;i++)
            printf("%c",a[i]);
        for(int i=(len+1)/2-1;i>=0;i--)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
*/

/*
���� F: 22-�ַ���-3-��С���Ĵ�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 32 MB

��Ŀ����
�������Ǵ�ǰ����ʹӺ���ǰ�õ���������ͬ�ġ�С�Ͻӵ���ʦ���õ����񣬾��ǶԸ�����������n���ҵ���n�����С���Ǹ�������p������n��0 <n< 1010000��������һ���ܴ����������ֻ�����ַ������������ܰ�����дһ������ʵ����
����
����������ÿ����������һ��������n��0 <n< 1010000��������n������ǰ��0��
���
����ÿ�����룬�����n�����С���Ǹ�������p��ÿ�����ռһ�С�
�������� Copy
44
3
175
9
99
1331
19991
������� Copy
55
4
181
11
101
1441
20002
*/