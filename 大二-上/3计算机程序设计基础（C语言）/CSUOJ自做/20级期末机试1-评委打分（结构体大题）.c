#include<stdio.h>

void quickSort(int *p, int left, int right);

struct inf
{
    char a[3];
    float avg;
}singer[999],t;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x[5];
        for(int i=0; i<n; i++)
        {
            scanf(" %c%c%c %d %d %d %d %d",
            &singer[i].a[0],&singer[i].a[1],&singer[i].a[2],&x[0],&x[1],&x[2],&x[3],&x[4]);
            quickSort(x,0,4);
            singer[i].avg=(x[1]+x[2]+x[3])/3.0;//Ϊʲô/3�Ͳ��ܳ�С���ˣ�
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n+1; j++)
            {
                //ע�����ĳЩѡ�ֵ�ƽ���ֳɼ���ͬ����������ţ���С��������
                if(singer[i].avg == singer[j].avg && (singer[i].a[0]*100+singer[i].a[1]*10+singer[i].a[2]) > (singer[j].a[0]*100+singer[j].a[1]*10+singer[j].a[2]))
                {
                    t=singer[j];
                    singer[j]=singer[i];
                    singer[i]=t;
                }
                if(singer[i].avg < singer[j].avg)
                {
                    t=singer[j];
                    singer[j]=singer[i];
                    singer[i]=t;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            printf("%c%c%c %5.2f\n",singer[i].a[0],singer[i].a[1],singer[i].a[2],singer[i].avg);
        }
    }
    return 0;
}

//���������㷨�����д�С�����ţ�(������-��Ҫע�����������Ƿ�Ҳ��int, �����һ��Ԫ�ص��±�, �������һ��Ԫ�ص��±�)
void quickSort(int *p, int left, int right)
{//(������-��Ҫע�����������Ƿ�Ҳ��int, �����һ��Ԫ�ص��±�, �������һ��Ԫ�ص��±�)
    if (left >= right)
        return;
    int pivot = p[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && p[j] >= pivot)
            j--;
        p[i] = p[j];
        while (i < j && p[i] < pivot)
            i++;
        p[j] = p[i];
    }
    p[i] = pivot;
    quickSort(p, left, i-1);
    quickSort(p, i+1, right);
}

/*
���� K: 20����ĩ����1-��ί��֣�10�֣�
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
����CC��������֯���ϴ�ѧ��ѧ���質������׼��������λ��ί���ݲ���ѡ�ֵı��ִ�֡�ѡ�ֵ÷ֹ���ȥ��һ����߷ֺ�һ����ͷ֣�Ȼ�����ƽ���÷֡�����Ҫ���һ�������ܸ���ÿλѡ�ֵ�ƽ���ִӸߵ��ͽ����������ܰ������
����
����������ÿ����������ĵ�һ��n����ʾ��n������ѡ�֣�n<1000��
�����n�У�ÿ�а�������ѡ�ֵı�ţ���������ɵĳ���Ϊ3���ַ���������5λ��ί���ķ��������ͣ����м��ɿո�ֿ���
���
����ѡ�ֵ�ƽ���֣��Ӹߵ��͵�˳���������ÿ��ѡ�ֵı�ź�ƽ���֣��������룬������λС������ע�����ĳЩѡ�ֵ�ƽ���ֳɼ���ͬ����������ţ���С��������
�������� Copy
5
001 98 95 82 85 90
002 76 87 90 90 88
003 90 92 97 95 93
004 97 88 86 90 92
010 99 98 97 96 96
������� Copy
010 97.00
003 93.33
001 90.00
004 90.00
002 88.33
*/