/* ���� J: 22-ѭ��-1-��̨��
[������ : �ⲿ����]
ʱ������ : 1.000 sec  �ڴ����� : 128 MB

��Ŀ����
С���������ϴ�ѧ�з������˳�������Ŀ�ĵأ������˳������Ժ�С�Ͽ�����һ��������¥�ݡ�
¥����n��̨�ף�С��һ�ο���������1����������������n��������С������n��̨���ж�����������
����
��һ������һ������t��������t������:�� T��30��
��������t�У�����һ������n����ʾ¥����n��̨�ף� 1��n��30��
���

���һ����������ʾ������n��̨���ж�����������ÿ������������ռһ�С�

�������� Copy
3
1
3
5
������� Copy
1
4
16 */

// https://blog.csdn.net/qq_55624813/article/details/121316553?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-121316553-blog-80567180.pc_relevant_3mothn_strategy_recovery&spm=1001.2101.3001.4242.1&utm_relevant_index=3
#include<stdio.h>

int JumpSteps(int x);

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int i=0; i<t; i++)
        {
            int n;
            scanf("%d",&n);
            printf("%d\n",JumpSteps(n));
        }
    }
    return 0;
}

int JumpSteps(int x)
{
    int fx;
    if(x<2)
    {
        return x;
    }
    else
    {
        return 2*JumpSteps(x-1);
    }
}