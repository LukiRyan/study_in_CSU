#include<stdio.h>//�����˲�Ҫһζ�ĸ���ճ�� + ƴдһ��Ҫ��ȷ��swich�Ǵ��

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        char str[n];
        scanf("%s",str);
        int left=0, right=0;
        for(int i=0; i<n; i++)
        {
            if(str[i] == 'L')
            {
                left++;
            }
            else if(str[i] == 'R')
            {
                right++;
            }
        }
        char now;
        if(left > right)
        {
            int all=left-right;
            switch(all%4)
            {
                case 0:now='N';break;
                case 1:now='W';break;
                case 2:now='S';break;
                case 3:now='E';break;
            }
        }
        else if(left < right)
        {
            int all=right-left;
            switch(all%4)
            {
                case 0:now='N';break;
                case 1:now='E';break;
                case 2:now='S';break;
                case 3:now='W';break;
            }
        }
        else
        {
            now='N';
        }
        printf("%c\n",now);
    }
    return 0;
}

/*
���� T: 21�����л���-����������20�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����

������֮����ТΪ��֮�ȣ�С�Ͼ���������ĩȥ����Ժ����־Ը�����������ȥ��һ���µľ���Ժ���ؼ�·����·�ˣ�ֻ�ǵó��ŵ�ʱ�����򱱷����м���ת������ת�����ɴΡ�Ϊ��ȷ���Լ���λ�ã�����Ҫ֪���Լ����������ĸ�����������������˵����������򱱷�������˳ʱ����ת�ķ�������Ϊ�������Ϸ���������

����

����������ÿ�����������������룬��һ�а���һ��������n��0<n��1000������ʾת����Ĵ������������ĵڶ��а���һ������Ϊn���ַ�����ֻ��L��R��ɣ�L��ʾ����ת��R��ʾ����ת��


���
����ÿһ�����������һ����ĸ������С���������ķ���N��ʾ����S��ʾ�ϣ�E��ʾ����W��ʾ����ÿ�����ռһ�С�

�������� Copy
1
L
1
R
3
LRR
������� Copy
W
E
E
*/