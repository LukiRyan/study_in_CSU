#include<stdio.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        if(t>=90 && t<=100)
        {
            printf("A\n");
        }
        else if(t>=80 && t<=89)
        {
            printf("B\n");
        }
        else if(t>=70 && t<=79)
        {
            printf("C\n");
        }
        else if(t>=60 && t<=69)
        {
            printf("D\n");
        }
        else if(t>=0 && t<=59)
        {
            printf("E\n");
        }
        else
        {
            printf("Score is error!\n");
        }
    }
    return 0;
}

/*
1500: �ɼ�ת��
[������ : admin]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
����һ���ٷ��Ƶĳɼ�t������ת���ɶ�Ӧ�ĵȼ�������ת���������£�
90~100ΪA;
80~89ΪB;
70~79ΪC;
60~69ΪD;
0~59ΪE;
����
���������ж��飬ÿ��ռһ�У���һ��������ɡ�

���
����ÿ���������ݣ����һ�С�����������ݲ���0~100��Χ�ڣ������һ�У���Score is error!����
�������� Copy
56
67
100
123
������� Copy
E
D
A
Score is error!
��Դ/����
*/