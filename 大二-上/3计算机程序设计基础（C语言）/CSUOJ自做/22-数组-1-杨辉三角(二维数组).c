/*
���� C: 22-����-1-�������
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
������ǣ����ص����������ϵ����ֶ�Ϊ1������λ���ϵ�����������һ������֮���ڵ���������֮�͡� 
����ͼ������һ��6����������
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1 
����
��������ÿ�������������ֻ����һ��������n��1��n��50������ʾ��Ҫ�����������ǵĲ�����
���
��Ӧ��ÿһ�����룬�����Ӧ������������ǣ�ÿһ�������֮����һ���ո������ÿһ��������Ǻ����һ�����С�
�������� Copy
2
3
������� Copy
1
1 1

1
1 1
1 2 1
*/

/*
#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long int a[51][51];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(j==0 || j==i)
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                printf("%d",a[i][j]);
                if(j != i)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
*/

/*���Ͻⷨ�иУ����Դ�ʹ�����int���ϣ���Ϊ���51̫��int�Ų���
#include<stdio.h>
double jie(double n);
int main()
{
	double n;
	while (scanf("%lf", &n) != EOF)
    {
		double i;
		double j;
		for (i = 1; i <= n; i++)
        {
			for (j = 0; j < i; j++)
            {
				if (i==1&&j==0)
                {
					printf("%d\n",1);
				}
				else if (i != 1 && j == 0)
                {
					printf("%d ",1);
				}
				else if (i != 1 && j == i - 1)
                {
					printf("%d\n",1);
				}
				else {
					printf("%.0f ", jie(i - 1) / (jie(j) * jie(i - 1 - j)));
				}
			}
		}
		printf("\n");
	}
	

}
double jie(double n) {
	if (n <= 1)
    {
		return 1;
	}
	else
    {
		return n * jie(n - 1);
	}
}
*/

//�ҵĸİ棺��ԭ������������ϣ���һ��Ҫ�ǵ�long long��%lld

#include<stdio.h>
 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long int a[51][51];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(j==0 || j==i)
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
                }
            }
        }
 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i+1; j++)
            {
                printf("%lld",a[i][j]);
                if(j != i)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}