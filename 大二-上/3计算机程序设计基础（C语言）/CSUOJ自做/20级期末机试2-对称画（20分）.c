#include<stdio.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int k=0; k<t; k++)
        {
            int n;
            scanf("%d",&n);
            //
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n-1-i; j++)
                {
                    printf(" ");
                }
                char ss='a';
                for(int j=0; j<i; j++)
                {
                    printf("%c",ss);
                    ss++;
                }
                printf("%c",ss);
                for(int j=0; j<i; j++)
                {
                    ss--;
                    printf("%c",ss);
                }
                printf("\n");
            }
            //
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<i; j++)
                {
                    printf(" ");
                }
                printf("a");
                for(int j=0; j<2*(n-i-1)-1; j++)
                {
                    printf(" ");
                }
                if(i != n-1)
                {
                    printf("a\n");
                }
            }
            printf("\n\n");
        }
    }
    return 0;
}

/*
���� M: 20����ĩ����2-�Գƻ���20�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
����CC����һ��ϲ���Գ����������ң������õ��Դ�ӡһЩ�Գ�ͼ�Ρ�������ֻϲ�����ҶԳƣ���ϲ�����¶Գơ���ϣ���������ӡһ��������ϲ�õĶԳƻ���
����
��һ����������T��1<T<9)���Ժ��ÿ��һ����������һ������n(1��n��26)����Գƻ��Ĵ�С�йء�
���
ÿ�����һ����Ӧ�ĶԳƻ�ͼ�Σ�ͼ������������û�пո�ÿ������֮�����һ�����С�
�������� Copy
2
2
3
������� Copy
 a 
aba
a a
 a 

  a  
 aba 
abcba
a   a
 a a 
  a  
*/