#include<stdio.h>
#include<string.h>

int read_line(char str[], int n);

int main()
{
    char s[1000];
    int N;
    scanf("%d",&N);
    getchar();//���ջس�!�����ؼ�֮��!�����get��������������������Ǹ��س�
    for(int i=0; i<N; i++)
    {
        read_line(s,1000);//����getsҲ��
        printf("%s\n\n",s);
    }
    while(scanf("%s",s)!=EOF)//scanf�Դ������ո����µĹ���
    {
        printf("%s\n\n",s);
    }
    return 0;
}
//����ַ����ַ�������ȫ���gets()��(���ַ��������֣����ַ�������������С)
int read_line(char str[], int n)
{
    int ch,i=0;
    while((ch=getchar())!='\n')
    {//�ڶ��뻻�з�ʱ������ֹ�������ǿո�
        if(i < n)
        {
            str[i++]=ch;
        }
    }
    str[i]='\0';//���ַ�
    return i;
}

/*
1516: �ַ����������������
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 64 MB

��Ŀ����
�ַ����������������
����
��һ����һ��������N�����Ϊ100��֮���Ƕ����ַ�������������N���� ÿһ���ַ������ܺ��пո��ַ���������1000��
���
�Ƚ������е�ǰN���ַ��������ܺ��пո�ԭ��������ٽ����µ��ַ����������пո��Կո��س��ָ����ΰ��������ÿ�����֮�����һ�����С�
�������� Copy
2
www.njupt.edu.cn NUPT
A C M
N U P Ter
������� Copy
www.njupt.edu.cn NUPT

A C M

N

U

P

Ter

��Դ/����
�ַ��� 
*/