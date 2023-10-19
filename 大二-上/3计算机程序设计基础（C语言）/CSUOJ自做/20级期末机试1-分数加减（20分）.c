#include<stdio.h>
#include<math.h>

int gcd(int a,int b);

int main()
{
    int a,b,c,d;
    char fu;
    while(scanf("%d/%d%c%d/%d",&a,&b,&fu,&c,&d)!=EOF)
    {
        if(fu=='+')
        {
            int x=a*d+b*c;
            int y=b*d;
            int m=gcd(x,y);
            x/=m;
            y/=m;
            if(x==y)
            {
                printf("1\n");
            }
            else if(x>y)
            {
                int zh=x/y;
                x=x%y;
                if(x!=0)//��������
                {
                    printf("%d+%d/%d\n",zh,x,y);
                }
                else
                {
                    printf("%d\n",zh);
                }
            }
            else
            {
                printf("%d/%d\n",x,y);
            }
        }
        else
        {
            int x=a*d-b*c;
            int y=b*d;
            if(x==0)
            {
                printf("0\n");
            }
            else if(x>0)
            {
                int m=gcd(x,y);
                x/=m;
                y/=m;
                if(x==y)
                {
                    printf("1\n");
                }
                else if(x>y)
                {
                    int zh=x/y;
                    x=x%y;
                    if(x!=0)
                    {
                        printf("%d+%d/%d\n",zh,x,y);
                    }
                    else
                    {
                        printf("%d\n",zh);
                    }
                }
                else
                {
                    printf("%d/%d\n",x,y);
                }
            }
            else
            {
                x=abs(x);
                int m=gcd(x,y);
                x/=m;
                y/=m;
                if(x==y)
                {
                    printf("-1\n");
                }
                else if(x>y)
                {
                    int zh=x/y;
                    x=x%y;
                    if(x!=0)
                    {
                        printf("-%d+%d/%d\n",zh+1,y-x,y);
                    }
                    else
                    {
                        printf("-%d\n",zh+1);
                    }
                }
                else
                {
                    printf("-%d/%d\n",x,y);
                }
            }
        }
    }
    return 0;
}

//����շת����������Լ��
int gcd(int a,int b)
{
	int t;
	while(b!=0)
    {
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

/*
���� J: 20����ĩ����1-�����Ӽ���20�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
����CC����·����ļ������㣬��Ϊ�����������ر��Ҫ��������Ҫ�Է�������Ȼ���Ǽٷ���Ҫд��һ������+���������ʽ�����鷳���ǣ�������Ǹ��ļٷ���ʱ��Ҫ��д��һ��������+�������������ʽ�����ܰ������
����
����������ÿ��һ��������a/b-c/d��a/b+c/d����ʽ���루a,b,c,d����С��10000������������
���
����ÿһ����������������һ�������ע��Խ��Ҫ���������������ֱ�����������Ҫ�Է�����ʽ�����������������ֱ����e/f����ʽ���������ٷ�����5/3������1+2/3����ʽ����������-5/3������-2+1/3����ʽ�����
�������� Copy
1/1-2/3
1/2+2/3
1/2-8/2
������� Copy
1/3
1+1/6
-4+1/2
*/