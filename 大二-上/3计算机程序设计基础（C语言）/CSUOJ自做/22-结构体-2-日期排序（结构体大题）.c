#include<stdio.h>//ȫ����������ʱ30����

struct csu
{
    int m;
    int d;
    int y;
}date[99],t;//����λ��ʱҪ�Ҹ��ݴ�ġ���ͬ��������t

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d/%d/%d",&date[i].m,&date[i].d,&date[i].y);
    }
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(date[i].y != date[j].y)
                {
                    if(date[i].y > date[j].y)
                    {
                        t=date[i];
                        date[i]=date[j];
                        date[j]=t;
                        //��break���ڴ˴������޷�����for
                    }
                    break;//�������������for���break���÷�����������swich���break
                }
                if(date[i].m != date[j].m)
                {
                    if(date[i].m > date[j].m)
                    {
                        t=date[i];
                        date[i]=date[j];
                        date[j]=t;
                    }
                    break;
                }
                if(date[i].d != date[j].d)
                {
                    if(date[i].d > date[j].d)
                    {
                        t=date[i];
                        date[i]=date[j];
                        date[j]=t;
                    }
                    //���һ��������break���п���
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(date[i].m<10)//����int�����ǰ���0����ʧ������
            {
                printf("0%d/%d/%d\n",date[i].m,date[i].d,date[i].y);
                continue;//���������break����ô����for������ȥ�ˣ�Ҫ��һ�δ�ӡһ�����ڣ�������continue
            }
            if(date[i].d<10)
            {
                printf("%d/0%d/%d\n",date[i].m,date[i].d,date[i].y);
                continue;
            }
            printf("%d/%d/%d\n",date[i].m,date[i].d,date[i].y);
        }
    return 0;
}

/*
���� F: 22-�ṹ��-2-��������
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
��ʦ����С��һЩ���ڣ����ڸ�ʽΪ��MM/DD/YYYY��Ҫ��С�ϱ�̽��䰴���ڴ�С���У����ܰ��������




����
������������ĵ�һ����һ������n��0<n<100)����ʾҪ�������ڵĸ�����
��������n�У�ÿ������һ�����ڣ���ʽΪMM/DD/YYYY��
���
��С����������������ڡ�
�������� Copy
3
02/21/2003
11/12/1999
10/22/2003
������� Copy
11/12/1999
02/21/2003
10/22/2003
��ʾ
Ҳ����������ʵ�֡�
*/